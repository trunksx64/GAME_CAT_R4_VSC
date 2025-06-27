/* Include ::: Headers :: Origin */
#include "Control_HAL_24CSM01.h"
/* Include ::: Header Drivers */
#include "Driver_SAMD_SERCOM1_I2CM.h"
/* Include ::: Header Storage */
#include "Storage_DELAY.h"

/******************************************************************************/
/* == Configuration Macros = Defines Controls  == */
/******************************************************************************/
#define xCONTROL_HAL_EEP_24CM01_POLL(D)          xDriver_SAMD_SERCOM1_I2C_POLL(D)
#define xCONTROL_HAL_EEP_24CM01_SET_ACK(D)       vDriver_SAMD_SERCOM1_I2C_SET_ACK(D)
#define xCONTROL_HAL_EEP_24CM01_SET_STOP()       vDriver_SAMD_SERCOM1_I2C_SET_STOP()
#define xCONTROL_HAL_EEP_24CM01_PUT_START(D)     xDriver_SAMD_SERCOM1_I2C_SET_START(D)
#define xCONTROL_HAL_EEP_24CM01_PUT_RESTART()    xDriver_SAMD_SERCOM1_I2C_SET_RESTART()
#define xCONTROL_HAL_EEP_24CM01_PUT_BYTE(D)      xDriver_SAMD_SERCOM1_I2C_PUT(D)
#define xCONTROL_HAL_EEP_24CM01_GET_BYTE(D)      xDriver_SAMD_SERCOM1_I2C_GET(D)
#define xCONTROL_HAL_EEP_24CM01_PUT_BUFFER(D, L) xDriver_SAMD_SERCOM1_I2C_PUTS(D, L)
#define xCONTROL_HAL_EEP_24CM01_GET_BUFFER(D, L) xDriver_SAMD_SERCOM1_I2C_GETS(D, L)

/******************************************************************************/
/* == Development Configuration Functions == */

/******************************************************************************/

uint01_t xControl_HAL_EEP_24CM01_CHECK(void) {
  /* Return ::: ACK */
  return (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS));
}

uint01_t xControl_HAL_EEP_24CM01_BLANK(uint08_t VALUE) {
  /* Local ::: Variables */
  uint32_t ADDRESS = 0U;
  uint08_t BUFFER[CONTROL_HAL_EEP_24CM01_PAGE_SIZE];

  /*------------------------------------------------------------------------*/

  /* Blank ::: pxBUFFER */
  memset(BUFFER, VALUE, sizeof(BUFFER));

  /*------------------------------------------------------------------------*/

  /* CHK ::: Device is Ready */
  if (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS) == pdSET) {
    /* Loop ::: Send Blank DATA to Eeprom */
    for (uint16_t I_COUNT = 0U; I_COUNT < CONTROL_HAL_EEP_24CM01_BLOCK_SIZE; I_COUNT++) {
      /* UDP ::: Next Page */
      ADDRESS = (I_COUNT * CONTROL_HAL_EEP_24CM01_PAGE_SIZE);

      /* CHK ::: Device is Ready */
      if (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS) == pdSET) {
        /* Sequence Write DATA */
        xCONTROL_HAL_EEP_24CM01_PUT_START(CONTROL_HAL_EEP_24CM01_ADDRESS | ((*((uint08_t *)&ADDRESS + 2U) & 0x01) << 1U)); // Start Signal & Write Address Eeprom
        xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 1U));                                                    // Write ADDRESS Memory
        xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 0U));                                                    // Write ADDRESS Memory
        xCONTROL_HAL_EEP_24CM01_PUT_BUFFER(BUFFER, CONTROL_HAL_EEP_24CM01_PAGE_SIZE);                                      // Write pxBUFFER
        xCONTROL_HAL_EEP_24CM01_SET_ACK(pdSET);                                                                            // Write ACK VALUE
        xCONTROL_HAL_EEP_24CM01_SET_STOP();                                                                                // Stop Signal..

        /* If the write command is acknowledged, then the device is ready */
        while (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS) == pdCLR)
          ;
      } else {
        /* Return ::: Status */
        return (pdCLR);
      }
    }
  }

  /*------------------------------------------------------------------------*/

  /* Return ::: Status */
  return (pdSET);
}

