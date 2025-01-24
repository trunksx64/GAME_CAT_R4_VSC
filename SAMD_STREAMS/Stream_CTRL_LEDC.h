#ifndef STREAM_CTRL_LED_H
#define STREAM_CTRL_LED_H

/* Configuration Main Settings */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Configuration Macros = Control CMD for LED == */

/******************************************************************************/

typedef enum {
    CMD_LED_CLR, CMD_LED_SET, CMD_LED_TGL, CMD_LED_TMR
} xStream_Command_Led_t;

typedef enum {
    NUM_LED_BUSY, NUM_LED_CTRL
} xStream_Number_Led_t;

/******************************************************************************/
/* == Typedef Control Variables = Struct Data LED == */

/******************************************************************************/

typedef struct __LED_COUNTER {
    xStream_Command_Led_t COMMAD;
    uint32_t TIME_OVERFLOW;
    uint32_t TIME_LAST;
} xStream_Led_Counter_t;

typedef struct __LED_CONFIG {
    xStream_Command_Led_t COMMAND;
    xStream_Number_Led_t NUMBER_LED;
    uint32_t TIMER;
} xStream_Led_Config_t;

/******************************************************************************/
/* == Prototype Configuration Functions = Control CMD for LED == */
/******************************************************************************/

uint01_t xStream_LED_COMMAND(uint08_t LED, uint08_t COMMAND, uint32_t TIME);

#endif /* STREAM_CTRL_LED_H */
