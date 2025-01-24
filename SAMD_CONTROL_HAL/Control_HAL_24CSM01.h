#ifndef CONTROL_HAL_24CSM01_H
#define	CONTROL_HAL_24CSM01_H

/* Configuration Main Settings */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Configuration Macros = Eeprom 24XX04  == */
/******************************************************************************/
#define CONTROL_HAL_EEP_24CM01_DEVICE_WRITE               (0xA0) // Address Write Data
#define CONTROL_HAL_EEP_24CM01_DEVICE_READ                (0xA1) // Address Read Data
#define CONTROL_HAL_EEP_24CM01_PAGE_WRITE                 (0x100) // 16 Bytes for Page
#define CONTROL_HAL_EEP_24CM01_BLOCK_SIZE                 (0x200) // 256 Bytes for Blocks

/******************************************************************************/
/* == Prototype Configuration Functions == */
/******************************************************************************/

uint01_t xControl_HAL_EEP_24CM01_CHECK(void);
uint01_t xControl_HAL_EEP_24CM01_BLANK(uint08_t BANK, uint08_t VALUE);

uint01_t xControl_HAL_EEP_24CM01_PUT(uint08_t BANK, uint08_t ADDRESS, uint08_t DATA);
uint08_t xControl_HAL_EEP_24CM01_GET(uint08_t BANK, uint08_t ADDRESS);

uint01_t xControl_HAL_EEP_24CM01_PUTS(uint08_t BANK, uint08_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH);
uint01_t xControl_HAL_EEP_24CM01_GETS(uint08_t BANK, uint08_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH);

#endif	/* CONTROL_HAL_24CSM01_H */