uint01_t xControl_HAL_EEP_24CM01_PUT(uint32_t ADDRESS, uint08_t DATA) {
  /* CHK ::: Device is Ready */
  if (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS) == pdSET) {
    /* Sequence Write DATA */
    xCONTROL_HAL_EEP_24CM01_PUT_START(CONTROL_HAL_EEP_24CM01_ADDRESS | ((*((uint08_t *)&ADDRESS + 2U) & 0x01) << 1U)); // Start Signal & Write Address Eeprom
    xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 1U));                                                    // Write ADDRESS Memory
    xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 0U));                                                    // Write ADDRESS Memory
    xCONTROL_HAL_EEP_24CM01_PUT_BYTE(DATA);                                                                            // Write Data Memory
    xCONTROL_HAL_EEP_24CM01_SET_ACK(pdSET);                                                                            // Write ACK VALUE
    xCONTROL_HAL_EEP_24CM01_SET_STOP();                                                                                // Stop Signal..

    /* If the write command is acknowledged, then the device is ready */
    while (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS) == pdCLR)
      ;

    /* Return ::: Status */
    return (pdSET);
  } else {
    /* Return ::: Status */
    return (pdCLR);
  }
}

uint08_t xControl_HAL_EEP_24CM01_GET(uint32_t ADDRESS) {
  /* Local ::: Variables */
  uint08_t DATA = 0U;

  /*------------------------------------------------------------------------*/

  /* CHK ::: Device is Ready */
  if (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS) == pdSET) {
    /* Sequence Write DATA */
    xCONTROL_HAL_EEP_24CM01_PUT_START(CONTROL_HAL_EEP_24CM01_ADDRESS | ((*((uint08_t *)&ADDRESS + 2U) & 0x01) << 1U));          // Start Signal & Write Address Eeprom
    xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 1U));                                                             // Write ADDRESS Memory
    xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 0U));                                                             // Write ADDRESS Memory
    xCONTROL_HAL_EEP_24CM01_PUT_START((CONTROL_HAL_EEP_24CM01_ADDRESS | 0x01) | ((*((uint08_t *)&ADDRESS + 2U) & 0x01) << 1U)); // Start Signal & Write Address Eeprom
    xCONTROL_HAL_EEP_24CM01_GET_BYTE(&DATA);                                                                                    // Write Data Memory
    xCONTROL_HAL_EEP_24CM01_SET_ACK(pdCLR);                                                                                     // Write ACK VALUE
    xCONTROL_HAL_EEP_24CM01_SET_STOP();                                                                                         // Stop Signal..

    /* Return ::: Status */
    return (DATA);
  } else {

    /* Return ::: Status */
    return (pdCLR);
  }
}

