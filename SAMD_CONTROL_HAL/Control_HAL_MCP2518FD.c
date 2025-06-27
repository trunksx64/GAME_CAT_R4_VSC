/* Include ::: Headers :: Origin */
#include "Control_HAL_MCP2518FD.h"
#include "Control_MOD_MCP2518FD_BYTE.h"
#include "Control_MOD_MCP2518FD_WORD.h"

/* Include ::: Header Drivers */
#include "Driver_SAMD_PORT.h"
#include "Driver_SAMD_SERCOM3_SPIM.h"

/******************************************************************************/
/* == Configuration Macros = Defines Controls  == */
/******************************************************************************/
#define vCANFD_MCP2518FD_PUT(D)     vDriver_SAMD_SERCOM3_SPIM_PUT(D)
#define xCANFD_MCP2518FD_GET()      xDriver_SAMD_SERCOM3_SPIM_GET()
#define xCANFD_MCP2518FD_PUTS(D, L) vDriver_SAMD_SERCOM3_SPIM_PUTS(D, L)
#define xCANFD_MCP2518FD_GETS(D, L) vDriver_SAMD_SERCOM3_SPIM_GETS(D, L)

#define vCANFD_MCP2518FD_SS_ENABLE() \
  CANFD_SS_CLR();                    \
  vStorage_DELAY_US(10U)

#define vCANFD_MCP2518FD_SS_DISABLE() \
  vStorage_DELAY_US(10U);             \
  CANFD_SS_SET()

/******************************************************************************/
/* == Configuration Macros = Defines Speed Values  == */
/******************************************************************************/

#define FREQ_NOML_100Khz (uint08_t)(0U) // Speed 100Khz
#define FREQ_NOML_250Khz (uint08_t)(1U) // Speed 250Khz
#define FREQ_NOML_500Khz (uint08_t)(2U) // Speed 500Khz

#define FREQ_DAT_1000Khz (uint08_t)(0U) // Speed 1Mhz
#define FREQ_DAT_2000Khz (uint08_t)(1U) // Speed 2Mhz
#define FREQ_DAT_5000Khz (uint08_t)(2U) // Speed 5Mhz

/* Variables ::: Globales :: Parametros en PROGM :: SYSCLK = 20Mhz -----------*/
const xCAN_Clock_Bus_t CAN_BAUD_NOM[3U] = {
    {.BRP = 9U, .TSEG1 = 10U, .TSEG2 = 5U, .SJW = 3U}, // 100Khz
    {.BRP = 3U, .TSEG1 = 13U, .TSEG2 = 6U, .SJW = 3U}, // 250khz
    {.BRP = 1U, .TSEG1 = 13U, .TSEG2 = 6U, .SJW = 3U}, // 500Khz
};

const xCAN_Clock_Bus_t CAN_BAUD_DAT[3U] = {
    {.BRP = 1U, .TSEG1 = 6U, .TSEG2 = 3U, .SJW = 2U}, // 1Mhz
    {.BRP = 1U, .TSEG1 = 3U, .TSEG2 = 1U, .SJW = 1U}, // 2Mhz
    {.BRP = 0U, .TSEG1 = 2U, .TSEG2 = 1U, .SJW = 1U}, // 5Mhz
};

/******************************************************************************/
/* == Definition ::: Config Macros MCP2518FD Commands == */
/******************************************************************************/
#define CMD_MCP2518FD_RESET      (uint08_t)(0x0) // Resets internal registers to default state; selects Configuration mode
#define CMD_MCP2518FD_READ       (uint08_t)(0x3) // Read SFR/RAM from address A
#define CMD_MCP2518FD_WRITE      (uint08_t)(0x2) // Write SFR/RAM to address A
#define CMD_MCP2518FD_READ_CRC   (uint08_t)(0xB) // Read SFR/RAM from address A. N data bytes. Two bytes CRC, CRC is calculated on C, A, N and D
#define CMD_MCP2518FD_WRITE_CRC  (uint08_t)(0xA) // Write SFR/RAM to address A. N data bytes. Two bytes CRC, CRC is calculated on C, A, N and D
#define CMD_MCP2518FD_WRITE_SAFE (uint08_t)(0xC) // Write SFR/RAM to address A. Check CRC before write. CRC is calculated on C, A and D

