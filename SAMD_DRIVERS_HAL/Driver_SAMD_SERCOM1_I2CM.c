/* Include ::: Header File Source */
#include "Driver_SAMD_SERCOM1_I2CM.h"
/* Driver ::: Configuration */
#include "Driver_SAMD_GCLK.h"

/******************************************************************************/
/* == Development Configuration Hardware SAMC :: SERCOM I2C == */
/******************************************************************************/

/* Function ::: Configure */
void vDriver_SAMD_SERCOM1_I2CM_CONFIGURE(void) {
  /* BRK ::: DEBUG */
  pdNOP();

  /*------------------------------------------------------------------------*/

  /* Enable ::: Device */
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM1(pdSET); // SERCOM1 APBC Mask Clock Enable

  /* Set Source Main Clock */
  GCLK_REGS->GCLK_CLKCTRL = (GCLK_CLKCTRL_ID_SERCOM1_CORE | // Generic Clock Selection ID
                             GCLK_CLKCTRL_GEN_GCLK2 |       // Generic Clock Generator
                             GCLK_CLKCTRL_CLKEN(pdSET) |    // Clock Enable
                             GCLK_CLKCTRL_WRTLOCK(pdCLR));  // Write Lock
  /* While ::: Sync */
  while (GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY(pdSET)) {}

  /*------------------------------------------------------------------------*/

  /* Configuration SERCOM1 (I2C) ------------------------------------------ */
  SERCOM1_REGS->I2CM.SERCOM_CTRLA |= SERCOM_I2CM_CTRLA_SWRST(pdSET); // Reset Module for Configuration
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SWRST(pdSET))
    ; // Wait Process Complete

  /* CFG ::: SERCOM1 (I2C) :: CTRLA --------------------------------- */
  SERCOM1_REGS->I2CM.SERCOM_CTRLA = (SERCOM_I2CM_CTRLA_LOWTOUTEN(pdCLR) |             // SCL Low Time-Out
                                     SERCOM_I2CM_CTRLA_INACTOUT_DISABLE |             // Inactive Time-Out
                                     SERCOM_I2CM_CTRLA_SCLSM(pdCLR) |                 // SCL Clock Stretch Mode
                                     SERCOM_I2CM_CTRLA_SPEED_STANDARD_AND_FAST_MODE | // Standard-mode (Sm) up to 100 kHz
                                     SERCOM_I2CM_CTRLA_SEXTTOEN(pdCLR) |              // Slave SCL Low Extend Time-Out
                                     SERCOM_I2CM_CTRLA_MEXTTOEN(pdCLR) |              // Master SCL Low Extend Time-Out
                                     SERCOM_I2CM_CTRLA_SDAHOLD_DISABLE |              // SDA Hold Time
                                     SERCOM_I2CM_CTRLA_PINOUT(pdCLR) |                // Pin Usage 4-wire operation disabled
                                     SERCOM_I2CM_CTRLA_RUNSTDBY(pdCLR) |              // Run in Standby
                                     SERCOM_I2CM_CTRLA_MODE_I2C_MASTER);              // Operating Mode

  /* CFG ::: SERCOM1 (I2C) :: CTRLB --------------------------------- */
  SERCOM1_REGS->I2CM.SERCOM_CTRLB = (SERCOM_I2CM_CTRLB_CMD(0U) |     // Command (No action)
                                     SERCOM_I2CM_CTRLB_QCEN(pdCLR) | // Quick Command
                                     SERCOM_I2CM_CTRLB_SMEN(pdCLR)); // Smart Mode

  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET)) {} // Wait Process Complete

  /* CFG ::: SERCOM1 (I2C) :: BAUD ---------------------------------- */
  SERCOM1_REGS->I2CM.SERCOM_BAUD = SERCOM_I2CM_BAUD_BAUD(SERCOM1_I2C_BAUD_RATE_CALC(configGCLK2_32MHZ, SERCOM1_I2C_BAUD_RATE)); // ((F_Ref/F_Baud)-(F_Ref*Trise)-10)

#if __DEBUG
  /* Configuration ::: SERCOM3 (UART) :: DBGCTRL -------------------------- */
  SERCOM1_REGS->I2CM.SERCOM_DBGCTRL = SERCOM_I2CM_DBGCTRL_DBGSTOP(pdCLR);
