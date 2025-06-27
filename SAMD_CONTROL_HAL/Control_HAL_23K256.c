/* Include ::: Headers :: Origin */
#include "Control_HAL_23K256.h"
/* Include ::: Header Drivers */
#include "Driver_SAMD_PORT.h"
#include "Driver_SAMD_SERCOM2_SPIM.h"
/* Include ::: Header Storage */
#include "Storage_DELAY.h"

/******************************************************************************/
/* == Configuration Macros = Defines Controls  == */
/******************************************************************************/
#define vSRAM_23K256_PUT(D)     vDriver_SAMD_SERCOM2_SPIM_PUT(D)
#define xSRAM_23K256_GET()      xDriver_SAMD_SERCOM2_SPIM_GET()
#define xSRAM_23K256_PUTS(D, L) vDriver_SAMD_SERCOM2_SPIM_PUTS(D, L)
#define xSRAM_23K256_GETS(D, L) vDriver_SAMD_SERCOM2_SPIM_GETS(D, L)

#define SRAM_23K256_SS_ENABLE()                                                                                                                                                                                                                                                                            \
  SRAM_SS_CLR();                                                                                                                                                                                                                                                                                           \
  vStorage_DELAY_US(5U)

#define SRAM_23K256_SS_DISABLE()                                                                                                                                                                                                                                                                           \
  SRAM_SS_SET();                                                                                                                                                                                                                                                                                           \
  vStorage_DELAY_US(5U)

/******************************************************************************/
/* == Development Configuration Functions == */
/******************************************************************************/

void vControl_HAL_SRAM_CONFIGURE(void) {
  /* Variables ::: Locales */
  uint08_t STATUS = 0U;

  /* Power-On State */
  SRAM_23K256_SS_DISABLE();
  vStorage_DELAY_MS(100U);

  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Read Config and Mode Saved >*/
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_READ);
    STATUS = xSRAM_23K256_GET();

    /* Select Mode Byte Control Whitout HOLD Ctrl */
    if ((STATUS & 0xFE) != CONTROL_HAL_SRAM_23K256_MODE_BYTE) {
      vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_WRITE);
      vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_MODE_BYTE | CONTROL_HAL_SRAM_23K256_HOLD_DISABLE);
    }
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}

void vControl_HAL_SRAM_WRITE_STATUS(uint08_t DATA) {
  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write Mode :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_WRITE);
    /* Write Value :: Read Status Register */
    vSRAM_23K256_PUT(DATA);
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}

/* Prototipo ::: Funciones Cotrol :: SRAM_23K256 */
uint08_t xControl_HAL_SRAM_READ_STATUS(void) {
  /* Variables ::: Locales */
  uint08_t READ_DATA = 0U;

  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write Mode :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_READ);
    /* Read the Status register */
    READ_DATA = xSRAM_23K256_GET();
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();

  /* Return ::: Value */
  return (READ_DATA);
}

void vControl_HAL_SRAM_WRITE_CMD(uint16_t ADDRESS, uint08_t COMMAND) {
  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write COMMAND :: Read Status Register */
    vSRAM_23K256_PUT(COMMAND);
    /* Write MSB ADDRESS */
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 1U));
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 0U));
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}

void vControl_HAL_SRAM_PUT(uint16_t ADDRESS, uint08_t DATA) {
  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write COMMAND :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_CMD_WRITE);
    /* Write MSB ADDRESS */
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 1U));
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 0U));
    /* Write DATA */
    vSRAM_23K256_PUT(DATA);
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}

uint08_t xControl_HAL_SRAM_GET(uint16_t ADDRESS) {
  /* Variables ::: Locales */
  uint08_t DATA = 0U;

  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write COMMAND :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_CMD_READ);
    /* Write MSB ADDRESS */
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 1U));
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 0U));
    /* Read DATA */
    DATA = xSRAM_23K256_GET();
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();

  /* Return ::: Value */
  return (DATA);
}

void vControl_HAL_SRAM_PAGE_PUT(uint16_t ADDRESS, uint08_t *DATA) {
  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write Mode :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_WRITE);
    /* Write Value :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_MODE_PAGE);
    /* Write COMMAND :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_CMD_WRITE);
    /* Write MSB ADDRESS */
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 1U));
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 0U));

    /* Send Buffer 32 Bytes */
    for (uint08_t COUNT = 0U; COUNT < CONTROL_HAL_SRAM_23K256_PAGE_SIZE; COUNT++) {
      /* Write ::: DATA */
      vSRAM_23K256_PUT(*DATA++);
    }
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}

void vControl_HAL_SRAM_PAGE_GET(uint16_t ADDRESS, uint08_t *DATA) {
  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write Mode :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_WRITE);
    /* Write Value :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_MODE_PAGE);
    /* Write COMMAND :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_CMD_READ);
    /* Write MSB ADDRESS */
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 1U));
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 0U));

    /* Receive Buffer 32 Bytes */
    for (uint08_t COUNT = 0U; COUNT < CONTROL_HAL_SRAM_23K256_PAGE_SIZE; COUNT++) {
      /* Read ::: DATA */
      *DATA++ = xSRAM_23K256_GET();
    }
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}

void vControl_HAL_SRAM_SEQ_PUT(uint16_t ADDRESS, uint08_t *DATA, uint16_t LENGTH) {
  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write Mode :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_WRITE);
    /* Write Value :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_MODE_SEQU);
    /* Write COMMAND :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_CMD_WRITE);
    /* Write MSB ADDRESS */
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 1U));
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 0U));

    /* Send DATA to be written to SRAM */
    for (uint08_t COUNT = 0U; COUNT < LENGTH; COUNT++) {
      /* Write ::: DATA */
      vSRAM_23K256_PUT(*DATA++);
    }
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}

void vControl_HAL_SRAM_SEQ_GET(uint16_t ADDRESS, uint08_t *DATA, uint16_t LENGTH) {
  /* Select ::: Device */
  SRAM_23K256_SS_ENABLE();
  {
    /* Write Mode :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_STATUS_WRITE);
    /* Write Value :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_MODE_SEQU);
    /* Write COMMAND :: Read Status Register */
    vSRAM_23K256_PUT(CONTROL_HAL_SRAM_23K256_CMD_READ);
    /* Write MSB ADDRESS */
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 1U));
    vSRAM_23K256_PUT(*((uint08_t *)(&ADDRESS) + 0U));

    /* Receive DATA to be Reading to SRAM */
    for (uint08_t COUNT = 0U; COUNT < LENGTH; COUNT++) {
      /* Read ::: DATA */
      *DATA++ = xSRAM_23K256_GET();
    }
  } /* Power-Off State */
  SRAM_23K256_SS_DISABLE();
}
