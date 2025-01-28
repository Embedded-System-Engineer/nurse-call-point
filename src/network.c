
#include "../inc/appRes.h"
/*
 *<@var System Data
 */
static callPoint_t gsCallPoint;
/*
 * <@var system network client state
 */
static uint8_t gu8NetworkClientState;

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkClientSystem>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkClientSystem                                                    |
 | < @Description         : any Response can be handel from this function                               |   
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkClientSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkHostSystem>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkHostSystem                                                      |
 | < @Description         : any request can be handel from this function                                |
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkHostSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkInit() {
    gu8NetworkClientState = 0;
    OnClientFrameCh0(NetworkClientSystem);
    OnHostFrameCh0(NetworkHostSystem);
    setBuff(&gsCallPoint, 0x00, sizeof (callPoint_t));
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkClientSystem>                                                |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkClientSystem                                                    |
 | < @Description         : any Response can be handel from this function                               |   
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkClientSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data) {
    if (Data[0] == SW_POWER_ON_RES) {
        if (Data[1] == SystemIp()) {
            stopPowerOnRequest();
            OnSaveConfiguration(Data + 2);
            copyBuff(&gsCallPoint, (Data + 2 + sizeof (SystemConfig_t)), sizeof (callPoint_t));
            /*Active send data to Displays and rooms*/
            RegisterOnUserSystem(gsCallPoint.State);
            gu8NetworkClientState = 1;

        }
        return (1);
    }

    if (Data[0] == SW_SAVE_STATE_RES) {

        if (Data[1] == SystemIp()) {
            stopPowerOnRequest();
            gsCallPoint.State = Data[2];
            RegisterOnUserSystem(gsCallPoint.State);
            if (SA == csmaGetStationAddress()) {
                gu8NetworkClientState = 1;
            }
        }
        return (1);
    }

    return (1);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkHostSystem>                                                  |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkHostSystem                                                      |
 | < @Description         : any request can be handel from this function                                |
 | < @Param DA            : received address from other station                                         |
 | < @PAram len           : Data received Length                                                        |
 | < @Param Data          : Data received                                                               |
 | < @return              : 0 is run , 1 is done                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t NetworkHostSystem(uint8_t SA, uint8_t DA, uint8_t len, uint8_t *Data) {

    if (Data[0] == SW_START_CONFIG_REQ && SA == csmaGetMaxAddress()) {
        /*send Response For Ip*/
        if (Data[1] == 0) {
            gu8NetworkClientState = 2;
            RegisterOnUserSystem(SYSTEM_START_ADDRESS_EVENT);
        } else {
            RegisterOnUserSystem(gsCallPoint.State);
        }
        return (1);
    }


    /*switch assign Ip */

    if (Data[0] == SW_CONFIG_REQ) {
        /*save data copy*/
        if (Data[1] == SystemIp()) {
            stopPowerOnRequest();
            OnSaveConfiguration(Data + 2);
            copyBuff(&gsCallPoint, (Data + 2 + sizeof (SystemConfig_t)), sizeof (callPoint_t));
            /*Active send data to Displays and rooms*/
            gu8NetworkClientState = 3;
            RegisterOnUserSystem(gsCallPoint.State);
        }
        return (1);
    }
    if (Data[0] == SET_IP_REQ && csmaGetStationAddress() == SA) {
        if (Data[1] != SystemIp()) {
            OnSaveIp(Data[1]);
            PowerOnInit();
        }
        RegisterOnUserSystem(gsCallPoint.State);
        return (1);
    }




    if (Data[0] == SW_ACCEPT_STATE_REQ) {

        if (Data[1] != SystemIp()) {
            return(1);
        }

        if (gsCallPoint.State == SYSTEM_CANCEL_EVENT) {
            return (1);
        }
        if (getAcceptState()) {
            gu8NetworkClientState = 1;
            gsCallPoint.State = SYSTEM_CANCEL_EVENT;
            RegisterOnUserSystem(SYSTEM_CANCEL_EVENT);
        } else {
            //save same state
            RegisterOnUserSystem(SYSTEM_ACCEPT_EVENT);
        }

        return (1);
    }

    if (Data[0] == SW_POWERON_ROOM_REQ) {
        if (Data[1] != getRoomIp()) {
            return (1);
        }
        gu8NetworkClientState = 1;
    }

    return (1);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <NetworkCallBack>                                                    |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void NetworkCallBack                                                        |
 | < @Description         : run network task                                                            |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void NetworkCallBack() {
    switch (gu8NetworkClientState) {
        case 0:
            break;
        case 1:
            if (!getRoomIp()) {
                gu8NetworkClientState = 4;
                return;
            }
            if (updateRoomRequest(gsCallPoint.State)) {
                gu8NetworkClientState = 4;
            }
            break;
        case 2:
            if (GetIpRequest()) {
                gu8NetworkClientState = 0;
            }
            break;
        case 3:
            if (ResForConfig()) {
                gu8NetworkClientState = 1;
            }
            break;
        case 4:
            if (sendFreeFrame()) {
                gu8NetworkClientState = 0;
            }
            break;
        default:
            gu8NetworkClientState = 0;
            break;
    }
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemIsData>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void SystemIsData                                                           |
 | < @Description         : system have Data Or Not                                                     |   
 | < @return              : 0 is not have a Data and  1 system have a Data                              |          
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SystemIsData() {
    if (gsCallPoint.State) {
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemIsData>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void SystemIsData                                                           |
 | < @Description         : system have Data Or Not                                                     |   
 | < @return              : 0 is not have a Data and  1 system have a Data                              |          
 --------------------------------------------------------------------------------------------------------
 */
uint16_t getSwId() {
    return gsCallPoint.userSwID;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <SystemIsData>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void SystemIsData                                                           |
 | < @Description         : system have Data Or Not                                                     |   
 | < @return              : 0 is not have a Data and  1 system have a Data                              |          
 --------------------------------------------------------------------------------------------------------
 */
uint16_t getRoomId() {
    return gsCallPoint.userRID;
}