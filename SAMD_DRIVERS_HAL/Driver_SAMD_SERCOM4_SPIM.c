/* Include ::: Header File Source */
#include "Driver_SAMD_SERCOM4_SPIM.h"
/* Driver ::: Configuration */
#include "Driver_SAMD_GCLK.h"

/******************************************************************************/
/* == Development Configuration Hardware SAMC :: SERCOM SPI == */
/******************************************************************************/

/* Function ::: Configure */
void vDriver_SAMD_SERCOM4_SPIM_CONFIGURE(void) {
  /* BRK ::: DEBUG */
  pdNOP();

  /*------------------------------------------------------------------------*/

  /* Enable ::: Device */
  PM_REGS->PM_APBCMASK |= PM_APBCMASK_SERCOM4(pdSET); // SERCOM4 APBC Mask Clock Enable

  /* Set Source Main Clock */
  GCLK_REGS->GCLK_CLKCTRL = (GCLK_CLKCTRL_ID_SERCOM4_CORE | // Generic Clock Selection ID
                             GCLK_CLKCTRL_GEN_GCLK3 |       // Generic Clock Generator
                             GCLK_CLKCTRL_CLKEN(pdSET) |    // Clock Enable
                             GCLK_CLKCTRL_WRTLOCK(pdCLR));  // Write Lock
  /* While ::: Sync */
  while (GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY(pdSET))
    ;

  /*------------------------------------------------------------------------*/

  /* Configuration SERCOM4 (SPI) ------------------------------------------ */
  SERCOM4_REGS->SPIM.SERCOM_CTRLA |= SERCOM_SPIM_CTRLA_SWRST(pdSET); // Reset Module for Configuration
  while (SERCOM4_REGS->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_SWRST(pdSET))
    ; // Wait Process Complete

  /* Configuration ::: SERCOM4 (SPI) :: CTRLA ----------------------------- */
  SERCOM4_REGS->SPIM.SERCOM_CTRLA = (SERCOM_SPIM_CTRLA_DORD_MSB |          // LSB is transmitted first Position
                                     SERCOM_SPIM_CTRLA_CPOL_IDLE_LOW |     // SCK is Low when idle
                                     SERCOM_SPIM_CTRLA_CPHA_LEADING_EDGE | // The data is sampled on a leading SCK edge and changed on a trailing SCK edge Position
                                     SERCOM_SPIM_CTRLA_FORM_SPI_FRAME |    // SPI frame
                                     SERCOM_SPIM_CTRLA_DIPO_PAD3 |         // SERCOM PAD[3] is used as data input
                                     SERCOM_SPIM_CTRLA_DOPO_PAD0 |         // SERCOM PAD[0][1] is used as data output
                                     SERCOM_SPIM_CTRLA_IBON(pdCLR) |       // Immediate Buffer Overflow Notification
                                     SERCOM_SPIM_CTRLA_RUNSTDBY(pdCLR) |   // Disabled. All reception is dropped, including the ongoing transaction.
                                     SERCOM_SPIM_CTRLA_MODE_SPI_MASTER);   // SPI master operation

  /* Configuration ::: SERCOM4 (SPI) :: CTRLB ----------------------------- */
  SERCOM4_REGS->SPIM.SERCOM_CTRLB = (SERCOM_SPIM_CTRLB_RXEN(pdSET) |    // The receiver is enabled or it will be enabled when SPI is enabled.
                                     SERCOM_SPIM_CTRLB_AMODE_MASK |     // ADDRMASK is used as a mask to the ADDR register.
                                     SERCOM_SPIM_CTRLB_MSSEN(pdCLR) |   // SS low detector is disabled.
                                     SERCOM_SPIM_CTRLB_SSDE(pdCLR) |    // SS low detector is disabled.
                                     SERCOM_SPIM_CTRLB_PLOADEN(pdCLR) | // Slave Data Preload Enable
                                     SERCOM_SPIM_CTRLB_CHSIZE_8_BIT);   // 8 bits

  while (SERCOM4_REGS->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_CTRLB(pdSET))
    ; // Wait Process Complete

  /* Configuration ::: SERCOM4 (SPI) :: BAUD ------------------------------ */
  SERCOM4_REGS->SPIM.SERCOM_BAUD = SERCOM_SPIM_BAUD_BAUD(SERCOM4_SPI_BAUD_RATE_CALC(configGCLK3_24MHZ, SERCOM4_SPI_BAUD_RATE)); // ((F_Clock/(2*F_Baud))-1)

  /* Configuration ::: SERCOM4 (SPI) :: CTRLA ----------------------------- */
  SERCOM4_REGS->SPIM.SERCOM_CTRLA |= SERCOM_SPIM_CTRLA_ENABLE(pdSET); // Enable SPI
  while (SERCOM4_REGS->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_ENABLE(pdSET))
    ; // Wait Process Complete

#if __DEBUG
  /* Configuration ::: SERCOM4 (SPI) :: DBGCTRL --------------------------- */
  SERCOM4_REGS->SPIM.SERCOM_DBGCTRL = SERCOM_SPIM_DBGCTRL_DBGSTOP(pdSET);
#endif

  /*------------------------------------------------------------------------*/

  /* Configuration ::: SERCOM4 (SPI) :: INTENSET & INTENCLR --------------- */
  SERCOM4_REGS->SPIM.SERCOM_INTENCLR = SERCOM_SPIM_INTENSET_TXC(pdSET);   // Interruption Send Complete
  SERCOM4_REGS->SPIM.SERCOM_INTENCLR = SERCOM_SPIM_INTENSET_RXC(pdSET);   // Interruption Receive Complete
  SERCOM4_REGS->SPIM.SERCOM_INTENCLR = SERCOM_SPIM_INTENSET_SSL(pdSET);   // Interruption Select Slave
  SERCOM4_REGS->SPIM.SERCOM_INTENCLR = SERCOM_SPIM_INTENSET_DRE(pdSET);   // Interruption Empty Buffer
  SERCOM4_REGS->SPIM.SERCOM_INTENCLR = SERCOM_SPIM_INTENSET_ERROR(pdSET); // Interruption Error Data

  /* Configuration ::: SERCOM4 (SPI) :: NVIC Interruption ----------------- */
  NVIC_ClearPendingIRQ(SERCOM4_IRQn); // Clear Pending Interruptions
  NVIC_DisableIRQ(SERCOM4_IRQn);      // Disable Vector Interruption
}

