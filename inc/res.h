/*
--------------------------------------------------------------------------------------------------
|                           < Module  Definition >                                               | 
--------------------------------------------------------------------------------------------------
| < FILE                     : res.h                                                             |                                  
| < Author                   : Hassan Elsaied                                                    |
| < Version                  : Mega2v241022                                                      |
| < Refences                 : no refence                                                        |
| < SRAM USAGE               : header file                                                       |
| < PROGRAM USAGE            : header file                                                       |                                      
| < Hardware Usage           : header file                                                       |
| < File Created             : 24-10-2022                                                        |
--------------------------------------------------------------------------------------------------
 */

#ifndef RES_H
#define	RES_H




#define  COMPILER_TYPE                       GCC

/*
 ---------------------------------------------------------------------------------------
 |                                <System MODULE>                                      | 
 ---------------------------------------------------------------------------------------
 | <macro F_CPU                  : F_CPU CLOCK  >look clock.h                          |                                        |
 | <macro @N_OF_US_REQUIRED      : each F_CPU has base number of micro                 |
 |                               : select one of number of micro seconds               |
 |                               : _number+us  > is defined and supported time         |  
 | <macro SRAM_USAGE             : 14 Byte                                             |
 | <macro PROGRAM_USAGE          : 694 byte (347 Instruction)                          |
 ---------------------------------------------------------------------------------------
 */
#define     F_CPU                          XTAL_11059200
#define     N_OF_US_REQUIRED               (_1250us)
/*
 ---------------------------------------------------------------------------------------
 |                                <GPIO MODULE>                                        | 
 ---------------------------------------------------------------------------------------
 | < macro GPIO2_PREFER_SPEED     : gpio speed acess                                   |
 |                                : 0 the  function called used                        |
 |                                : 1 the  function not called and used inline         |
 | < macro GPIO2_IOREGS_ABOVEFF   : enable or disable access gpio with in atomic block |
 |                                : 0 gpio acess without atomic                        |
 |                                : 1 gpio acess with in atomic                        |
 |                                : @note : atomic means disable any extrnal interrupt |
 |                                :       : to not effect in gpio pins at write or...  |
 ---------------------------------------------------------------------------------------
 */
#define     GPIO2_PREFER_SPEED               (1)
#define     GPIO2_IOREGS_ABOVEFF             (0)







/*
 ------------------------------------------------------------------------------------------------------------
 |                             < USART_MODULE  >                                                            |                                       
 |-----------------------------------------------------------------------------------------------------------
 | < USART_MODULE               : 0 module is not active                                                    |
 |                              : 1 module is active                                                        |
 ------------------------------------------------------------------------------------------------------------
 | < USARTx_ENABLED            : to enable USART please define USART0_ENABLED                               |
 |                             : or defined USART0_ENABLED or defined both                                  |
 |                             : version supported a 4 USART (0,1,2,3)                                      |
 |-----------------------------------------------------------------------------------------------------------
 | < speed (Mbps)                                       |  Bit duration  |  byte rate      | byte duration  |
 |------------------------------------------------------|----------------|-----------------|----------------|  
 | < UARTx_BUADRATE           @StandBaudRate_1200       |    833.33 us   |  00120 byte/s   |  8333.33 us    |                
 | < x is 0 to 3              @StandBaudRate_2400       |    416.66 us   |  00240 byte/s   |  4166.66 us    |                                   
 |                            @StandBaudRate_4800       |    208.33 us   |  00480 byte/s   |  2083.33 us    |                     
 |                            @StandBaudRate_9600       |    104.16 us   |  00960 byte/s   |  1041.66 us    |                            
 |                            @StandBaudRate_19200      |    052.08 us   |  01920 byte/s   |  0520.83 us    |                                      
 |                            @StandBaudRate_38400      |    026.04 us   |  03840 byte/s   |  0260.41 us    |                        
 |                            @StandBaudRate_57600      |    017.36 us   |  05760 byte/s   |  0173.61 us    |
 |                            @StandBaudRate_76800      |    013.68 us   |  07680 byte/s   |  0130.20 us    |
 |                            @StandBaudRate_115200     |    008.68 us   |  11520 byte/s   |  0086.00 us    |                                                                  
 ------------------------------------------------------------------------------------------------------------
 | < note : @UARTx_BUADRATE      : x  0 to 3 if defined more UART please defined the baud rate every uart   |
 |        : @UART_XYZ            : not supported in current version the usart is work only 8nit data and    |
 |                               : and  no parity and 1-stop bit in new version can support this  and       | 
 |                               : @X is a number of bits and @Y type the parity and @Z is n-stop bits      | 
 | < SRAM USAGE                  : no-used                                                                  |
 | < PROGRAM USAGE               : 40 Byte with enable Uart 0, Uart 1 (20 Instruction)                      |                                                |
 ------------------------------------------------------------------------------------------------------------
 */
