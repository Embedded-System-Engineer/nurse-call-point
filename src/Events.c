

#include "../inc/appRes.h"

ButtonCreateEvent(key1, BUTTON_KEY_06, 0, key2);
ButtonCreateEvent(key2, BUTTON_KEY_05, 1, key3);
ButtonCreateEvent(key3, BUTTON_KEY_03, 2, NO_BUTTONCODE);

static uint8_t gu8SwEventsCallBack;
/*
 
 */
static uint8_t gu8EventState;
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onCall >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onEvent                                                                  |
 | < @Description       : Press a Call onEvent                                                          |      
 | < @return            : 0 is run , 1 is done                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onEvent(stButton_t *key, uint8_t Value);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onCall >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onCall                                                                   |
 | < @Description       : Press a Call State                                                            |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onSwitch0(stButton_t *key);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onEMG >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onEMG                                                                   |
 | < @Description       : Press a Emg State                                                            |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onSwitch1(stButton_t *key);
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onCancel >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onCancel                                                                   |
 | < @Description       : Press a Cencel State                                                            |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onSwitch2(stButton_t *key);

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < EventsInit >                                                       |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void EventsInit                                                               |
 | < @Description       : Init Variables and Key Registeration                                         |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
void EventsInit() {
    gu8SwEventsCallBack = 0;
    buttonAssignCosntEvents(&key1);
    buttonRegisterEvent(onSwitch0, 0);
    buttonRegisterEvent(onSwitch1, 1);
    buttonRegisterEvent(onSwitch2, 2);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onCall >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onCall                                                                   |
 | < @Description       : Press a Call State                                                            |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onSwitch0(stButton_t *key) {
    return onEvent(key, 0);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onEMG >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onEMG                                                                   |
 | < @Description       : Press a Emg State                                                            |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onSwitch1(stButton_t *key) {
    return onEvent(key, 1);
}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onCancel >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onCancel                                                                   |
 | < @Description       : Press a Cencel State                                                            |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onSwitch2(stButton_t *key) {
    return onEvent(key, 2);
}
/*
 --------------------------------------------------------------------------------------------------------
 |                                 < SwitchEventCallBack >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void SwitchEventCallBack                                                                   |
 | < @Description       : send Frame to server unit                                                           |      
 | < @return            : void                                                                          |
 --------------------------------------------------------------------------------------------------------
 */
void SwitchEventCallBack() {
    if (!gu8SwEventsCallBack) {
        return;
    }
    if (SaveOnRequest(gu8EventState)) {
        gu8SwEventsCallBack = 0;
    }


}

/*
 --------------------------------------------------------------------------------------------------------
 |                                 < onCall >                                                           |
 --------------------------------------------------------------------------------------------------------
 | < @Function          : void onEvent                                                                  |
 | < @Description       : Press a Call onEvent                                                          |      
 | < @return            : 0 is run , 1 is done                                                          |
 --------------------------------------------------------------------------------------------------------
 */
static uint8_t onEvent(stButton_t *key, uint8_t Value) {
    if (!SystemIsSerial()) {
        return (1);
    }
    if (!SystemIsIp()) {
        return (1);
    }

    if (!SystemIsData()) {
        return (1);
    }



    switch (getSwitchType(Value)) {
        case SYSTEM_SWITCH_TYPE_DISABLED:
            break;
        case SYSTEM_SWITCH_TYPE_CALL:
            if (key->State == BUTTON_KEY_PRESS) {
                gu8SwEventsCallBack = 1;
                gu8EventState = (SYSTEM_CALL_EVENT);
            }
            break;
        case SYSTEM_SWITCH_TYPE_CENECEL:
            if (key->State == BUTTON_KEY_PRESS) {
                gu8SwEventsCallBack = 1;
                gu8EventState = (SYSTEM_CANCEL_EVENT);
            }
            break;
        case SYSTEM_SWITCH_TYPE_ASSISSET:
            if (key->State == BUTTON_KEY_PRESS) {
                gu8SwEventsCallBack = 1;
                gu8EventState = (SYSTEM_ASSISSET_EVENT);
            }
            break;
        case SYSTEM_SWITCH_TYPE_CALL_ASSIESSET:
            if (key->State == BUTTON_LONG_TAP) {
                gu8SwEventsCallBack = 1;
                gu8EventState = (SYSTEM_ASSISSET_EVENT);
                return (1);
            }

            if (key->State == BUTTON_KEY_PRESS) {
                gu8SwEventsCallBack = 1;
                gu8EventState = (SYSTEM_CALL_EVENT);
            }
            break;
        case SYSTEM_SWITCH_TYPE_EMG:
            if (key->State == BUTTON_KEY_PRESS) {
                gu8SwEventsCallBack = 1;
                gu8EventState = (SYSTEM_EMG_EVENT);
            }
            break;
        default:
            break;

    }
    return (1);
}