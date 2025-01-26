#ifndef CONTROL_HAL_24CSM01_H
#define	CONTROL_HAL_24CSM01_H

/* Configuration Main Settings */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Configuration Macros = Eeprom 24XX04  == */
/******************************************************************************/
#define CONTROL_HAL_EEP_24CM01_DEVICE_WRITE               (uint08_t)(0xA0) // Address Write Data
#define CONTROL_HAL_EEP_24CM01_DEVICE_READ                (uint08_t)(0xA1) // Address Read Data
#define CONTROL_HAL_EEP_24CM01_PAGE_WRITE                 (uint16_t)(256U) // 256 Bytes for Page
#define CONTROL_HAL_EEP_24CM01_BLOCK_SIZE                 (uint16_t)(512U) // 512 Bytes for Blocks
#define CONTROL_HAL_EEP_24CM01_START                      (uint32_t)(0x00000) 
#define CONTROL_HAL_EEP_24CM01_FINAL                      (uint32_t)(0x1FFFF)

/******************************************************************************/
/* == Prototype Configuration Functions == */
/******************************************************************************/

uint01_t xControl_HAL_EEP_24CM01_CHECK(void);
uint01_t xControl_HAL_EEP_24CM01_BLANK(uint08_t VALUE);

uint01_t xControl_HAL_EEP_24CM01_PUT(uint32_t ADDRESS, uint08_t DATA);
uint08_t xControl_HAL_EEP_24CM01_GET(uint32_t ADDRESS);

uint01_t xControl_HAL_EEP_24CM01_PUTS(uint32_t ADDRESS, uint08_t *pxBUFFER, uint16_t LENGTH);
uint01_t xControl_HAL_EEP_24CM01_GETS(uint32_t ADDRESS, uint08_t *pxBUFFER, uint16_t LENGTH);

#endif	/* CONTROL_HAL_24CSM01_H */

