#ifndef CONTROL_HAL_23K256_H
#define CONTROL_HAL_23K256_H

/* Configuration Main Settings */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Configuration Macros = CMD SRAM Memory == */
/******************************************************************************/
#define CONTROL_HAL_SRAM_23K256_CMD_READ     (0x03) //  Read COMMAND for SRAM
#define CONTROL_HAL_SRAM_23K256_CMD_WRITE    (0x02) //  Write COMMAND for SRAM
#define CONTROL_HAL_SRAM_23K256_STATUS_READ  (0x05) //  Read the status register
#define CONTROL_HAL_SRAM_23K256_STATUS_WRITE (0x01) //  Write the status register
#define CONTROL_HAL_SRAM_23K256_MODE_BYTE    (0x00) //  Mode Byte, Hold Disabled
#define CONTROL_HAL_SRAM_23K256_MODE_PAGE    (0x80) //  Mode Page, Hold Disabled
#define CONTROL_HAL_SRAM_23K256_MODE_SEQU    (0x40) //  Mode Sequential, Hold Disabled
#define CONTROL_HAL_SRAM_23K256_HOLD_ENABLE  (0x00)
#define CONTROL_HAL_SRAM_23K256_HOLD_DISABLE (0x01)
#define CONTROL_HAL_SRAM_23K256_PAGE_SIZE    (0x20)

/******************************************************************************/
/* == Prototype Configuration Functions == */
/******************************************************************************/

void vControl_HAL_SRAM_CONFIGURE(void);

void vControl_HAL_SRAM_WRITE_STATUS(uint8_t DATA);
uint8_t xControl_HAL_SRAM_READ_STATUS(void);
void vControl_HAL_SRAM_WRITE_CMD(uint16_t ADDRESS, uint8_t COMMAND);

void vControl_HAL_SRAM_PUT(uint16_t ADDRESS, uint8_t DATA);
uint8_t xControl_HAL_SRAM_GET(uint16_t ADDRESS);
void vControl_HAL_SRAM_PAGE_PUT(uint16_t ADDRESS, uint8_t *DATA);
void vControl_HAL_SRAM_PAGE_GET(uint16_t ADDRESS, uint8_t *DATA);
void vControl_HAL_SRAM_SEQ_PUT(uint16_t ADDRESS, uint8_t *pxBUFFER, uint16_t LENGTH);
void vControl_HAL_SRAM_SEQ_GET(uint16_t ADDRESS, uint8_t *pxBUFFER, uint16_t LENGTH);

#endif /* CONTROL_HAL_23K256_H */