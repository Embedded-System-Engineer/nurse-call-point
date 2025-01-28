/* 
 * File:   Requests.h
 * Author: hassa
 *
 * Created on April 19, 2023, 12:46 PM
 */

#ifndef REQUESTS_H
#define	REQUESTS_H
#include "appRes.h"


/*
 --------------------------------------------------------------------------------------------------------
 |                                 < Internal Functions Implements>                                    |
 --------------------------------------------------------------------------------------------------------
 */

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < updateDisplaysRequest >                                            |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void updateDisplaysRequest                                                    |
 | < @Description       : Request user switch id and room switch id to all active displays in call point|                                                     |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t updateDisplaysRequest(callPoint_t *callpoint);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < updateDisplayRequest >                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void updateDisplayRequest                                                     |
 | < @Description       : Response for request data                                                     |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t updateDisplayRequest(uint8_t currenAddress, uint8_t DIP, callPoint_t *point);

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
uint8_t updateRoomRequest(uint8_t State);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < PowerOnRequest >                                                   |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void PowerOnRequest                                                           |
 | < @Description       : request data from save unit                                                   |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t PowerOnRequest();

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < SaveOnRequest >                                                    |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void SaveOnRequest                                                            |
 | < @Description       : save state into save unit                                                     |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t SaveOnRequest(uint8_t State);
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
void ReadSystemConfig(SystemConfig_t *systemConig);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < GetIpRequest >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void GetIpRequest                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t GetIpRequest();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < ResForConfig >                                                     |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void ResForConfig                                                             |
 | < @Description       : Response for Start Flash with select address                                  |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t ResForConfig();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < updateDisplaysRequest >                                            |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void updateDisplaysRequest                                                    |
 | < @Description       : Request user switch id and room switch id to all active displays in call point|                                                     |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t updateDisplaysRequestPowerOn(callPoint_t *callpoint);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < updateDisplayRequest >                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void updateDisplayRequest                                                     |
 | < @Description       : Response for request data                                                     |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
uint8_t updateDisplayRequestPowerOn(uint8_t DAddress, uint8_t DIP, callPoint_t *point);
#endif	/* REQUESTS_H */

