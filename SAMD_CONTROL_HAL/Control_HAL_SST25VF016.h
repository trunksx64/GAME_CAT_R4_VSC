#ifndef CONTROL_HAL_SST25VF016_H
#define CONTROL_HAL_SST25VF016_H

/* Configuration Main Settings */
#include "Storage_CLASS.h"
#include "Storage_DELAY.h"

/******************************************************************************/
/* == Configuration Macros = UID Serial Flash Memory == */
/******************************************************************************/
#define CONTROL_HAL_FLASH_SST25VF016_JEDEC_ID                    (0xBF2541)

/******************************************************************************/
/* == Configuration Macros = Block Segmentation == */
/******************************************************************************/
#define CONTROL_HAL_FLASH_SST25VF016_PAGE_SIZE                   (0x100) // Page Buffer
#define CONTROL_HAL_FLASH_SST25VF016_WORD_SIZE                   (0x002) // Page Buffer
#define CONTROL_HAL_FLASH_SST25VF016_SECTOR_4K                   (0x010) // 16 Sectors
#define CONTROL_HAL_FLASH_SST25VF016_BLOCK_32K                   (0x040) // 64 Blocks
#define CONTROL_HAL_FLASH_SST25VF016_BLOCK_64K                   (0x020) // 32 Blocks

#define CONTROL_HAL_FLASH_SST25VF016_START_ADDR_MEMORY           (0x000000)
#define CONTROL_HAL_FLASH_SST25VF016_FINAL_ADDR_MEMORY           (0x1FFFFF)

/******************************************************************************/
/* == Configuration Macros = CMD Serial Flash Memory == */
/******************************************************************************/
#define CONTROL_HAL_FLASH_SST25VF016_CMD_READ                    (0x03)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_READ_HIGH_SPEED         (0x0B)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_04K_SECTORS       (0x20)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_32K_BLOCK         (0x52)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_64K_BLOCK         (0xD8)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_ERASE_ALL_BLOCKS        (0xC7)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_PROGRAM_BYTE            (0x02)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_PROGRAM_WORD            (0xAD)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_READ_STATUS_REG         (0x05)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_ENABLE_WRITE_STATUS_REG (0x50)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_WRITE_STATUS_REG        (0x01)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_ENABLE_WRITE            (0x06)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_DISABLE_WRITE           (0x04)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_READ_ID                 (0x90)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_READ_JEDEC_ID           (0x9F)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_ENABLE_BUSY_SO          (0x70)
#define CONTROL_HAL_FLASH_SST25VF016_CMD_DISABLE_BUSY_SO         (0x80)

/******************************************************************************/
/* == Configuration Macros = Status Serial Flash Memory == */
/******************************************************************************/
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BUSY_BIT         (0x01)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_WEL_BIT          (0x02)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BP0_BIT          (0x04)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BP1_BIT          (0x08)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BP2_BIT          (0x10)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BP3_BIT          (0x20)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BPW_BIT          (0x3C)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_AAI_BIT          (0x40)
#define CONTROL_HAL_FLASH_SST25VF016_STATUS_REG_BPL_BIT          (0x80)

/******************************************************************************/
/* == Prototype Configuration Functions == */
/******************************************************************************/

uint01_t xControl_HAL_FLASH_SST25VF016_CHECK(void);
void vControl_HAL_FLASH_SST25VF016_CONFIG(void);

/*----------------------------------------------------------------------------*/

void vControl_HAL_FLASH_SST25VF016_WRITE_ENABLE(void);
void vControl_HAL_FLASH_SST25VF016_WRITE_DISABLE(void);
void vControl_HAL_FLASH_SST25VF016_ENABLE_WRITE_STATUS(void);

/*----------------------------------------------------------------------------*/

uint08_t xControl_HAL_FLASH_SST25VF016_GET_STATUS(void);
void vControl_HAL_FLASH_SST25VF016_PUT_STATUS(uint08_t DATA);
void vControl_HAL_FLASH_SST25VF016_PUT_STATUS_SET(uint08_t DATA);
void vControl_HAL_FLASH_SST25VF016_PUT_STATUS_CLEAR(uint08_t DATA);

/*----------------------------------------------------------------------------*/

void vControl_HAL_FLASH_SST25VF016_BUSY_OUT_ENABLE(void);
void vControl_HAL_FLASH_SST25VF016_BUSY_OUT_DISABLE(void);
uint01_t xControl_HAL_FLASH_SST25VF016_CHECK_POLL_BUSY(void);

/*----------------------------------------------------------------------------*/

uint08_t xControl_HAL_FLASH_SST25VF016_GET_BYTE(uint32_t ADDRESS);
void vControl_HAL_FLASH_SST25VF016_PUT_BYTE(uint32_t ADDRESS, uint08_t DATA);

uint01_t xControl_HAL_FLASH_SST25VF016_GET_PAGE(uint32_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH);
uint01_t xControl_HAL_FLASH_SST25VF016_PUT_PAGE_BYTE(uint32_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH);
uint01_t xControl_HAL_FLASH_SST25VF016_PUT_PAGE_WORD(uint32_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH);

/*----------------------------------------------------------------------------*/

void vControl_HAL_FLASH_SST25VF016_BLOCK_ERASE_4K(uint32_t ADDRESS);
void vControl_HAL_FLASH_SST25VF016_BLOCK_ERASE_32K(uint32_t ADDRESS);
void vControl_HAL_FLASH_SST25VF016_BLOCK_ERASE_64K(uint32_t ADDRESS);
void vControl_HAL_FLASH_SST25VF016_CHIP_ERASE(void);

/*----------------------------------------------------------------------------*/

uint16_t xControl_HAL_FLASH_SST25VF016_GET_DEVICE_ID(uint01_t ADD);
uint32_t xControl_HAL_FLASH_SST25VF016_GET_JEDEC(void);

#endif /* CONTROL_HAL_SST25VF016_H */