const uint16_t CRC16_TABLE[256U] = {0x0000, 0x8005, 0x800F, 0x000A, 0x801B, 0x001E, 0x0014, 0x8011, 0x8033, 0x0036, 0x003C, 0x8039, 0x0028, 0x802D, 0x8027, 0x0022, 0x8063, 0x0066, 0x006C, 0x8069, 0x0078, 0x807D, 0x8077, 0x0072, 0x0050, 0x8055, 0x805F, 0x005A, 0x804B, 0x004E, 0x0044, 0x8041, 0x80C3, 0x00C6, 0x00CC, 0x80C9, 0x00D8,
                                    0x80DD, 0x80D7, 0x00D2, 0x00F0, 0x80F5, 0x80FF, 0x00FA, 0x80EB, 0x00EE, 0x00E4, 0x80E1, 0x00A0, 0x80A5, 0x80AF, 0x00AA, 0x80BB, 0x00BE, 0x00B4, 0x80B1, 0x8093, 0x0096, 0x009C, 0x8099, 0x0088, 0x808D, 0x8087, 0x0082, 0x8183, 0x0186, 0x018C, 0x8189, 0x0198, 0x819D, 0x8197, 0x0192, 0x01B0, 0x81B5,
                                    0x81BF, 0x01BA, 0x81AB, 0x01AE, 0x01A4, 0x81A1, 0x01E0, 0x81E5, 0x81EF, 0x01EA, 0x81FB, 0x01FE, 0x01F4, 0x81F1, 0x81D3, 0x01D6, 0x01DC, 0x81D9, 0x01C8, 0x81CD, 0x81C7, 0x01C2, 0x0140, 0x8145, 0x814F, 0x014A, 0x815B, 0x015E, 0x0154, 0x8151, 0x8173, 0x0176, 0x017C, 0x8179, 0x0168, 0x816D, 0x8167,
                                    0x0162, 0x8123, 0x0126, 0x012C, 0x8129, 0x0138, 0x813D, 0x8137, 0x0132, 0x0110, 0x8115, 0x811F, 0x011A, 0x810B, 0x010E, 0x0104, 0x8101, 0x8303, 0x0306, 0x030C, 0x8309, 0x0318, 0x831D, 0x8317, 0x0312, 0x0330, 0x8335, 0x833F, 0x033A, 0x832B, 0x032E, 0x0324, 0x8321, 0x0360, 0x8365, 0x836F, 0x036A,
                                    0x837B, 0x037E, 0x0374, 0x8371, 0x8353, 0x0356, 0x035C, 0x8359, 0x0348, 0x834D, 0x8347, 0x0342, 0x03C0, 0x83C5, 0x83CF, 0x03CA, 0x83DB, 0x03DE, 0x03D4, 0x83D1, 0x83F3, 0x03F6, 0x03FC, 0x83F9, 0x03E8, 0x83ED, 0x83E7, 0x03E2, 0x83A3, 0x03A6, 0x03AC, 0x83A9, 0x03B8, 0x83BD, 0x83B7, 0x03B2, 0x0390,
                                    0x8395, 0x839F, 0x039A, 0x838B, 0x038E, 0x0384, 0x8381, 0x0280, 0x8285, 0x828F, 0x028A, 0x829B, 0x029E, 0x0294, 0x8291, 0x82B3, 0x02B6, 0x02BC, 0x82B9, 0x02A8, 0x82AD, 0x82A7, 0x02A2, 0x82E3, 0x02E6, 0x02EC, 0x82E9, 0x02F8, 0x82FD, 0x82F7, 0x02F2, 0x02D0, 0x82D5, 0x82DF, 0x02DA, 0x82CB, 0x02CE,
                                    0x02C4, 0x82C1, 0x8243, 0x0246, 0x024C, 0x8249, 0x0258, 0x825D, 0x8257, 0x0252, 0x0270, 0x8275, 0x827F, 0x027A, 0x826B, 0x026E, 0x0264, 0x8261, 0x0220, 0x8225, 0x822F, 0x022A, 0x823B, 0x023E, 0x0234, 0x8231, 0x8213, 0x0216, 0x021C, 0x8219, 0x0208, 0x820D, 0x8207, 0x0202};

