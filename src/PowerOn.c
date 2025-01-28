#include "../inc/appRes.h"
/*
 <@var Power on state 
 */
static uint8_t gu8PowerOnState;
/*
 *<@var Power on Time out to send Frame 
 */
static stTimer_TimeOut_t gstPowerOnTimeOut;

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnInit>                                                        |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnInit                                                            |
 | < @Description         : Init all data into this file                                                |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnInit() {
    gu8PowerOnState = 0;
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 <PowerOnCallBack>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void PowerOnCallBack                                                        |
 | < @Description         : Power on task                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void PowerOnCallBack() {
    if (!SystemIsSerial()) {
        gu8PowerOnState = 0;
        return;
    }

    if (!SystemIsIp()) {
        gu8PowerOnState = 0;
        return;
    }

    if (csmaGetStationAddress() == 0) {
        gu8PowerOnState = 0;
        return;
    }

    switch (gu8PowerOnState) {
        case 0:
            if (PowerOnRequest()) {
                gu8PowerOnState = 1;
                sysSetPeriodMS(&gstPowerOnTimeOut, 200);
            }
            break;
        case 1:
            if (sysIsTimeoutMs(&gstPowerOnTimeOut) == 0) {
                gu8PowerOnState = 0;
            }
            break;
        case 2:
            break;
        default:
            gu8PowerOnState = 0;
            break;
    }
}
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <stopPowerOnRequest>                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void stopPowerOnRequest                                                        |
 | < @Description         : stop Request Power On after Master Response                                                               |   
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void stopPowerOnRequest() {
    gu8PowerOnState = 2;
}