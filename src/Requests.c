


#include "../inc/appRes.h"
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Variables>                                                |
 --------------------------------------------------------------------------------------------------------
 */

SystemConfig_t *gpSystemConig;

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Functions Definitions>                                    |
 --------------------------------------------------------------------------------------------------------
 */






/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Functions Implements>                                    |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < udateRoomRequest >                                                 |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void udateRoomRequest                                                         |
 | < @Description       : Request the State to update room state                                        |      
 | < @Param State       : Current Switch State (Call , Cenecl , Emg )                                   |
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t updateRoomRequest(uint8_t State) {
    uint8_t FrameState;
    uint8_t buf[4];
    buf[0] = SW_UPDATE_ROOM_REQ;
    buf[1] = SystemIp();
    buf[2] = gpSystemConig->Rip;
    buf[3] = State;
    FrameState = putDataCh0(buf, 4, 0xFF, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }
    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < PowerOnRequest >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void PowerOnRequest                                                           |
 | < @Description       : request data from save unit                                                   |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t PowerOnRequest() {
    uint8_t FrameState;
    uint8_t buf[2];
    buf[0] = SW_POWER_ON_REQ;
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < SaveOnRequest >                                                    |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void SaveOnRequest                                                            |
 | < @Description       : save state into save unit                                                     |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SaveOnRequest(uint8_t State) {
    uint8_t FrameState;
    uint8_t buf[7];
    buf[0] = SW_SAVE_STATE_REQ;
    buf[1] = SystemIp();
    buf[2] = State;
    uint16_t swId = getSwId();
    uint16_t RoomId = getRoomId();
    copyBuff(buf + 3, &swId, 2);
    copyBuff(buf + 5, &RoomId, 2);
    FrameState = putDataCh0(buf, 7, 0, RequestFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < External Functions >                                    |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < ReadSystemConfig >                                                 |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void ReadSystemConfig                                                       |
 | < @Description         : Read Current call Point System Config                                       |      
 | < @Param systemConig   : Pointer of system Config                                                    |
 | < @return              : void                                                                        |
 --------------------------------------------------------------------------------------------------------
 */
void ReadSystemConfig(SystemConfig_t *systemConig) {
    gpSystemConig = systemConig;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < GetIpRequest >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void GetIpRequest                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t GetIpRequest() {
    uint8_t FrameState;
    uint8_t buf[2];
    buf[0] = SET_IP_RES;
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0, ResponseFrame);
    if (FrameState == DATA_FRAME_SUCESS) {

        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {

        return (1);
    }
    return (0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < ResForConfig >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void ResForConfig                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t ResForConfig() {
    uint8_t FrameState;
    uint8_t buf[2];
    buf[0] = SW_CONFIG_RES;
    buf[1] = SystemIp();
    FrameState = putDataCh0(buf, 2, 0, ResponseFrame);
    if (FrameState == DATA_FRAME_SUCESS) {
        return (1);
    }

    if (FrameState == DATA_FRAME_ERROR) {
        return (1);
    }
    return (0);
}