/******************************************************************************/
/* == Development Auxiliar Functions == */
/******************************************************************************/

void vAuxliar_MCP2518FD_RESET(void) {
  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Reset */
    vCANFD_MCP2518FD_PUT(CMD_MCP2518FD_RESET << 4U);
    vCANFD_MCP2518FD_PUT(0U);
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();
}

/*----------------------------------------------------------------------------*/

void vAuxliar_MCP2518FD_BUFFER_PUT(uint16_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGHT) {
  /* Check ::: Variables */
  if ((pxBUFFER != NULL) && LENGHT) {
    /* Enable ::: Module CAN */
    vCANFD_MCP2518FD_SS_ENABLE();
    {
      /* Send ::: Command Write */
      vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_WRITE << 4U) | ((ADDRESS >> 8U) & 0x0F));
      vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
      xCANFD_MCP2518FD_PUTS(pxBUFFER, LENGHT);
    }
    /* Disable ::: Module CAN */
    vCANFD_MCP2518FD_SS_DISABLE();
  }
}

void vAuxliar_MCP2518FD_BUFFER_GET(uint16_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGHT) {
  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Read */
    vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_READ << 4U) | ((ADDRESS >> 8U) & 0x0F));
    vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
    xCANFD_MCP2518FD_GETS(pxBUFFER, LENGHT);
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();
}

/*----------------------------------------------------------------------------*/

void vAuxliar_MCP2518FD_BYTE_PUT(uint16_t ADDRESS, uint08_t DATA) {
  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Write */
    vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_WRITE << 4U) | ((ADDRESS >> 8U) & 0x0F));
    vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
    xCANFD_MCP2518FD_PUTS((void *)&DATA, sizeof(DATA));
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();
}

uint08_t xAuxliar_MCP2518FD_BYTE_GET(uint16_t ADDRESS) {
  /* Variables ::: Locals */
  uint08_t DATA = 0U;

  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Read */
    vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_READ << 4U) | ((ADDRESS >> 8U) & 0x0F));
    vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
    xCANFD_MCP2518FD_GETS((void *)&DATA, sizeof(DATA));
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();

  /* Return ::: Data */
  return (DATA);
}

/*----------------------------------------------------------------------------*/

void vAuxliar_MCP2518FD_HALF_WORD_PUT(uint16_t ADDRESS, uint16_t DATA) {
  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Write */
    vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_WRITE << 4U) | ((ADDRESS >> 8U) & 0x0F));
    vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
    xCANFD_MCP2518FD_PUTS((void *)&DATA, sizeof(DATA));
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();
}

uint16_t xAuxliar_MCP2518FD_HALF_WORD_GET(uint16_t ADDRESS) {
  /* Variables ::: Locals */
  uint16_t DATA = 0U;

  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Read */
    vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_READ << 4U) | ((ADDRESS >> 8U) & 0x0F));
    vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
    xCANFD_MCP2518FD_GETS((void *)&DATA, sizeof(DATA));
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();

  /* Return ::: Data */
  return (DATA);
}

/*----------------------------------------------------------------------------*/

void vAuxliar_MCP2518FD_WORD_PUT(uint16_t ADDRESS, uint32_t DATA) {
  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Write */
    vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_WRITE << 4U) | ((ADDRESS >> 8U) & 0x0F));
    vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
    xCANFD_MCP2518FD_PUTS((void *)&DATA, sizeof(DATA));
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();
}