#endif

  /* CFG ::: SERCOM1 (I2C) :: CTRLA --------------------------------- */
  SERCOM1_REGS->I2CM.SERCOM_CTRLA |= SERCOM_I2CM_CTRLA_ENABLE(pdSET); // Enable
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_ENABLE(pdSET))
    ; // Wait Process Complete

  /* Bus State is Forced Into Idle State */
  SERCOM1_REGS->I2CM.SERCOM_STATUS |= SERCOM_I2CM_STATUS_BUSSTATE(1U);              // The Bus state is waiting for a transaction to be initialized
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET)) {} // Wait Process Complete

  /*------------------------------------------------------------------------*/

  /* Configuration ::: SERCOM1 (I2C) :: INTENCLER ------------------------- */
  SERCOM1_REGS->I2CM.SERCOM_INTENCLR = SERCOM_I2CM_INTENSET_ERROR(pdSET); // Interruption Error
  SERCOM1_REGS->I2CM.SERCOM_INTENCLR = SERCOM_I2CM_INTENSET_SB(pdSET);    // Interruption Slave
  SERCOM1_REGS->I2CM.SERCOM_INTENCLR = SERCOM_I2CM_INTENSET_MB(pdSET);    // Interruption Master

  /* Configuration ::: SERCOM1 (I2C) :: NVIC Interruption ----------------- */
  NVIC_ClearPendingIRQ(SERCOM1_IRQn); // Clear Pending Interruptions
  NVIC_DisableIRQ(SERCOM1_IRQn);      // Disable Vector Interruption
}

uint08_t xDriver_SAMD_SERCOM1_I2C_GET_ERROR(void) {
  /* CHK ::: Error Status */
  if (SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_LENERR(pdSET)) {
    /* Return ::: Execution */
    return (SERCOM1_I2C_ERROR_LENERR);
  } else if (SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_SEXTTOUT(pdSET)) {
    /* Return ::: Execution */
    return (SERCOM1_I2C_ERROR_SEXTTOUT);
  } else if (SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_MEXTTOUT(pdSET)) {
    /* Return ::: Execution */
    return (SERCOM1_I2C_ERROR_MEXTTOUT);
  } else if (SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_CLKHOLD(pdSET)) {
    /* Return ::: Execution */
    return (SERCOM1_I2C_ERROR_CLKHOLD);
  } else if (SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_LOWTOUT(pdSET)) {
    /* Return ::: Execution */
    return (SERCOM1_I2C_ERROR_LOWTOUT);
  } else if (SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_ARBLOST(pdSET)) {
    /* Return ::: Execution */
    return (SERCOM1_I2C_ERROR_ARBLOST);
  } else if (SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_BUSERR(pdSET)) {
    /* Return ::: Execution */
    return (SERCOM1_I2C_ERROR_BUSERR);
  } else {
    /* Return ::: Execution */
    return (SERCOM1_I2C_STATUS_NONE);
  }
}

uint01_t xDriver_SAMD_SERCOM1_I2C_POLL(uint8_t ADDRESS) {
  /* Local ::: Variables */
  uint16_t TIMEOUT = UINT16_MAX;
  uint01_t STATUS_ACK = 0U;

  /* CLR ::: Ints Flags */
  SERCOM1_REGS->I2CM.SERCOM_INTFLAG = (SERCOM_I2CM_INTFLAG_MB(pdSET) | SERCOM_I2CM_INTFLAG_ERROR(pdSET));

  /* PUT ::: Address Slave */
  SERCOM1_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(ADDRESS);
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
    ; // Wait Process Complete

  /* WAT ::: Flag Master on Bus Interrupt */
  while (!(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_MB(pdSET)) && (TIMEOUT--))
    ;

  /* GET ::: ACK from Slave Device */
  STATUS_ACK = !!(SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK(pdSET));

  /* PUT ::: Stop Signal */
  SERCOM1_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3U);
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
    ; // Wait Process Complete

  /* Return */
  return (!STATUS_ACK);
}

