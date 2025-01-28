/* 
 * File:   memory.h
 * Author: hassa
 *
 * Created on April 19, 2023, 12:07 PM
 */

#ifndef MEMORY_H
#define	MEMORY_H
#include "appRes.h"

typedef union {
    uint8_t Options;

    struct {
        unsigned DisapledSystem : 1;
        unsigned buzzerState : 1;
        unsigned buzzerTimeFactor : 6;
    };
} CallPointOptions_t;

typedef struct callPoint_s {
    uint16_t userSwID;
    uint16_t userRID;
    uint8_t State;
} callPoint_t;

typedef struct SystemConfig_s {
    uint8_t Rip;
    uint8_t SwitchHwType[3];
    CallPointOptions_t Option;
} SystemConfig_t;

typedef struct System_s {
    SystemConfig_t Config;
    callPoint_t Data;
} System_t;
/*
 * < @macro APP_START : start of the application       
 */
#define  BOOT_START      asm("JMP 0x3E00")
#endif	/* MEMORY_H */