void vDriver_SAMD_SERCOM4_SPIM_PUT(uint16_t DATA) {
  /* Local ::: Variables */
  uint08_t DUMMY = 0U;

  /*------------------------------------------------------------------------*/

  /* GET ::: Dummy Data Buffer */
  DUMMY = SERCOM4_REGS->SPIM.SERCOM_DATA;
  /* Stop :: Warning Message */
  (void)DUMMY;

  /*------------------------------------------------------------------------*/

  /* CHK ::: Empty Buffer Data SPI */
  while (!(SERCOM4_REGS->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_DRE(pdSET)))
    ;
  /* PUT ::: Buffer Data SPI */
  SERCOM4_REGS->SPIM.SERCOM_DATA = DATA;
  /* CHK ::: Empty Buffer Data SPI */
  while (!(SERCOM4_REGS->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_TXC(pdSET)))
    ;
}

uint16_t xDriver_SAMD_SERCOM4_SPIM_GET(void) {
  /* Local ::: Variables */
  uint08_t DATA = 0U;

  /*------------------------------------------------------------------------*/

  /* GET ::: Dummy Data Buffer */
  DATA = SERCOM4_REGS->SPIM.SERCOM_DATA;
  /* CHK ::: Empty Buffer Data SPI */
  while (!(SERCOM4_REGS->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_DRE(pdSET)))
    ;

  /*------------------------------------------------------------------------*/

  /* PUT Dummy ::: Buffer Data SPI */
  SERCOM4_REGS->SPIM.SERCOM_DATA = 0xAA;
  /* CHK ::: Empty Buffer Data SPI */
  while (!(SERCOM4_REGS->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_RXC(pdSET)))
    ;

  /*------------------------------------------------------------------------*/

  /* GET ::: Data Buffer */
  DATA = SERCOM4_REGS->SPIM.SERCOM_DATA;
  /* CHK ::: Empty Buffer Data SPI */
  while (!(SERCOM4_REGS->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_TXC(pdSET)))
    ;

  /*------------------------------------------------------------------------*/

  /* Return ::: Data */
  return (DATA);
}

void vDriver_SAMD_SERCOM4_SPIM_PUTS(uint08_t *BUFFER, uint08_t LENGTH) {
  /* CHK ::: Buffer */
  if (BUFFER) {
    /* CHK ::: Empty Buffer */
    while (LENGTH--) {
      /* PUT ::: Buffer Data */
      vDriver_SAMD_SERCOM4_SPIM_PUT(*BUFFER++);
    }
  }
}

void vDriver_SAMD_SERCOM4_SPIM_GETS(uint08_t *BUFFER, uint08_t LENGTH) {
  /* CHK ::: Buffer */
  if (BUFFER) {
    /* CHK :: Buffer Full */
    while (LENGTH--) {
      /* Receive :::: Data in Buffer */
      *BUFFER++ = xDriver_SAMD_SERCOM4_SPIM_GET();
    }
  }
}
