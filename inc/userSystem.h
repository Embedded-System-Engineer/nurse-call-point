/* 
 * File:   userSystem.h
 * Author: hassa
 *
 * Created on April 21, 2023, 1:42 AM
 */

#ifndef USERSYSTEM_H
#define	USERSYSTEM_H

#include "appRes.h"
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < RegisterOnUserSystem >                                             |
 --------------------------------------------------------------------------------------------------------
 | < @Function                  : void RegisterOnUserSystem                                             |
 | < @Description               : user indicator show                                                   |     
 | < @Param  UserIndicatorId    : system indicator hav a 6 Indicator                                    |
 |                               : 0 OnDefault System                                                   |
 |                               : 1 OnStart Configuration Set                                          |
 |                               : 2 On Call State                                                      |
 |                               : 3 On Emg State                                                       |
 |                               : 4 On Cencel State                                                    |
 *  |                            : 5 On Accept State                                                    |
 | < @return                     : void                                                                 |
 --------------------------------------------------------------------------------------------------------
 */
void RegisterOnUserSystem(uint8_t UserIndicatorId);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserInit>                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserInit                                                               |
 | < @Description         : Init all variable in this file                                              |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserInit();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserCallBack>                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserCallBack                                                           |
 | < @Description         : run in background                                                           |      
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserCallBack();
/*
 --------------------------------------------------------------------------------------------------------
 |                                 <UserSetAcceptValueRun>                                              |
 --------------------------------------------------------------------------------------------------------
 | < @Function            : void UserSetAcceptValueRun                                                  |
 | < @Description         : set accept state is run is emg or  Call                                     |   
 | < @Param state         : 1 is call and 2 is Emg else not run any case                                |
 | < @return              : void                                                                        |          
 --------------------------------------------------------------------------------------------------------
 */
void UserSetAcceptValueRun(uint8_t state);
#endif	/* USERSYSTEM_H */