uint32_t xAuxliar_MCP2518FD_WORD_GET(uint16_t ADDRESS) {
  /* Variables ::: Locals */
  uint32_t DATA = 0U;

  /* Enable ::: Module CAN */
  vCANFD_MCP2518FD_SS_ENABLE();
  {
    /* Send ::: Command Read */
    vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_READ << 4U) | ((ADDRESS >> 8U) & 0x0F));
    vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
    xCANFD_MCP2518FD_GETS((void *)&DATA, sizeof(DATA));
  }
  /* Disable ::: Module CAN */
  vCANFD_MCP2518FD_SS_DISABLE();

  /* Return ::: Data */
  return (DATA);
}

void vAuxliar_MCP2518FD_WORD_BIT_MODIFY(uint16_t ADDRESS, uint32_t MASK, uint32_t DATA) {
  /*- Write Register ---------------------------------------------------------*/
  vAuxliar_MCP2518FD_WORD_PUT(ADDRESS, (xAuxliar_MCP2518FD_WORD_GET(ADDRESS) & ~MASK) | (DATA & MASK));
}

/*----------------------------------------------------------------------------*/

uint16_t xAuxiliar_MCP2518FD_CRC16(uint08_t *pxBUFFER, uint16_t LENGTH) {
  /* Local ::: Variables */
  uint08_t INDEX = 0U;
  uint16_t CRC_DAT = UINT16_MAX;

  /* Check ::: Pointer */
  if (pxBUFFER != NULL) {
    /* Loop ::: Full Array */
    while (LENGTH--) {
      INDEX = ((uint8_t *)&CRC_DAT)[1U] ^ *pxBUFFER++;
      CRC_DAT = (CRC_DAT << 8U) ^ CRC16_TABLE[INDEX];
    }
  }

  /* Return ::: CRC_VAL16 */
  return (CRC_DAT);
}

/******************************************************************************/
/* == Development Configuration Functions == */
/******************************************************************************/