void vDriver_SAMD_SERCOM1_I2C_SET_ACK(uint01_t ACK) {
  /* PUT ::: STATUS ACK to Send >*/
  if (ACK == pdSET) {
    SERCOM1_REGS->I2CM.SERCOM_CTRLB &= ~SERCOM_I2CM_CTRLB_ACKACT(pdSET);
  } else {
    SERCOM1_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_ACKACT(pdSET);
  }
  /* WAT ::: Process Complete*/
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
    ;
}

void vDriver_SAMD_SERCOM1_I2C_SET_STOP(void) {
  /* CHK ::: STATUS Int Flags */
  if ((SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_MB(pdSET)) || (SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_SB(pdSET))) {
    /* PUT ::: Stop Signal */
    SERCOM1_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(3U);
    while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
      ; // Wait Process Complete
  }
}

uint08_t xDriver_SAMD_SERCOM1_I2C_SET_START(uint08_t ADDRESS) {
  /* Local ::: Variables */
  uint16_t TIMEOUT = UINT16_MAX;

  /* CLR ::: Ints Flags */
  SERCOM1_REGS->I2CM.SERCOM_INTENCLR = (SERCOM_I2CM_INTFLAG_MB(pdSET) | SERCOM_I2CM_INTFLAG_SB(pdSET) | SERCOM_I2CM_INTFLAG_ERROR(pdSET));

  /* PUT ::: Address Slave */
  SERCOM1_REGS->I2CM.SERCOM_ADDR = SERCOM_I2CM_ADDR_ADDR(ADDRESS);
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
    ; // Wait Process Complete;

  /* WAT ::: Flag Master on Bus Interrupt  */
  while (!(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_MB(pdSET)) && !(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_SB(pdSET)) && (TIMEOUT--))
    ;

  /* CHK ::; Flag Error BUS */
  if (SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR(pdSET)) {
    /* GET ::: Error Bus */
    return (xDriver_SAMD_SERCOM1_I2C_GET_ERROR());
  } else
    ;

  /* Return ::: Execution */
  return (!!(SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK(pdSET)));
}

uint08_t xDriver_SAMD_SERCOM1_I2C_SET_RESTART(void) {
  /* Local ::: Variables */
  uint16_t TIMEOUT = UINT16_MAX;

  /* CLR ::: Ints Flags */
  SERCOM1_REGS->I2CM.SERCOM_INTENCLR = (SERCOM_I2CM_INTFLAG_MB(pdSET) | SERCOM_I2CM_INTFLAG_SB(pdSET) | SERCOM_I2CM_INTFLAG_ERROR(pdSET));

  /* PUT ::: Restart Signal */
  SERCOM1_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(1U);

  /* WAT ::: Flag Master on Bus Interrupt */
  while (!(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_MB(pdSET)) && !(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_SB(pdSET)) && (TIMEOUT--))
    ;

  /* CHK ::; Flag Error BUS */
  if (SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR(pdSET)) {
    /* GET ::: Error Bus */
    return (xDriver_SAMD_SERCOM1_I2C_GET_ERROR());
  } else
    ;

  /* Return ::: Execution */
  return (!!(SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK(pdSET)));
}

uint08_t xDriver_SAMD_SERCOM1_I2C_PUT(uint08_t DATA) {
  /* Local ::: Variables */
  uint16_t TIMEOUT = UINT16_MAX;

  /* CLR ::: Ints Flags */
  SERCOM1_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_MB(pdSET);

  /* PUT ::: Data to Slave Device */
  SERCOM1_REGS->I2CM.SERCOM_DATA = SERCOM_I2CM_DATA_DATA(DATA);
  while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
    ; // Wait Process Complete;

  /* WAT ::: Flag Master on Bus Interrupt  */
  while (!(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_MB(pdSET)) && (TIMEOUT--))
    ;

  /* CHK ::; Flag Error BUS */
  if (SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR(pdSET)) {
    /* GET ::: Error Bus */
    return (xDriver_SAMD_SERCOM1_I2C_GET_ERROR());
  } else
    ;

  /* Return ::: Execution */
  return (!!(SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK(pdSET)));
}