#define  USART_MODULE                                                           (1)
#if      USART_MODULE
#define  USART0_ENABLED                                                          
#define  UART0_BUADRATE                                                       StandBaudRate_19200
#endif

/*
 --------------------------------------------------------------------------------------
 |                               < CSMA_MODULE  >                                     |                                       
 |-------------------------------------------------------------------------------------
 |< @CSMA_MODULE                 : 0 module is not active                             |
 |                               : 1 module is active                                 |
 |< @STATION_BLOCK_TIME          : Station Blocking Time(ms)after send Block address  |    
 |< @COM_PLAYLOAD_SIZE           : number of Byte Data send                           |                                                  
 --------------------------------------------------------------------------------------
 */
#define    CSMA_MODULE                                     (1)
#if        CSMA_MODULE
#define    STATION_BLOCK_TIME                              (100)  
#define    STATION_SERIAL_TIME                             (200)
#define    COM_PAYLOAD_SIZE                                (20)
#define    COM_MAX_RETARY                                  (5)
#endif



/* 
 -------------------------------------------------------------------------------------------------
 |                          < BUTTON_MODULE   >                                                  |                                             
 -------------------------------------------------------------------------------------------------
 | < BUTTON_MODULE                : 0 module is not active                                       |
 |                                : 1 module is active                                           |
 | < NUMBER_OF_BUTTON             : number  of Buttons  used                                     |  
 | < BUTTON_PREDIOC_TASK_TIME     : run evey x time                                              |
 | < BUTTON_MAX_BUFFER            : max key stored                                               |
 | < BUTTON_DEDEBOUND_TIME        : time required to press or released switch                    |
 | < BUTTON_LONG_TIME             : time required to long press                                  |
 | < BUTTON_REPEAT_TIME           : time required to repeat key                                  |
 | < BUTTON_REPEAT_RATE           : time required between repeat key                             |
 | < note                         : keypad state is fixed active low                             |          
 | < SRAM USAGE                   : 14 Byte + BUTTON_MAX_BUFFER                                  |  
 | < PROGRAM USAGE                : 624 Byte (312 Instruction)                                   |               
 -------------------------------------------------------------------------------------------------
 */
#define   BUTTON_MODULE                   1
#if BUTTON_MODULE
#define   BUTTON_MAX_EVENT               (3)
#define   BUTTON_DEDEBOUND_TIME          (20)   /* 20 ms*/
#define   BUTTON_LONG_TIME               (2000) /* 2 second*/
#define   BUTTONS_QUEUE_SIZE             (3)
#define   BUTTON_01_PIN                   GPIO_C3
#define   BUTTON_02_PIN                   GPIO_C4
#define   BUTTON_03_PIN                   GPIO_C5
#define   BUTTON_04_PIN                   NOT_A_PIN
#define   BUTTON_05_PIN                   NOT_A_PIN
#define   BUTTON_06_PIN                   NOT_A_PIN
#define   BUTTON_07_PIN                   NOT_A_PIN
#define   BUTTON_08_PIN                   NOT_A_PIN
#endif     
/*
 ----------------------------------------------------------------------------------------
 |                                <TONE_MODULE>                                         | 
 ----------------------------------------------------------------------------------------
 | < TONE_MODULE             : 0 module is not active                                   | 
 |                           : 1 module is active                                       |
777uuu7 | <TONES_MAX_PINS_USED      : Number of Pin Used                                       |
 | < TONE_PINx_GPIO          : GPIO_Access Pin                                          |
 | < TONE_PINx_DEFALUT_STATE : PIN defalut case High or low                             |
 | < SRAM USAGE              :  Byte Per Pin  +2 Byte Pinter to first signal            |      
 | < PROGRAM USAGE           :                                                          |  
 ----------------------------------------------------------------------------------------
 */
#define       TONE_MODULE                      (1)
#if TONE_MODULE
#define          TONES_MAX_PINS_USED           (2)
#define          TONE_PIN0_GPIO             GPIO_C6
#define          TONE_PIN1_GPIO             GPIO_C0
#define          TONE_PIN0_DEFALUT_STATE    GPIO_LOW
#define          TONE_PIN1_DEFALUT_STATE    GPIO_HIGH
#endif

/*
----------------------------------------------------------------------------------------
|                                <EEPROM MODULE>                                       | 
----------------------------------------------------------------------------------------
| < EEPROM_MODULE           : 0 module is not active                                   | 
|                           : 1 module is active                                       |
| < SRAM USAGE              : 21-Byte 10 in Read Buffer 4Byte Time out , 7 Byte used   |  
| < PROGRAM USAGE           : 722 Byte (361 Instruction)                               |  
----------------------------------------------------------------------------------------
 */
#define       EEPROM_MODULE                   (1)
#define       EEPROM_MAX_BUFFER_SIZE          (10)

#endif	/* RES_H */