uint01_t xControl_HAL_EEP_24CM01_PUTS(uint32_t ADDRESS, uint08_t *pxBUFFER, uint16_t LENGTH) {
  /* Variables ::: Locals */
  uint16_t OFFSET = CONTROL_HAL_EEP_24CM01_ADDRESS;
  uint16_t WRAP_AROUND = 0U;
  uint01_t RETURN = pdCLR;

  /*--------------------------------------------------------------------------*/

  /* Check ::: pxDATA & LENGTH */
  if (pxBUFFER && (LENGTH && (LENGTH <= CONTROL_HAL_EEP_24CM01_DEVICE_FINAL))) {
    /* Counter ::: LENGTH */
    do {
      /* Check ::: Maximun Size for Eeprom */
      OFFSET = ((OFFSET > LENGTH) ? LENGTH : CONTROL_HAL_EEP_24CM01_PAGE_SIZE);
      /* Check ::: Limit of Page */
      WRAP_AROUND = (CONTROL_HAL_EEP_24CM01_PAGE_SIZE - (ADDRESS % CONTROL_HAL_EEP_24CM01_PAGE_SIZE));
      /* Check ::: WRAP_AROUND vs OFFSET*/
      OFFSET = ((OFFSET > WRAP_AROUND) ? WRAP_AROUND : OFFSET);

      /*--------------------------------------------------------------------*/

      /* Sequence Write DATA */
      xCONTROL_HAL_EEP_24CM01_PUT_START(CONTROL_HAL_EEP_24CM01_ADDRESS | ((*((uint08_t *)&ADDRESS + 2U) & 0x01) << 1U)); // Start Signal & Write Address Eeprom
      xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 1U));                                                    // Write ADDRESS Memory
      xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 0U));                                                    // Write ADDRESS Memory
      RETURN = xCONTROL_HAL_EEP_24CM01_PUT_BUFFER(pxBUFFER, OFFSET);                                                     // Write Data Memory
      xCONTROL_HAL_EEP_24CM01_SET_ACK(pdSET);                                                                            // Write ACK VALUE
      xCONTROL_HAL_EEP_24CM01_SET_STOP();                                                                                // Stop Signal..

      /* If the write command is acknowledged, then the device is ready */
      while (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_ADDRESS) == pdCLR)
        ;

      /*--------------------------------------------------------------------*/

      /* Check ::: RETURN */
      if (RETURN) {
        /* Decrement ::: Ctrl */
        LENGTH -= OFFSET;
        /* Update ::: Address Buffer */
        pxBUFFER += OFFSET;
        ADDRESS += OFFSET;
      } else {
        /* Stop ::: Loop */
        break;
      }
    } while (LENGTH);
  }

  /*--------------------------------------------------------------------------*/

  /* Return ::: Status */
  return (RETURN);
}

uint01_t xControl_HAL_EEP_24CM01_GETS(uint32_t ADDRESS, uint08_t *pxBUFFER, uint16_t LENGTH) {
  /* Variables ::: Locals */
  uint16_t OFFSET = CONTROL_HAL_EEP_24CM01_BLOCK_SIZE;
  uint01_t RETURN = pdCLR;

  /*--------------------------------------------------------------------------*/

  /* Check ::: pxDATA & LENGTH */
  if (pxBUFFER && (LENGTH && (LENGTH <= CONTROL_HAL_EEP_24CM01_DEVICE_FINAL))) {
    /* Counter ::: LENGTH */
    do {
      /* Check ::: Maximun Size for Eeprom */
      OFFSET = ((OFFSET > LENGTH) ? LENGTH : CONTROL_HAL_EEP_24CM01_BLOCK_SIZE);

      /*--------------------------------------------------------------------*/

      /* Sequence Write DATA */
      xCONTROL_HAL_EEP_24CM01_PUT_START(CONTROL_HAL_EEP_24CM01_ADDRESS | ((*((uint08_t *)&ADDRESS + 2U) & 0x01) << 1U));          // Start Signal & Write Address Eeprom
      xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 1U));                                                             // Write ADDRESS Memory
      xCONTROL_HAL_EEP_24CM01_PUT_BYTE(*((uint08_t *)&ADDRESS + 0U));                                                             // Write ADDRESS Memory
      xCONTROL_HAL_EEP_24CM01_PUT_START((CONTROL_HAL_EEP_24CM01_ADDRESS | 0x01) | ((*((uint08_t *)&ADDRESS + 2U) & 0x01) << 1U)); // Start Signal & Write Address Eeprom
      xCONTROL_HAL_EEP_24CM01_GET_BUFFER(pxBUFFER, OFFSET);                                                                       // Write Data Memory
      xCONTROL_HAL_EEP_24CM01_SET_ACK(pdCLR);                                                                                     // Write ACK VALUE
      xCONTROL_HAL_EEP_24CM01_SET_STOP();                                                                                         // Stop Signal

      /*--------------------------------------------------------------------*/

      /* Check ::: RETURN */
      if (RETURN) {
        /* Decrement ::: Ctrl */
        LENGTH -= OFFSET;
        /* Update ::: Address Buffer */
        pxBUFFER += OFFSET;
        ADDRESS += OFFSET;
      } else {
        /* Stop ::: Loop */
        break;
      }
    } while (LENGTH);
  }

  /*--------------------------------------------------------------------------*/

  /* Return ::: Status */
  return (RETURN);
}