uint01_t xDriver_SAMD_SERCOM1_I2C_GET(uint08_t *DATA) {
  /* Local ::: Variables */
  uint16_t TIMEOUT = UINT16_MAX;

  /* CHK ::: Pointer Value */
  if (DATA != NULL) {
    /* CLR ::: Ints Flags */
    SERCOM1_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_ERROR(pdSET);

    /* WAT ::: Flag Master on Bus Interrupt */
    while (!(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_SB(pdSET)) && TIMEOUT--)
      ;

    /* GET ::: Input Buffer */
    *DATA = SERCOM1_REGS->I2CM.SERCOM_DATA;

    /* CHK ::; Flag Error BUS */
    if (SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR(pdSET)) {
      /* GET ::: Error Bus */
      return (xDriver_SAMD_SERCOM1_I2C_GET_ERROR());
    } else
      ;
  } else {
    /* Return ::: STATUS */
    return (pdCLR);
  }

  /* Return ::: STATUS */
  return (pdSET);
}

uint01_t xDriver_SAMD_SERCOM1_I2C_PUTS(uint08_t *DATA, uint16_t LENGTH) {
  /* Local ::: Variables */
  uint16_t TIMEOUT = UINT16_MAX;

  /* CHK ::: Pointer Value & Size Buffer */
  if (DATA && LENGTH) {
    /* WAT ::: Send all Buffer */
    while (LENGTH--) {
      /* CLR ::: Ints Flags */
      SERCOM1_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_MB(pdSET);

      /* PUT ::: Data to Slave Device */
      SERCOM1_REGS->I2CM.SERCOM_DATA = SERCOM_I2CM_DATA_DATA(*DATA++);
      while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
        ; // Wait Process Complete;

      /* WAT ::: Flag Master on Bus Interrupt  */
      while (!(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_MB(pdSET)) && (TIMEOUT--))
        ;

      /* CHK ::; Flag Error BUS */
      if (SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR(pdSET)) {
        /* GET ::: Error Bus */
        return (xDriver_SAMD_SERCOM1_I2C_GET_ERROR());
      } else
        ;

      /* Return ::: Execution */
      if (!!(SERCOM1_REGS->I2CM.SERCOM_STATUS & SERCOM_I2CM_STATUS_RXNACK(pdSET))) {
        /* Return ::: STATUS */
        return (pdCLR);
      } else
        ;

      /* CLR ::: TIMEOUT */
      TIMEOUT = UINT16_MAX;
    }
  } else {
    /* Return ::: STATUS */
    return (pdCLR);
  }

  /* Return ::: STATUS */
  return (pdSET);
}

uint01_t xDriver_SAMD_SERCOM1_I2C_GETS(uint08_t *DATA, uint16_t LENGTH) {
  /* Local ::: Variables */
  uint16_t TIMEOUT = UINT16_MAX;

  /* CHK ::: Pointer Value & Size Buffer */
  if (DATA && LENGTH) {
    /* WAT ::: Send all Buffer */
    while (LENGTH--) {
      /* CLR ::: Ints Flags */
      SERCOM1_REGS->I2CM.SERCOM_INTFLAG = SERCOM_I2CM_INTFLAG_ERROR(pdSET);

      /* WAT ::: Flag Master on Bus Interrupt */
      while (!(SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_SB(pdSET)) && TIMEOUT--)
        ;

      /* GET ::: Input Buffer */
      *DATA++ = SERCOM1_REGS->I2CM.SERCOM_DATA;

      /* CHK ::: */
      if (LENGTH) {
        /* PUT ::: Stop Signal */
        SERCOM1_REGS->I2CM.SERCOM_CTRLB |= SERCOM_I2CM_CTRLB_CMD(2U);
        while (SERCOM1_REGS->I2CM.SERCOM_SYNCBUSY & SERCOM_I2CM_SYNCBUSY_SYSOP(pdSET))
          ; // Wait Process Complete
      } else
        ;

      /* CHK ::; Flag Error BUS */
      if (SERCOM1_REGS->I2CM.SERCOM_INTFLAG & SERCOM_I2CM_INTFLAG_ERROR(pdSET)) {
        /* GET ::: Error Bus */
        return (xDriver_SAMD_SERCOM1_I2C_GET_ERROR());
      } else
        ;

      /* CLR ::: TIMEOUT */
      TIMEOUT = UINT16_MAX;
    }
  } else {
    /* Return ::: STATUS */
    return (pdCLR);
  }

  /* Return ::: STATUS */
  return (pdSET);
}