void vControl_MCP2518FD_CONFIGURE(void) {
  /* BRK ::: DEBUG */
  pdNOP();

  /* Reseting ::: Command  MCP2515 -------------------------------------------*/

  /* Send ::: Reset Command*/
  vAuxliar_MCP2518FD_RESET();
  /* Delay ::: System */
  vStorage_DELAY_MS(10U);

  /* Setting ::: Configuration IOCON MCP2515 ---------------------------------*/

  /* Configure ::: IOCON Register */
  vAuxliar_MCP2518FD_WORD_PUT(MCP2518FD_WORD_REGS_IOCON, (MCP2518FD_WORD_IOCON_TRIS0_OUT | MCP2518FD_WORD_IOCON_TRIS1_OUT | MCP2518FD_WORD_IOCON_XSTBYEN_DISABLE | MCP2518FD_WORD_IOCON_PM0_IS_GPIO | MCP2518FD_WORD_IOCON_PM1_IS_GPIO));
  /* Enable ::: GPIO CAN LEDS */
  vAuxliar_MCP2518FD_BYTE_PUT(MCP2518FD_BYTE_REGS_IOCON_01, (MCP2518FD_BYTE_IOCON_LAT1_PUT_HIGH | MCP2518FD_BYTE_IOCON_LAT0_PUT_HIGH));

  /*--------------------------------------------------------------------------*/

  /* Set ::: Set Configuration Mode */
  vAuxliar_MCP2518FD_WORD_BIT_MODIFY(MCP2518FD_WORD_REGS_C1CON, MCP2518FD_WORD_C1CON_REQOP_MSK, MCP2518FD_WORD_C1CON_REQOP_CONFIG);
  /* While ::: Set Configuration Mode */
  while ((xAuxliar_MCP2518FD_WORD_GET(MCP2518FD_WORD_REGS_C1CON) & MCP2518FD_WORD_C1CON_REQOP_MSK) != MCP2518FD_WORD_C1CON_REQOP_CONFIG) {}
  {
    /*------------------------------------------------------------------------*/

    /* Write ::: OSC Register */
    vAuxliar_MCP2518FD_WORD_BIT_MODIFY(MCP2518FD_WORD_REGS_OSC, (MCP2518FD_WORD_OSC_SCLKDIV_MSK | MCP2518FD_WORD_OSC_CLKODIV_MSK | MCP2518FD_WORD_OSC_PLLEN_MSK), (MCP2518FD_WORD_OSC_SCLKDIV_DIV1 | MCP2518FD_WORD_OSC_CLKODIV_DIV10 | MCP2518FD_WORD_OSC_PLLEN_SYS_CLK_XTAL));
    /* While ::: PLL Locked */
    while ((xAuxliar_MCP2518FD_WORD_GET(MCP2518FD_WORD_REGS_OSC) & MCP2518FD_WORD_OSC_OSCRDY_MSK) != MCP2518FD_WORD_OSC_OSCRDY_RUNNING) {}

    /*------------------------------------------------------------------------*/

    /* Config ::: Baudrate Nominal & Data  */
    vAuxliar_MCP2518FD_WORD_PUT(MCP2518FD_WORD_REGS_C1NBTCFG, MCP2518FD_WORD_C1DBTCFG_SJW_WRTE(CAN_BAUD_NOM[FREQ_NOML_100Khz].SJW) | MCP2518FD_WORD_C1DBTCFG_TSEG1_WRTE(CAN_BAUD_NOM[FREQ_NOML_100Khz].TSEG1) | MCP2518FD_WORD_C1DBTCFG_TSEG2_WRTE(CAN_BAUD_NOM[FREQ_NOML_100Khz].TSEG2) | MCP2518FD_WORD_C1DBTCFG_BRP_WRTE(CAN_BAUD_NOM[FREQ_NOML_100Khz].BRP));
    vAuxliar_MCP2518FD_WORD_PUT(MCP2518FD_WORD_REGS_C1DBTCFG, MCP2518FD_WORD_C1DBTCFG_SJW_WRTE(CAN_BAUD_DAT[FREQ_DAT_1000Khz].SJW) | MCP2518FD_WORD_C1DBTCFG_TSEG1_WRTE(CAN_BAUD_DAT[FREQ_DAT_1000Khz].TSEG1) | MCP2518FD_WORD_C1DBTCFG_TSEG2_WRTE(CAN_BAUD_DAT[FREQ_DAT_1000Khz].TSEG2) | MCP2518FD_WORD_C1DBTCFG_BRP_WRTE(CAN_BAUD_DAT[FREQ_DAT_1000Khz].BRP));

    /*------------------------------------------------------------------------*/

    /* Enable ::: TX Queue */
    vAuxliar_MCP2518FD_WORD_BIT_MODIFY(MCP2518FD_WORD_REGS_C1CON, MCP2518FD_WORD_C1CON_TXQEN_MSK, MCP2518FD_WORD_C1CON_TXQEN_TXQ_ENABLE);
    /* Configure ::: TX Queue Parameters */

    /*------------------------------------------------------------------------*/
    /*------------------------------------------------------------------------*/
    /*------------------------------------------------------------------------*/
  }
  /* Set ::: Set Configuration Mode */
  vAuxliar_MCP2518FD_WORD_BIT_MODIFY(MCP2518FD_WORD_REGS_C1CON, MCP2518FD_WORD_C1CON_REQOP_MSK, MCP2518FD_WORD_C1CON_REQOP_NORMAL_FD);
  /* While ::: Set Configuration Mode */
  while ((xAuxliar_MCP2518FD_WORD_GET(MCP2518FD_WORD_REGS_C1CON) & MCP2518FD_WORD_C1CON_REQOP_MSK) != MCP2518FD_WORD_C1CON_REQOP_NORMAL_FD) {}
}

void vControl_MCP2518FD_SEND_TXQ_MESSAGE(xCAN_TX_Buffer_Message_t *pxBUFFER) {
  /* Check ::: Buffer is not Zero */
  if (pxBUFFER) {
    /* Check ::: Message Transmit Request */
    if (xAuxliar_MCP2518FD_WORD_GET(MCP2518FD_WORD_REGS_C1CON)) {}
  }
}