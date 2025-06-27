#ifndef CONTROL_MOD_MCP2518FD_BYTE_H
#define CONTROL_MOD_MCP2518FD_BYTE_H

/******************************************************************************/
/* == Definition ::: Config Macros :: MCP2518FD_BYTE REGISTER SUMMARY 8bits == */
/******************************************************************************/
#define MCP2518FD_BYTE_REGS_OSC_00                    (uint16_t)(0xE00) // OSCILLATOR REGISTER
#define MCP2518FD_BYTE_REGS_OSC_01                    (uint16_t)(0xE01)
#define MCP2518FD_BYTE_REGS_OSC_02                    (uint16_t)(0xE02)
#define MCP2518FD_BYTE_REGS_OSC_03                    (uint16_t)(0xE03)

#define MCP2518FD_BYTE_REGS_IOCON_00                  (uint16_t)(0xE04) // IOCON REGISTER
#define MCP2518FD_BYTE_REGS_IOCON_01                  (uint16_t)(0xE05)
#define MCP2518FD_BYTE_REGS_IOCON_02                  (uint16_t)(0xE06)
#define MCP2518FD_BYTE_REGS_IOCON_03                  (uint16_t)(0xE07)

#define MCP2518FD_BYTE_REGS_CRC_00                    (uint16_t)(0xE08) // CRC REGISTER
#define MCP2518FD_BYTE_REGS_CRC_01                    (uint16_t)(0xE09)
#define MCP2518FD_BYTE_REGS_CRC_02                    (uint16_t)(0xE0A)
#define MCP2518FD_BYTE_REGS_CRC_03                    (uint16_t)(0xE0B)

#define MCP2518FD_BYTE_REGS_ECCCON_00                 (uint16_t)(0xE0C) // ECCCON REGISTER
#define MCP2518FD_BYTE_REGS_ECCCON_01                 (uint16_t)(0xE0D)
#define MCP2518FD_BYTE_REGS_ECCCON_02                 (uint16_t)(0xE0E)
#define MCP2518FD_BYTE_REGS_ECCCON_03                 (uint16_t)(0xE0F)

#define MCP2518FD_BYTE_REGS_ECCSTAT_00                (uint16_t)(0xE10) // ECCSTAT REGISTER
#define MCP2518FD_BYTE_REGS_ECCSTAT_01                (uint16_t)(0xE11)
#define MCP2518FD_BYTE_REGS_ECCSTAT_02                (uint16_t)(0xE12)
#define MCP2518FD_BYTE_REGS_ECCSTAT_03                (uint16_t)(0xE14)

#define MCP2518FD_BYTE_REGS_DEVID_00                  (uint16_t)(0xE10) // DEVID REGISTER
#define MCP2518FD_BYTE_REGS_DEVID_01                  (uint16_t)(0xE11)
#define MCP2518FD_BYTE_REGS_DEVID_02                  (uint16_t)(0xE12)
#define MCP2518FD_BYTE_REGS_DEVID_03                  (uint16_t)(0xE14)

/******************************************************************************/
/* == Definition ::: Config Macros :: MCP2518FD_BYTE CTRL MODULE REG 8Bits  == */
/******************************************************************************/
#define MCP2518FD_BYTE_REGS_C1CON_00                  (uint16_t)(0x000) // C1CON REGISTER
#define MCP2518FD_BYTE_REGS_C1CON_01                  (uint16_t)(0x001)
#define MCP2518FD_BYTE_REGS_C1CON_02                  (uint16_t)(0x002)
#define MCP2518FD_BYTE_REGS_C1CON_03                  (uint16_t)(0x003)

#define MCP2518FD_BYTE_REGS_C1NBTCFG_00               (uint16_t)(0x004) // C1NBTCFG REGISTER
#define MCP2518FD_BYTE_REGS_C1NBTCFG_01               (uint16_t)(0x005)
#define MCP2518FD_BYTE_REGS_C1NBTCFG_02               (uint16_t)(0x006)
#define MCP2518FD_BYTE_REGS_C1NBTCFG_03               (uint16_t)(0x007)

#define MCP2518FD_BYTE_REGS_C1DBTCFG_00               (uint16_t)(0x008) // C1DBTCFG REGISTER
#define MCP2518FD_BYTE_REGS_C1DBTCFG_01               (uint16_t)(0x009)
#define MCP2518FD_BYTE_REGS_C1DBTCFG_02               (uint16_t)(0x00A)
#define MCP2518FD_BYTE_REGS_C1DBTCFG_03               (uint16_t)(0x00B)

#define MCP2518FD_BYTE_REGS_C1TDC_00                  (uint16_t)(0x00C) // C1TDC REGISTER
#define MCP2518FD_BYTE_REGS_C1TDC_01                  (uint16_t)(0x00D)
#define MCP2518FD_BYTE_REGS_C1TDC_02                  (uint16_t)(0x00E)
#define MCP2518FD_BYTE_REGS_C1TDC_03                  (uint16_t)(0x00F)

#define MCP2518FD_BYTE_REGS_C1TBC_00                  (uint16_t)(0x010) // C1TBC REGISTER
#define MCP2518FD_BYTE_REGS_C1TBC_01                  (uint16_t)(0x011)
#define MCP2518FD_BYTE_REGS_C1TBC_02                  (uint16_t)(0x012)
#define MCP2518FD_BYTE_REGS_C1TBC_03                  (uint16_t)(0x013)

#define MCP2518FD_BYTE_REGS_C1TSCON_00                (uint16_t)(0x014) // C1TSCON REGISTER
#define MCP2518FD_BYTE_REGS_C1TSCON_01                (uint16_t)(0x015)
#define MCP2518FD_BYTE_REGS_C1TSCON_02                (uint16_t)(0x016)
#define MCP2518FD_BYTE_REGS_C1TSCON_03                (uint16_t)(0x017)

#define MCP2518FD_BYTE_REGS_C1VEC_00                  (uint16_t)(0x018) // C1VEC REGISTER
#define MCP2518FD_BYTE_REGS_C1VEC_01                  (uint16_t)(0x019)
#define MCP2518FD_BYTE_REGS_C1VEC_02                  (uint16_t)(0x01A)
#define MCP2518FD_BYTE_REGS_C1VEC_03                  (uint16_t)(0x01B)

#define MCP2518FD_BYTE_REGS_C1INT_00                  (uint16_t)(0x01C) // C1INT REGISTER
#define MCP2518FD_BYTE_REGS_C1INT_01                  (uint16_t)(0x01D)
#define MCP2518FD_BYTE_REGS_C1INT_02                  (uint16_t)(0x01E)
#define MCP2518FD_BYTE_REGS_C1INT_03                  (uint16_t)(0x01F)

#define MCP2518FD_BYTE_REGS_C1RXIF_00                 (uint16_t)(0x020) // C1RXIF REGISTER
#define MCP2518FD_BYTE_REGS_C1RXIF_01                 (uint16_t)(0x021)
#define MCP2518FD_BYTE_REGS_C1RXIF_02                 (uint16_t)(0x022)
#define MCP2518FD_BYTE_REGS_C1RXIF_03                 (uint16_t)(0x023)

#define MCP2518FD_BYTE_REGS_C1TXIF_00                 (uint16_t)(0x024) // C1TXIF REGISTER
#define MCP2518FD_BYTE_REGS_C1TXIF_01                 (uint16_t)(0x025)
#define MCP2518FD_BYTE_REGS_C1TXIF_02                 (uint16_t)(0x026)
#define MCP2518FD_BYTE_REGS_C1TXIF_03                 (uint16_t)(0x027)

#define MCP2518FD_BYTE_REGS_C1RXOVIF_00               (uint16_t)(0x028) // C1RXOVIF REGISTER
#define MCP2518FD_BYTE_REGS_C1RXOVIF_01               (uint16_t)(0x029)
#define MCP2518FD_BYTE_REGS_C1RXOVIF_02               (uint16_t)(0x02A)
#define MCP2518FD_BYTE_REGS_C1RXOVIF_03               (uint16_t)(0x02B)

#define MCP2518FD_BYTE_REGS_C1TXATIF_00               (uint16_t)(0x02C) // C1TXATIF REGISTER
#define MCP2518FD_BYTE_REGS_C1TXATIF_01               (uint16_t)(0x02D)
#define MCP2518FD_BYTE_REGS_C1TXATIF_02               (uint16_t)(0x02E)
#define MCP2518FD_BYTE_REGS_C1TXATIF_03               (uint16_t)(0x02F)

#define MCP2518FD_BYTE_REGS_C1TXREQ_00                (uint16_t)(0x030) // C1TXREQ REGISTER
#define MCP2518FD_BYTE_REGS_C1TXREQ_01                (uint16_t)(0x031)
#define MCP2518FD_BYTE_REGS_C1TXREQ_02                (uint16_t)(0x032)
#define MCP2518FD_BYTE_REGS_C1TXREQ_03                (uint16_t)(0x033)

#define MCP2518FD_BYTE_REGS_C1TREC_00                 (uint16_t)(0x034) // C1TREC REGISTER
#define MCP2518FD_BYTE_REGS_C1TREC_01                 (uint16_t)(0x035)
#define MCP2518FD_BYTE_REGS_C1TREC_02                 (uint16_t)(0x036)
#define MCP2518FD_BYTE_REGS_C1TREC_03                 (uint16_t)(0x037)

#define MCP2518FD_BYTE_REGS_C1BDIAG0_00               (uint16_t)(0x038) // C1BDIAG0 REGISTER
#define MCP2518FD_BYTE_REGS_C1BDIAG0_01               (uint16_t)(0x039)
#define MCP2518FD_BYTE_REGS_C1BDIAG0_02               (uint16_t)(0x03A)
#define MCP2518FD_BYTE_REGS_C1BDIAG0_03               (uint16_t)(0x03B)

#define MCP2518FD_BYTE_REGS_C1BDIAG1_00               (uint16_t)(0x03C) // C1BDIAG1 REGISTER
#define MCP2518FD_BYTE_REGS_C1BDIAG1_01               (uint16_t)(0x03D)
#define MCP2518FD_BYTE_REGS_C1BDIAG1_02               (uint16_t)(0x03E)
#define MCP2518FD_BYTE_REGS_C1BDIAG1_03               (uint16_t)(0x03F)

#define MCP2518FD_BYTE_REGS_C1TEFCON_00               (uint16_t)(0x040) // C1TEFCON REGISTER
#define MCP2518FD_BYTE_REGS_C1TEFCON_01               (uint16_t)(0x041)
#define MCP2518FD_BYTE_REGS_C1TEFCON_02               (uint16_t)(0x042)
#define MCP2518FD_BYTE_REGS_C1TEFCON_03               (uint16_t)(0x043)

#define MCP2518FD_BYTE_REGS_C1TEFSTA_00               (uint16_t)(0x044) // C1TEFSTA REGISTER
#define MCP2518FD_BYTE_REGS_C1TEFSTA_01               (uint16_t)(0x045)
#define MCP2518FD_BYTE_REGS_C1TEFSTA_02               (uint16_t)(0x046)
#define MCP2518FD_BYTE_REGS_C1TEFSTA_03               (uint16_t)(0x047)

#define MCP2518FD_BYTE_REGS_C1TEFUA_00                (uint16_t)(0x048) // C1TEFUA REGISTER
#define MCP2518FD_BYTE_REGS_C1TEFUA_01                (uint16_t)(0x049)
#define MCP2518FD_BYTE_REGS_C1TEFUA_02                (uint16_t)(0x04A)
#define MCP2518FD_BYTE_REGS_C1TEFUA_03                (uint16_t)(0x04B)

#define MCP2518FD_BYTE_REGS_C1TXQCON_00               (uint16_t)(0x050) // C1TXQCON REGISTER
#define MCP2518FD_BYTE_REGS_C1TXQCON_01               (uint16_t)(0x051)
#define MCP2518FD_BYTE_REGS_C1TXQCON_02               (uint16_t)(0x052)
#define MCP2518FD_BYTE_REGS_C1TXQCON_03               (uint16_t)(0x053)

#define MCP2518FD_BYTE_REGS_C1TXQSTA_00               (uint16_t)(0x054) // C1TXQSTA REGISTER
#define MCP2518FD_BYTE_REGS_C1TXQSTA_01               (uint16_t)(0x055)
#define MCP2518FD_BYTE_REGS_C1TXQSTA_02               (uint16_t)(0x056)
#define MCP2518FD_BYTE_REGS_C1TXQSTA_03               (uint16_t)(0x057)

#define MCP2518FD_BYTE_REGS_C1TXQUA_00                (uint16_t)(0x058) // C1TXQUA REGISTER
#define MCP2518FD_BYTE_REGS_C1TXQUA_01                (uint16_t)(0x059)
#define MCP2518FD_BYTE_REGS_C1TXQUA_02                (uint16_t)(0x05A)
#define MCP2518FD_BYTE_REGS_C1TXQUA_03                (uint16_t)(0x05B)

#define MCP2518FD_BYTE_REGS_C1FIFOCON1_00             (uint16_t)(0x05C) // C1FIFOCON1 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON1_01             (uint16_t)(0x05D)
#define MCP2518FD_BYTE_REGS_C1FIFOCON1_02             (uint16_t)(0x05E)
#define MCP2518FD_BYTE_REGS_C1FIFOCON1_03             (uint16_t)(0x05F)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA1_00             (uint16_t)(0x060) // C1FIFOSTA1 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA1_01             (uint16_t)(0x061)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA1_02             (uint16_t)(0x062)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA1_03             (uint16_t)(0x063)

#define MCP2518FD_BYTE_REGS_C1FIFOUA1_00              (uint16_t)(0x064) // C1FIFOUA1 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA1_01              (uint16_t)(0x065)
#define MCP2518FD_BYTE_REGS_C1FIFOUA1_02              (uint16_t)(0x066)
#define MCP2518FD_BYTE_REGS_C1FIFOUA1_03              (uint16_t)(0x067)

#define MCP2518FD_BYTE_REGS_C1FIFOCON2_00             (uint16_t)(0x068) // C1FIFOCON2 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON2_01             (uint16_t)(0x069)
#define MCP2518FD_BYTE_REGS_C1FIFOCON2_02             (uint16_t)(0x06A)
#define MCP2518FD_BYTE_REGS_C1FIFOCON2_03             (uint16_t)(0x06B)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA2_00             (uint16_t)(0x06C) // C1FIFOSTA2 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA2_01             (uint16_t)(0x06D)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA2_02             (uint16_t)(0x06E)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA2_03             (uint16_t)(0x06F)

#define MCP2518FD_BYTE_REGS_C1FIFOUA2_00              (uint16_t)(0x070) // C1FIFOUA2 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA2_01              (uint16_t)(0x071)
#define MCP2518FD_BYTE_REGS_C1FIFOUA2_02              (uint16_t)(0x072)
#define MCP2518FD_BYTE_REGS_C1FIFOUA2_03              (uint16_t)(0x073)

#define MCP2518FD_BYTE_REGS_C1FIFOCON3_00             (uint16_t)(0x074) // C1FIFOCON3 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON3_01             (uint16_t)(0x075)
#define MCP2518FD_BYTE_REGS_C1FIFOCON3_02             (uint16_t)(0x076)
#define MCP2518FD_BYTE_REGS_C1FIFOCON3_03             (uint16_t)(0x077)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA3_00             (uint16_t)(0x078) // C1FIFOSTA3 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA3_01             (uint16_t)(0x079)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA3_02             (uint16_t)(0x07A)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA3_03             (uint16_t)(0x07B)

#define MCP2518FD_BYTE_REGS_C1FIFOUA3_00              (uint16_t)(0x07C) // C1FIFOUA3 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA3_01              (uint16_t)(0x07D)
#define MCP2518FD_BYTE_REGS_C1FIFOUA3_02              (uint16_t)(0x07E)
#define MCP2518FD_BYTE_REGS_C1FIFOUA3_03              (uint16_t)(0x07F)

#define MCP2518FD_BYTE_REGS_C1FIFOCON4_00             (uint16_t)(0x080) // C1FIFOCON4 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON4_01             (uint16_t)(0x081)
#define MCP2518FD_BYTE_REGS_C1FIFOCON4_02             (uint16_t)(0x082)
#define MCP2518FD_BYTE_REGS_C1FIFOCON4_03             (uint16_t)(0x083)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA4_00             (uint16_t)(0x084) // C1FIFOSTA4 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA4_01             (uint16_t)(0x085)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA4_02             (uint16_t)(0x086)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA4_03             (uint16_t)(0x087)

#define MCP2518FD_BYTE_REGS_C1FIFOUA4_00              (uint16_t)(0x088) // C1FIFOUA4 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA4_01              (uint16_t)(0x089)
#define MCP2518FD_BYTE_REGS_C1FIFOUA4_02              (uint16_t)(0x08A)
#define MCP2518FD_BYTE_REGS_C1FIFOUA4_03              (uint16_t)(0x08B)

#define MCP2518FD_BYTE_REGS_C1FIFOCON5_00             (uint16_t)(0x08C) // C1FIFOCON5 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON5_01             (uint16_t)(0x08D)
#define MCP2518FD_BYTE_REGS_C1FIFOCON5_02             (uint16_t)(0x08E)
#define MCP2518FD_BYTE_REGS_C1FIFOCON5_03             (uint16_t)(0x08F)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA5_00             (uint16_t)(0x090) // C1FIFOSTA5 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA5_01             (uint16_t)(0x091)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA5_02             (uint16_t)(0x092)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA5_03             (uint16_t)(0x093)

#define MCP2518FD_BYTE_REGS_C1FIFOUA5_00              (uint16_t)(0x094) // C1FIFOUA5 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA5_01              (uint16_t)(0x095)
#define MCP2518FD_BYTE_REGS_C1FIFOUA5_02              (uint16_t)(0x096)
#define MCP2518FD_BYTE_REGS_C1FIFOUA5_03              (uint16_t)(0x097)

#define MCP2518FD_BYTE_REGS_C1FIFOCON6_00             (uint16_t)(0x098) // C1FIFOCON6 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON6_01             (uint16_t)(0x099)
#define MCP2518FD_BYTE_REGS_C1FIFOCON6_02             (uint16_t)(0x09A)
#define MCP2518FD_BYTE_REGS_C1FIFOCON6_03             (uint16_t)(0x09B)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA6_00             (uint16_t)(0x09C) // C1FIFOSTA6 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA6_01             (uint16_t)(0x09D)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA6_02             (uint16_t)(0x09E)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA6_03             (uint16_t)(0x09F)

#define MCP2518FD_BYTE_REGS_C1FIFOUA6_00              (uint16_t)(0x0A0) // C1FIFOUA6 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA6_01              (uint16_t)(0x0A1)
#define MCP2518FD_BYTE_REGS_C1FIFOUA6_02              (uint16_t)(0x0A2)
#define MCP2518FD_BYTE_REGS_C1FIFOUA6_03              (uint16_t)(0x0A3)

#define MCP2518FD_BYTE_REGS_C1FIFOCON7_00             (uint16_t)(0x0A4) // C1FIFOCON7 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON7_01             (uint16_t)(0x0A5)
#define MCP2518FD_BYTE_REGS_C1FIFOCON7_02             (uint16_t)(0x0A6)
#define MCP2518FD_BYTE_REGS_C1FIFOCON7_03             (uint16_t)(0x0A7)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA7_00             (uint16_t)(0x0A8) // C1FIFOSTA7 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA7_01             (uint16_t)(0x0A9)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA7_02             (uint16_t)(0x0AA)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA7_03             (uint16_t)(0x0AB)

#define MCP2518FD_BYTE_REGS_C1FIFOUA7_00              (uint16_t)(0x0AC) // C1FIFOUA7 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA7_01              (uint16_t)(0x0AD)
#define MCP2518FD_BYTE_REGS_C1FIFOUA7_02              (uint16_t)(0x0AE)
#define MCP2518FD_BYTE_REGS_C1FIFOUA7_03              (uint16_t)(0x0AF)

#define MCP2518FD_BYTE_REGS_C1FIFOCON8_00             (uint16_t)(0x0B0) // C1FIFOCON8 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON8_01             (uint16_t)(0x0B1)
#define MCP2518FD_BYTE_REGS_C1FIFOCON8_02             (uint16_t)(0x0B1)
#define MCP2518FD_BYTE_REGS_C1FIFOCON8_03             (uint16_t)(0x0B3)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA8_00             (uint16_t)(0x0B4) // C1FIFOSTA8 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA8_01             (uint16_t)(0x0B5)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA8_02             (uint16_t)(0x0B6)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA8_03             (uint16_t)(0x0B7)

#define MCP2518FD_BYTE_REGS_C1FIFOUA8_00              (uint16_t)(0x0B8) // C1FIFOUA8 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA8_01              (uint16_t)(0x0B0)
#define MCP2518FD_BYTE_REGS_C1FIFOUA8_02              (uint16_t)(0x0BA)
#define MCP2518FD_BYTE_REGS_C1FIFOUA8_03              (uint16_t)(0x0BB)

#define MCP2518FD_BYTE_REGS_C1FIFOCON9_00             (uint16_t)(0x0BC) // C1FIFOCON9 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON9_01             (uint16_t)(0x0BD)
#define MCP2518FD_BYTE_REGS_C1FIFOCON9_02             (uint16_t)(0x0BE)
#define MCP2518FD_BYTE_REGS_C1FIFOCON9_03             (uint16_t)(0x0BF)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA9_00             (uint16_t)(0x0C0) // C1FIFOSTA9 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA9_01             (uint16_t)(0x0C1)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA9_02             (uint16_t)(0x0C2)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA9_03             (uint16_t)(0x0C3)

#define MCP2518FD_BYTE_REGS_C1FIFOUA9_00              (uint16_t)(0x0C4) // C1FIFOUA9 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA9_01              (uint16_t)(0x0C5)
#define MCP2518FD_BYTE_REGS_C1FIFOUA9_02              (uint16_t)(0x0C6)
#define MCP2518FD_BYTE_REGS_C1FIFOUA9_03              (uint16_t)(0x0C7)

#define MCP2518FD_BYTE_REGS_C1FIFOCON10_00            (uint16_t)(0x0C8) // C1FIFOCON10 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON10_01            (uint16_t)(0x0C9)
#define MCP2518FD_BYTE_REGS_C1FIFOCON10_02            (uint16_t)(0x0CA)
#define MCP2518FD_BYTE_REGS_C1FIFOCON10_03            (uint16_t)(0x0CB)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA10_00            (uint16_t)(0x0CC) // C1FIFOSTA10 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA10_01            (uint16_t)(0x0CD)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA10_02            (uint16_t)(0x0CE)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA10_03            (uint16_t)(0x0CF)

#define MCP2518FD_BYTE_REGS_C1FIFOUA10_00             (uint16_t)(0x0D0) // C1FIFOUA10 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA10_01             (uint16_t)(0x0D1)
#define MCP2518FD_BYTE_REGS_C1FIFOUA10_02             (uint16_t)(0x0D2)
#define MCP2518FD_BYTE_REGS_C1FIFOUA10_03             (uint16_t)(0x0D3)

#define MCP2518FD_BYTE_REGS_C1FIFOCON11_00            (uint16_t)(0x0D4) // C1FIFOCON11 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON11_01            (uint16_t)(0x0D5)
#define MCP2518FD_BYTE_REGS_C1FIFOCON11_02            (uint16_t)(0x0D6)
#define MCP2518FD_BYTE_REGS_C1FIFOCON11_03            (uint16_t)(0x0D7)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA11_00            (uint16_t)(0x0D8) // C1FIFOSTA11 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA11_01            (uint16_t)(0x0D9)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA11_02            (uint16_t)(0x0DA)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA11_03            (uint16_t)(0x0DB)

#define MCP2518FD_BYTE_REGS_C1FIFOUA11_00             (uint16_t)(0x0DC) // C1FIFOUA11 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA11_01             (uint16_t)(0x0DD)
#define MCP2518FD_BYTE_REGS_C1FIFOUA11_02             (uint16_t)(0x0DE)
#define MCP2518FD_BYTE_REGS_C1FIFOUA11_03             (uint16_t)(0x0DF)

#define MCP2518FD_BYTE_REGS_C1FIFOCON12_00            (uint16_t)(0x0E0) // C1FIFOCON12 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON12_01            (uint16_t)(0x0E1)
#define MCP2518FD_BYTE_REGS_C1FIFOCON12_02            (uint16_t)(0x0E2)
#define MCP2518FD_BYTE_REGS_C1FIFOCON12_03            (uint16_t)(0x0E3)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA12_00            (uint16_t)(0x0E4) // C1FIFOSTA12 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA12_01            (uint16_t)(0x0E5)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA12_02            (uint16_t)(0x0E6)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA12_03            (uint16_t)(0x0E7)

#define MCP2518FD_BYTE_REGS_C1FIFOUA12_00             (uint16_t)(0x0E8) // C1FIFOUA12 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA12_01             (uint16_t)(0x0E9)
#define MCP2518FD_BYTE_REGS_C1FIFOUA12_02             (uint16_t)(0x0EA)
#define MCP2518FD_BYTE_REGS_C1FIFOUA12_03             (uint16_t)(0x0EB)

#define MCP2518FD_BYTE_REGS_C1FIFOCON13_00            (uint16_t)(0x0EC) // C1FIFOCON13 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON13_01            (uint16_t)(0x0ED)
#define MCP2518FD_BYTE_REGS_C1FIFOCON13_02            (uint16_t)(0x0EE)
#define MCP2518FD_BYTE_REGS_C1FIFOCON13_03            (uint16_t)(0x0EF)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA13_00            (uint16_t)(0x0F0) // C1FIFOSTA13 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA13_01            (uint16_t)(0x0F1)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA13_02            (uint16_t)(0x0F2)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA13_03            (uint16_t)(0x0F3)

#define MCP2518FD_BYTE_REGS_C1FIFOUA13_00             (uint16_t)(0x0F4) // C1FIFOUA13 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA13_01             (uint16_t)(0x0F5)
#define MCP2518FD_BYTE_REGS_C1FIFOUA13_02             (uint16_t)(0x0F6)
#define MCP2518FD_BYTE_REGS_C1FIFOUA13_03             (uint16_t)(0x0F7)

#define MCP2518FD_BYTE_REGS_C1FIFOCON14_00            (uint16_t)(0x0F8) // C1FIFOCON14 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON14_01            (uint16_t)(0x0F9)
#define MCP2518FD_BYTE_REGS_C1FIFOCON14_02            (uint16_t)(0x0FA)
#define MCP2518FD_BYTE_REGS_C1FIFOCON14_03            (uint16_t)(0x0FB)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA14_00            (uint16_t)(0x0FC) // C1FIFOSTA14 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA14_01            (uint16_t)(0x0FD)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA14_02            (uint16_t)(0x0FE)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA14_03            (uint16_t)(0x0FF)

#define MCP2518FD_BYTE_REGS_C1FIFOUA14_00             (uint16_t)(0x100) // C1FIFOUA14 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA14_01             (uint16_t)(0x101)
#define MCP2518FD_BYTE_REGS_C1FIFOUA14_02             (uint16_t)(0x102)
#define MCP2518FD_BYTE_REGS_C1FIFOUA14_03             (uint16_t)(0x103)

#define MCP2518FD_BYTE_REGS_C1FIFOCON15_00            (uint16_t)(0x004) // C1FIFOCON15 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON15_01            (uint16_t)(0x105)
#define MCP2518FD_BYTE_REGS_C1FIFOCON15_02            (uint16_t)(0x106)
#define MCP2518FD_BYTE_REGS_C1FIFOCON15_03            (uint16_t)(0x107)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA15_00            (uint16_t)(0x108) // C1FIFOSTA15 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA15_01            (uint16_t)(0x109)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA15_02            (uint16_t)(0x10A)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA15_03            (uint16_t)(0x10B)

#define MCP2518FD_BYTE_REGS_C1FIFOUA15_00             (uint16_t)(0x10C) // C1FIFOUA15 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA15_01             (uint16_t)(0x10D)
#define MCP2518FD_BYTE_REGS_C1FIFOUA15_02             (uint16_t)(0x10E)
#define MCP2518FD_BYTE_REGS_C1FIFOUA15_03             (uint16_t)(0x10F)

#define MCP2518FD_BYTE_REGS_C1FIFOCON16_00            (uint16_t)(0x110) // C1FIFOCON16 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON16_01            (uint16_t)(0x111)
#define MCP2518FD_BYTE_REGS_C1FIFOCON16_02            (uint16_t)(0x112)
#define MCP2518FD_BYTE_REGS_C1FIFOCON16_03            (uint16_t)(0x113)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA16_00            (uint16_t)(0x114) // C1FIFOSTA16 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA16_01            (uint16_t)(0x114)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA16_02            (uint16_t)(0x116)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA16_03            (uint16_t)(0x117)

#define MCP2518FD_BYTE_REGS_C1FIFOUA16_00             (uint16_t)(0x118) // C1FIFOUA16 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA16_01             (uint16_t)(0x119)
#define MCP2518FD_BYTE_REGS_C1FIFOUA16_02             (uint16_t)(0x11A)
#define MCP2518FD_BYTE_REGS_C1FIFOUA16_03             (uint16_t)(0x11B)

#define MCP2518FD_BYTE_REGS_C1FIFOCON17_00            (uint16_t)(0x11C) // C1FIFOCON17 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON17_01            (uint16_t)(0x11D)
#define MCP2518FD_BYTE_REGS_C1FIFOCON17_02            (uint16_t)(0x11E)
#define MCP2518FD_BYTE_REGS_C1FIFOCON17_03            (uint16_t)(0x11F)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA17_00            (uint16_t)(0x120) // C1FIFOSTA17 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA17_01            (uint16_t)(0x121)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA17_02            (uint16_t)(0x122)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA17_03            (uint16_t)(0x123)

#define MCP2518FD_BYTE_REGS_C1FIFOUA17_00             (uint16_t)(0x124) // C1FIFOUA17 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA17_01             (uint16_t)(0x125)
#define MCP2518FD_BYTE_REGS_C1FIFOUA17_02             (uint16_t)(0x126)
#define MCP2518FD_BYTE_REGS_C1FIFOUA17_03             (uint16_t)(0x127)

#define MCP2518FD_BYTE_REGS_C1FIFOCON18_00            (uint16_t)(0x128) // C1FIFOCON18 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON18_01            (uint16_t)(0x129)
#define MCP2518FD_BYTE_REGS_C1FIFOCON18_02            (uint16_t)(0x12A)
#define MCP2518FD_BYTE_REGS_C1FIFOCON18_03            (uint16_t)(0x12B)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA18_00            (uint16_t)(0x12C) // C1FIFOSTA18 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA18_01            (uint16_t)(0x12D)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA18_02            (uint16_t)(0x12E)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA18_03            (uint16_t)(0x12F)

#define MCP2518FD_BYTE_REGS_C1FIFOUA18_00             (uint16_t)(0x130) // C1FIFOUA18 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA18_01             (uint16_t)(0x131)
#define MCP2518FD_BYTE_REGS_C1FIFOUA18_02             (uint16_t)(0x132)
#define MCP2518FD_BYTE_REGS_C1FIFOUA18_03             (uint16_t)(0x133)

#define MCP2518FD_BYTE_REGS_C1FIFOCON19_00            (uint16_t)(0x134) // C1FIFOCON19 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON19_01            (uint16_t)(0x135)
#define MCP2518FD_BYTE_REGS_C1FIFOCON19_02            (uint16_t)(0x136)
#define MCP2518FD_BYTE_REGS_C1FIFOCON19_03            (uint16_t)(0x137)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA19_00            (uint16_t)(0x138) // C1FIFOSTA19 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA19_01            (uint16_t)(0x139)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA19_02            (uint16_t)(0x13A)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA19_03            (uint16_t)(0x13B)

#define MCP2518FD_BYTE_REGS_C1FIFOUA19_00             (uint16_t)(0x13C) // C1FIFOUA19 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA19_01             (uint16_t)(0x13D)
#define MCP2518FD_BYTE_REGS_C1FIFOUA19_02             (uint16_t)(0x13E)
#define MCP2518FD_BYTE_REGS_C1FIFOUA19_03             (uint16_t)(0x13F)

#define MCP2518FD_BYTE_REGS_C1FIFOCON20_00            (uint16_t)(0x140) // C1FIFOCON20 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON20_01            (uint16_t)(0x141)
#define MCP2518FD_BYTE_REGS_C1FIFOCON20_02            (uint16_t)(0x142)
#define MCP2518FD_BYTE_REGS_C1FIFOCON20_03            (uint16_t)(0x143)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA20_00            (uint16_t)(0x144) // C1FIFOSTA20 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA20_01            (uint16_t)(0x145)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA20_02            (uint16_t)(0x146)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA20_03            (uint16_t)(0x147)

#define MCP2518FD_BYTE_REGS_C1FIFOUA20_00             (uint16_t)(0x148) // C1FIFOUA20 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA20_01             (uint16_t)(0x149)
#define MCP2518FD_BYTE_REGS_C1FIFOUA20_02             (uint16_t)(0x14A)
#define MCP2518FD_BYTE_REGS_C1FIFOUA20_03             (uint16_t)(0x14B)

#define MCP2518FD_BYTE_REGS_C1FIFOCON21_00            (uint16_t)(0x14C) // C1FIFOCON21 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON21_01            (uint16_t)(0x14D)
#define MCP2518FD_BYTE_REGS_C1FIFOCON21_02            (uint16_t)(0x14E)
#define MCP2518FD_BYTE_REGS_C1FIFOCON21_03            (uint16_t)(0x14F)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA21_00            (uint16_t)(0x150) // C1FIFOSTA21 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA21_01            (uint16_t)(0x151)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA21_02            (uint16_t)(0x152)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA21_03            (uint16_t)(0x153)

#define MCP2518FD_BYTE_REGS_C1FIFOUA21_00             (uint16_t)(0x154) // C1FIFOUA21 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA21_01             (uint16_t)(0x155)
#define MCP2518FD_BYTE_REGS_C1FIFOUA21_02             (uint16_t)(0x156)
#define MCP2518FD_BYTE_REGS_C1FIFOUA21_03             (uint16_t)(0x157)

#define MCP2518FD_BYTE_REGS_C1FIFOCON22_00            (uint16_t)(0x158) // C1FIFOCON22 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON22_01            (uint16_t)(0x159)
#define MCP2518FD_BYTE_REGS_C1FIFOCON22_02            (uint16_t)(0x15A)
#define MCP2518FD_BYTE_REGS_C1FIFOCON22_03            (uint16_t)(0x15B)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA22_00            (uint16_t)(0x15C) // C1FIFOSTA22 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA22_01            (uint16_t)(0x15D)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA22_02            (uint16_t)(0x15E)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA22_03            (uint16_t)(0x15F)

#define MCP2518FD_BYTE_REGS_C1FIFOUA22_00             (uint16_t)(0x160) // C1FIFOUA22 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA22_01             (uint16_t)(0x161)
#define MCP2518FD_BYTE_REGS_C1FIFOUA22_02             (uint16_t)(0x162)
#define MCP2518FD_BYTE_REGS_C1FIFOUA22_03             (uint16_t)(0x163)

#define MCP2518FD_BYTE_REGS_C1FIFOCON23_00            (uint16_t)(0x164) // C1FIFOCON23 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON23_01            (uint16_t)(0x165)
#define MCP2518FD_BYTE_REGS_C1FIFOCON23_02            (uint16_t)(0x166)
#define MCP2518FD_BYTE_REGS_C1FIFOCON23_03            (uint16_t)(0x167)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA23_00            (uint16_t)(0x168) // C1FIFOSTA23 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA23_01            (uint16_t)(0x169)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA23_02            (uint16_t)(0x16A)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA23_03            (uint16_t)(0x16B)

#define MCP2518FD_BYTE_REGS_C1FIFOUA23_00             (uint16_t)(0x16C) // C1FIFOUA23 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA23_01             (uint16_t)(0x16D)
#define MCP2518FD_BYTE_REGS_C1FIFOUA23_02             (uint16_t)(0x16E)
#define MCP2518FD_BYTE_REGS_C1FIFOUA23_03             (uint16_t)(0x16F)

#define MCP2518FD_BYTE_REGS_C1FIFOCON24_00            (uint16_t)(0x170) // C1FIFOCON24 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON24_01            (uint16_t)(0x171)
#define MCP2518FD_BYTE_REGS_C1FIFOCON24_02            (uint16_t)(0x172)
#define MCP2518FD_BYTE_REGS_C1FIFOCON24_03            (uint16_t)(0x173)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA24_00            (uint16_t)(0x174) // C1FIFOSTA24 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA24_01            (uint16_t)(0x175)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA24_02            (uint16_t)(0x176)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA24_03            (uint16_t)(0x177)

#define MCP2518FD_BYTE_REGS_C1FIFOUA24_00             (uint16_t)(0x178) // C1FIFOUA24 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA24_01             (uint16_t)(0x179)
#define MCP2518FD_BYTE_REGS_C1FIFOUA24_02             (uint16_t)(0x17A)
#define MCP2518FD_BYTE_REGS_C1FIFOUA24_03             (uint16_t)(0x17B)

#define MCP2518FD_BYTE_REGS_C1FIFOCON25_00            (uint16_t)(0x17C) // C1FIFOCON25 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON25_01            (uint16_t)(0x17D)
#define MCP2518FD_BYTE_REGS_C1FIFOCON25_02            (uint16_t)(0x17E)
#define MCP2518FD_BYTE_REGS_C1FIFOCON25_03            (uint16_t)(0x17F)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA25_00            (uint16_t)(0x180) // C1FIFOSTA25 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA25_01            (uint16_t)(0x181)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA25_02            (uint16_t)(0x182)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA25_03            (uint16_t)(0x183)

#define MCP2518FD_BYTE_REGS_C1FIFOUA25_00             (uint16_t)(0x184) // C1FIFOUA25 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA25_01             (uint16_t)(0x185)
#define MCP2518FD_BYTE_REGS_C1FIFOUA25_02             (uint16_t)(0x186)
#define MCP2518FD_BYTE_REGS_C1FIFOUA25_03             (uint16_t)(0x187)

#define MCP2518FD_BYTE_REGS_C1FIFOCON26_00            (uint16_t)(0x188) // C1FIFOCON26 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON26_01            (uint16_t)(0x189)
#define MCP2518FD_BYTE_REGS_C1FIFOCON26_02            (uint16_t)(0x18A)
#define MCP2518FD_BYTE_REGS_C1FIFOCON26_03            (uint16_t)(0x18B)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA26_00            (uint16_t)(0x18C) // C1FIFOSTA26 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA26_01            (uint16_t)(0x18D)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA26_02            (uint16_t)(0x18E)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA26_03            (uint16_t)(0x18F)

#define MCP2518FD_BYTE_REGS_C1FIFOUA26_00             (uint16_t)(0x190) // C1FIFOUA26 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA26_01             (uint16_t)(0x191)
#define MCP2518FD_BYTE_REGS_C1FIFOUA26_02             (uint16_t)(0x192)
#define MCP2518FD_BYTE_REGS_C1FIFOUA26_03             (uint16_t)(0x193)

#define MCP2518FD_BYTE_REGS_C1FIFOCON27_00            (uint16_t)(0x194) // C1FIFOCON27 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON27_01            (uint16_t)(0x195)
#define MCP2518FD_BYTE_REGS_C1FIFOCON27_02            (uint16_t)(0x196)
#define MCP2518FD_BYTE_REGS_C1FIFOCON27_03            (uint16_t)(0x197)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA27_00            (uint16_t)(0x198) // C1FIFOSTA27 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA27_01            (uint16_t)(0x199)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA27_02            (uint16_t)(0x19A)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA27_03            (uint16_t)(0x19B)

#define MCP2518FD_BYTE_REGS_C1FIFOUA27_00             (uint16_t)(0x19C) // C1FIFOUA27 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA27_01             (uint16_t)(0x19D)
#define MCP2518FD_BYTE_REGS_C1FIFOUA27_02             (uint16_t)(0x19E)
#define MCP2518FD_BYTE_REGS_C1FIFOUA27_03             (uint16_t)(0x19F)

#define MCP2518FD_BYTE_REGS_C1FIFOCON28_00            (uint16_t)(0x1A0) // C1FIFOCON28 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON28_01            (uint16_t)(0x1A1)
#define MCP2518FD_BYTE_REGS_C1FIFOCON28_02            (uint16_t)(0x1A1)
#define MCP2518FD_BYTE_REGS_C1FIFOCON28_03            (uint16_t)(0x1A3)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA28_00            (uint16_t)(0x1A4) // C1FIFOSTA28 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA28_01            (uint16_t)(0x1A5)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA28_02            (uint16_t)(0x1A6)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA28_03            (uint16_t)(0x1A7)

#define MCP2518FD_BYTE_REGS_C1FIFOUA28_00             (uint16_t)(0x1A8) // C1FIFOUA28 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA28_01             (uint16_t)(0x1A9)
#define MCP2518FD_BYTE_REGS_C1FIFOUA28_02             (uint16_t)(0x1AA)
#define MCP2518FD_BYTE_REGS_C1FIFOUA28_03             (uint16_t)(0x1AB)

#define MCP2518FD_BYTE_REGS_C1FIFOCON29_00            (uint16_t)(0x1AC) // C1FIFOCON29 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON29_01            (uint16_t)(0x1AD)
#define MCP2518FD_BYTE_REGS_C1FIFOCON29_02            (uint16_t)(0x1AE)
#define MCP2518FD_BYTE_REGS_C1FIFOCON29_03            (uint16_t)(0x1AF)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA29_00            (uint16_t)(0x1B0) // C1FIFOSTA29 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA29_01            (uint16_t)(0x1B1)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA29_02            (uint16_t)(0x1B2)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA29_03            (uint16_t)(0x1B3)

#define MCP2518FD_BYTE_REGS_C1FIFOUA29_00             (uint16_t)(0x1B4) // C1FIFOUA29 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA29_01             (uint16_t)(0x1B5)
#define MCP2518FD_BYTE_REGS_C1FIFOUA29_02             (uint16_t)(0x1B6)
#define MCP2518FD_BYTE_REGS_C1FIFOUA29_03             (uint16_t)(0x1B7)

#define MCP2518FD_BYTE_REGS_C1FIFOCON30_00            (uint16_t)(0x1B8) // C1FIFOCON30 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON30_01            (uint16_t)(0x1B9)
#define MCP2518FD_BYTE_REGS_C1FIFOCON30_02            (uint16_t)(0x1BA)
#define MCP2518FD_BYTE_REGS_C1FIFOCON30_03            (uint16_t)(0x1BB)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA30_00            (uint16_t)(0x1BC) // C1FIFOSTA30 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA30_01            (uint16_t)(0x1BD)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA30_02            (uint16_t)(0x1BE)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA30_03            (uint16_t)(0x1BF)

#define MCP2518FD_BYTE_REGS_C1FIFOUA30_00             (uint16_t)(0x1C0) // C1FIFOUA30 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA30_01             (uint16_t)(0x1C1)
#define MCP2518FD_BYTE_REGS_C1FIFOUA30_02             (uint16_t)(0x1C2)
#define MCP2518FD_BYTE_REGS_C1FIFOUA30_03             (uint16_t)(0x1C3)

#define MCP2518FD_BYTE_REGS_C1FIFOCON31_00            (uint16_t)(0x1C4) // C1FIFOCON31 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOCON31_01            (uint16_t)(0x1C5)
#define MCP2518FD_BYTE_REGS_C1FIFOCON31_02            (uint16_t)(0x1C6)
#define MCP2518FD_BYTE_REGS_C1FIFOCON31_03            (uint16_t)(0x1C7)

#define MCP2518FD_BYTE_REGS_C1FIFOSTA31_00            (uint16_t)(0x1C8) // C1FIFOSTA31 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOSTA31_01            (uint16_t)(0x1C9)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA31_02            (uint16_t)(0x1CA)
#define MCP2518FD_BYTE_REGS_C1FIFOSTA31_03            (uint16_t)(0x1CB)

#define MCP2518FD_BYTE_REGS_C1FIFOUA31_00             (uint16_t)(0x1CC) // C1FIFOUA31 REGISTER
#define MCP2518FD_BYTE_REGS_C1FIFOUA31_01             (uint16_t)(0x1CD)
#define MCP2518FD_BYTE_REGS_C1FIFOUA31_02             (uint16_t)(0x1CE)
#define MCP2518FD_BYTE_REGS_C1FIFOUA31_03             (uint16_t)(0x1CF)

#define MCP2518FD_BYTE_REGS_C1FLTCON0_00              (uint16_t)(0x1D0) // C1FLTCON0 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON0_01              (uint16_t)(0x1D1)
#define MCP2518FD_BYTE_REGS_C1FLTCON0_02              (uint16_t)(0x1D2)
#define MCP2518FD_BYTE_REGS_C1FLTCON0_03              (uint16_t)(0x1D3)

#define MCP2518FD_BYTE_REGS_C1FLTCON1_00              (uint16_t)(0x1D4) // C1FLTCON1 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON1_01              (uint16_t)(0x1D5)
#define MCP2518FD_BYTE_REGS_C1FLTCON1_02              (uint16_t)(0x1D6)
#define MCP2518FD_BYTE_REGS_C1FLTCON1_03              (uint16_t)(0x1D6)

#define MCP2518FD_BYTE_REGS_C1FLTCON2_00              (uint16_t)(0x1D8) // C1FLTCON2 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON2_01              (uint16_t)(0x1D9)
#define MCP2518FD_BYTE_REGS_C1FLTCON2_02              (uint16_t)(0x1DA)
#define MCP2518FD_BYTE_REGS_C1FLTCON2_03              (uint16_t)(0x1DB)

#define MCP2518FD_BYTE_REGS_C1FLTCON3_00              (uint16_t)(0x1DC) // C1FLTCON3 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON3_01              (uint16_t)(0x1DD)
#define MCP2518FD_BYTE_REGS_C1FLTCON3_02              (uint16_t)(0x1DE)
#define MCP2518FD_BYTE_REGS_C1FLTCON3_03              (uint16_t)(0x1DF)

#define MCP2518FD_BYTE_REGS_C1FLTCON4_00              (uint16_t)(0x1E0) // C1FLTCON4 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON4_01              (uint16_t)(0x1E1)
#define MCP2518FD_BYTE_REGS_C1FLTCON4_02              (uint16_t)(0x1E2)
#define MCP2518FD_BYTE_REGS_C1FLTCON4_03              (uint16_t)(0x1E3)

#define MCP2518FD_BYTE_REGS_C1FLTCON5_00              (uint16_t)(0x1E4) // C1FLTCON5 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON5_01              (uint16_t)(0x1E5)
#define MCP2518FD_BYTE_REGS_C1FLTCON5_02              (uint16_t)(0x1E6)
#define MCP2518FD_BYTE_REGS_C1FLTCON5_03              (uint16_t)(0x1E7)

#define MCP2518FD_BYTE_REGS_C1FLTCON6_00              (uint16_t)(0x1E8) // C1FLTCON6 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON6_01              (uint16_t)(0x1E9)
#define MCP2518FD_BYTE_REGS_C1FLTCON6_02              (uint16_t)(0x1EA)
#define MCP2518FD_BYTE_REGS_C1FLTCON6_03              (uint16_t)(0x1EB)

#define MCP2518FD_BYTE_REGS_C1FLTCON7_00              (uint16_t)(0x1EC) // C1FLTCON7 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTCON7_01              (uint16_t)(0x1ED)
#define MCP2518FD_BYTE_REGS_C1FLTCON7_02              (uint16_t)(0x1EE)
#define MCP2518FD_BYTE_REGS_C1FLTCON7_03              (uint16_t)(0x1EF)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ0_00              (uint16_t)(0x1F0) // C1FLTOBJ0 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ0_01              (uint16_t)(0x1F1)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ0_02              (uint16_t)(0x1F2)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ0_03              (uint16_t)(0x1F3)

#define MCP2518FD_BYTE_REGS_C1MASK0_00                (uint16_t)(0x1F4) // C1MASK0 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK0_01                (uint16_t)(0x1F5)
#define MCP2518FD_BYTE_REGS_C1MASK0_02                (uint16_t)(0x1F6)
#define MCP2518FD_BYTE_REGS_C1MASK0_03                (uint16_t)(0x1F7)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ1_00              (uint16_t)(0x1F8) // C1FLTOBJ1 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ1_01              (uint16_t)(0x1F9)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ1_02              (uint16_t)(0x1FA)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ1_03              (uint16_t)(0x1FB)

#define MCP2518FD_BYTE_REGS_C1MASK1_00                (uint16_t)(0x1FC) // C1MASK1 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK1_01                (uint16_t)(0x1FD)
#define MCP2518FD_BYTE_REGS_C1MASK1_02                (uint16_t)(0x1FE)
#define MCP2518FD_BYTE_REGS_C1MASK1_03                (uint16_t)(0x1FF)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ2_00              (uint16_t)(0x200) // C1FLTOBJ2 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ2_01              (uint16_t)(0x201)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ2_02              (uint16_t)(0x202)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ2_03              (uint16_t)(0x203)

#define MCP2518FD_BYTE_REGS_C1MASK2_00                (uint16_t)(0x204) // C1MASK2 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK2_01                (uint16_t)(0x205)
#define MCP2518FD_BYTE_REGS_C1MASK2_02                (uint16_t)(0x206)
#define MCP2518FD_BYTE_REGS_C1MASK2_03                (uint16_t)(0x207)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ3_00              (uint16_t)(0x208) // C1FLTOBJ3 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ3_01              (uint16_t)(0x209)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ3_02              (uint16_t)(0x20A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ3_03              (uint16_t)(0x20B)

#define MCP2518FD_BYTE_REGS_C1MASK3_00                (uint16_t)(0x20C) // C1MASK3 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK3_01                (uint16_t)(0x20D)
#define MCP2518FD_BYTE_REGS_C1MASK3_02                (uint16_t)(0x20E)
#define MCP2518FD_BYTE_REGS_C1MASK3_03                (uint16_t)(0x20F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ4_00              (uint16_t)(0x210) // C1FLTOBJ4 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ4_01              (uint16_t)(0x211)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ4_02              (uint16_t)(0x212)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ4_03              (uint16_t)(0x213)

#define MCP2518FD_BYTE_REGS_C1MASK4_00                (uint16_t)(0x214) // C1MASK4 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK4_01                (uint16_t)(0x215)
#define MCP2518FD_BYTE_REGS_C1MASK4_02                (uint16_t)(0x216)
#define MCP2518FD_BYTE_REGS_C1MASK4_03                (uint16_t)(0x217)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ5_00              (uint16_t)(0x218) // C1FLTOBJ5 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ5_01              (uint16_t)(0x219)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ5_02              (uint16_t)(0x21A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ5_03              (uint16_t)(0x21B)

#define MCP2518FD_BYTE_REGS_C1MASK5_00                (uint16_t)(0x21C) // C1MASK5 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK5_01                (uint16_t)(0x21D)
#define MCP2518FD_BYTE_REGS_C1MASK5_02                (uint16_t)(0x21E)
#define MCP2518FD_BYTE_REGS_C1MASK5_03                (uint16_t)(0x21F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ6_00              (uint16_t)(0x220) // C1FLTOBJ6 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ6_01              (uint16_t)(0x221)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ6_02              (uint16_t)(0x222)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ6_03              (uint16_t)(0x223)

#define MCP2518FD_BYTE_REGS_C1MASK6_00                (uint16_t)(0x224) // C1MASK6 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK6_01                (uint16_t)(0x225)
#define MCP2518FD_BYTE_REGS_C1MASK6_02                (uint16_t)(0x226)
#define MCP2518FD_BYTE_REGS_C1MASK6_03                (uint16_t)(0x227)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ7_00              (uint16_t)(0x228) // C1FLTOBJ7 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ7_01              (uint16_t)(0x229)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ7_02              (uint16_t)(0x22A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ7_03              (uint16_t)(0x22B)

#define MCP2518FD_BYTE_REGS_C1MASK7_00                (uint16_t)(0x22C) // C1MASK7 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK7_01                (uint16_t)(0x22D)
#define MCP2518FD_BYTE_REGS_C1MASK7_02                (uint16_t)(0x22E)
#define MCP2518FD_BYTE_REGS_C1MASK7_03                (uint16_t)(0x22F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ8_00              (uint16_t)(0x230) // C1FLTOBJ8 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ8_01              (uint16_t)(0x231)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ8_02              (uint16_t)(0x232)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ8_03              (uint16_t)(0x233)

#define MCP2518FD_BYTE_REGS_C1MASK8_00                (uint16_t)(0x234) // C1MASK8 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK8_01                (uint16_t)(0x235)
#define MCP2518FD_BYTE_REGS_C1MASK8_02                (uint16_t)(0x236)
#define MCP2518FD_BYTE_REGS_C1MASK8_03                (uint16_t)(0x237)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ9_00              (uint16_t)(0x238) // C1FLTOBJ9 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ9_01              (uint16_t)(0x239)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ9_02              (uint16_t)(0x23A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ9_03              (uint16_t)(0x23B)

#define MCP2518FD_BYTE_REGS_C1MASK9_00                (uint16_t)(0x23C) // C1MASK9 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK9_01                (uint16_t)(0x23D)
#define MCP2518FD_BYTE_REGS_C1MASK9_02                (uint16_t)(0x23E)
#define MCP2518FD_BYTE_REGS_C1MASK9_03                (uint16_t)(0x23F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ10_00             (uint16_t)(0x240) // C1FLTOBJ10 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ10_01             (uint16_t)(0x241)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ10_02             (uint16_t)(0x242)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ10_03             (uint16_t)(0x243)

#define MCP2518FD_BYTE_REGS_C1MASK10_00               (uint16_t)(0x244) // C1MASK10 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK10_01               (uint16_t)(0x245)
#define MCP2518FD_BYTE_REGS_C1MASK10_02               (uint16_t)(0x246)
#define MCP2518FD_BYTE_REGS_C1MASK10_03               (uint16_t)(0x247)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ11_00             (uint16_t)(0x248) // C1FLTOBJ11 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ11_01             (uint16_t)(0x249)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ11_02             (uint16_t)(0x24A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ11_03             (uint16_t)(0x24B)

#define MCP2518FD_BYTE_REGS_C1MASK11_00               (uint16_t)(0x24C) // C1MASK11 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK11_01               (uint16_t)(0x24D)
#define MCP2518FD_BYTE_REGS_C1MASK11_02               (uint16_t)(0x24E)
#define MCP2518FD_BYTE_REGS_C1MASK11_03               (uint16_t)(0x24F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ12_00             (uint16_t)(0x250) // C1FLTOBJ12 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ12_01             (uint16_t)(0x251)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ12_02             (uint16_t)(0x252)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ12_03             (uint16_t)(0x253)

#define MCP2518FD_BYTE_REGS_C1MASK12_00               (uint16_t)(0x254) // C1MASK12 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK12_01               (uint16_t)(0x255)
#define MCP2518FD_BYTE_REGS_C1MASK12_02               (uint16_t)(0x256)
#define MCP2518FD_BYTE_REGS_C1MASK12_03               (uint16_t)(0x257)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ13_00             (uint16_t)(0x258) // C1FLTOBJ13 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ13_01             (uint16_t)(0x259)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ13_02             (uint16_t)(0x25A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ13_03             (uint16_t)(0x25B)

#define MCP2518FD_BYTE_REGS_C1MASK13_00               (uint16_t)(0x25C) // C1MASK13 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK13_01               (uint16_t)(0x25D)
#define MCP2518FD_BYTE_REGS_C1MASK13_02               (uint16_t)(0x25E)
#define MCP2518FD_BYTE_REGS_C1MASK13_03               (uint16_t)(0x25F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ14_00             (uint16_t)(0x260) // C1FLTOBJ14 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ14_01             (uint16_t)(0x261)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ14_02             (uint16_t)(0x262)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ14_03             (uint16_t)(0x263)

#define MCP2518FD_BYTE_REGS_C1MASK14_00               (uint16_t)(0x264) // C1MASK14 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK14_01               (uint16_t)(0x265)
#define MCP2518FD_BYTE_REGS_C1MASK14_02               (uint16_t)(0x266)
#define MCP2518FD_BYTE_REGS_C1MASK14_03               (uint16_t)(0x267)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ15_00             (uint16_t)(0x268) // C1FLTOBJ15 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ15_01             (uint16_t)(0x269)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ15_02             (uint16_t)(0x26A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ15_03             (uint16_t)(0x26B)

#define MCP2518FD_BYTE_REGS_C1MASK15_00               (uint16_t)(0x26C) // C1MASK15 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK15_01               (uint16_t)(0x26D)
#define MCP2518FD_BYTE_REGS_C1MASK15_02               (uint16_t)(0x26E)
#define MCP2518FD_BYTE_REGS_C1MASK15_03               (uint16_t)(0x26F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ16_00             (uint16_t)(0x270) // C1FLTOBJ16 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ16_01             (uint16_t)(0x271)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ16_02             (uint16_t)(0x272)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ16_03             (uint16_t)(0x273)

#define MCP2518FD_BYTE_REGS_C1MASK16_00               (uint16_t)(0x274) // C1MASK16 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK16_01               (uint16_t)(0x275)
#define MCP2518FD_BYTE_REGS_C1MASK16_02               (uint16_t)(0x276)
#define MCP2518FD_BYTE_REGS_C1MASK16_03               (uint16_t)(0x277)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ17_00             (uint16_t)(0x278) // C1FLTOBJ17 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ17_01             (uint16_t)(0x279)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ17_02             (uint16_t)(0x27A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ17_03             (uint16_t)(0x27B)

#define MCP2518FD_BYTE_REGS_C1MASK17_00               (uint16_t)(0x27C) // C1MASK17 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK17_01               (uint16_t)(0x27D)
#define MCP2518FD_BYTE_REGS_C1MASK17_02               (uint16_t)(0x27E)
#define MCP2518FD_BYTE_REGS_C1MASK17_03               (uint16_t)(0x27F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ18_00             (uint16_t)(0x280) // C1FLTOBJ18 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ18_01             (uint16_t)(0x281)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ18_02             (uint16_t)(0x282)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ18_03             (uint16_t)(0x283)

#define MCP2518FD_BYTE_REGS_C1MASK18_00               (uint16_t)(0x284) // C1MASK18 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK18_01               (uint16_t)(0x285)
#define MCP2518FD_BYTE_REGS_C1MASK18_02               (uint16_t)(0x286)
#define MCP2518FD_BYTE_REGS_C1MASK18_03               (uint16_t)(0x287)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ19_00             (uint16_t)(0x288) // C1FLTOBJ19 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ19_01             (uint16_t)(0x289)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ19_02             (uint16_t)(0x28A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ19_03             (uint16_t)(0x28B)

#define MCP2518FD_BYTE_REGS_C1MASK19_00               (uint16_t)(0x28C) // C1MASK19 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK19_01               (uint16_t)(0x28D)
#define MCP2518FD_BYTE_REGS_C1MASK19_02               (uint16_t)(0x28E)
#define MCP2518FD_BYTE_REGS_C1MASK19_03               (uint16_t)(0x28F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ20_00             (uint16_t)(0x290) // C1FLTOBJ20 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ20_01             (uint16_t)(0x291)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ20_02             (uint16_t)(0x292)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ20_03             (uint16_t)(0x293)

#define MCP2518FD_BYTE_REGS_C1MASK20_00               (uint16_t)(0x294) // C1MASK20 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK20_01               (uint16_t)(0x295)
#define MCP2518FD_BYTE_REGS_C1MASK20_02               (uint16_t)(0x296)
#define MCP2518FD_BYTE_REGS_C1MASK20_03               (uint16_t)(0x297)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ21_00             (uint16_t)(0x298) // C1FLTOBJ21 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ21_01             (uint16_t)(0x299)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ21_02             (uint16_t)(0x29A)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ21_03             (uint16_t)(0x29B)

#define MCP2518FD_BYTE_REGS_C1MASK21_00               (uint16_t)(0x29C) // C1MASK21 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK21_01               (uint16_t)(0x29D)
#define MCP2518FD_BYTE_REGS_C1MASK21_02               (uint16_t)(0x29E)
#define MCP2518FD_BYTE_REGS_C1MASK21_03               (uint16_t)(0x29F)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ22_00             (uint16_t)(0x2A0) // C1FLTOBJ22 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ22_01             (uint16_t)(0x2A1)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ22_02             (uint16_t)(0x2A2)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ22_03             (uint16_t)(0x2A3)

#define MCP2518FD_BYTE_REGS_C1MASK22_00               (uint16_t)(0x2A4) // C1MASK22 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK22_01               (uint16_t)(0x2A5)
#define MCP2518FD_BYTE_REGS_C1MASK22_02               (uint16_t)(0x2A6)
#define MCP2518FD_BYTE_REGS_C1MASK22_03               (uint16_t)(0x2A7)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ23_00             (uint16_t)(0x2A8) // C1FLTOBJ23 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ23_01             (uint16_t)(0x2A9)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ23_02             (uint16_t)(0x2AA)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ23_03             (uint16_t)(0x2AB)

#define MCP2518FD_BYTE_REGS_C1MASK23_00               (uint16_t)(0x2AC) // C1MASK23 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK23_01               (uint16_t)(0x2AD)
#define MCP2518FD_BYTE_REGS_C1MASK23_02               (uint16_t)(0x2AE)
#define MCP2518FD_BYTE_REGS_C1MASK23_03               (uint16_t)(0x2AF)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ24_00             (uint16_t)(0x2B0) // C1FLTOBJ24 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ24_01             (uint16_t)(0x2B1)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ24_02             (uint16_t)(0x2B2)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ24_03             (uint16_t)(0x2B3)

#define MCP2518FD_BYTE_REGS_C1MASK24_00               (uint16_t)(0x2B4) // C1MASK24 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK24_01               (uint16_t)(0x2B5)
#define MCP2518FD_BYTE_REGS_C1MASK24_02               (uint16_t)(0x2B6)
#define MCP2518FD_BYTE_REGS_C1MASK24_03               (uint16_t)(0x2B7)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ25_00             (uint16_t)(0x2B8) // C1FLTOBJ25 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ25_01             (uint16_t)(0x2B9)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ25_02             (uint16_t)(0x2BA)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ25_03             (uint16_t)(0x2BB)

#define MCP2518FD_BYTE_REGS_C1MASK25_00               (uint16_t)(0x2BC) // C1MASK25 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK25_01               (uint16_t)(0x2BD)
#define MCP2518FD_BYTE_REGS_C1MASK25_02               (uint16_t)(0x2BE)
#define MCP2518FD_BYTE_REGS_C1MASK25_03               (uint16_t)(0x2BF)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ26_00             (uint16_t)(0x2C0) // C1FLTOBJ26 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ26_01             (uint16_t)(0x2C1)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ26_02             (uint16_t)(0x2C2)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ26_03             (uint16_t)(0x2C3)

#define MCP2518FD_BYTE_REGS_C1MASK26_00               (uint16_t)(0x2C4) // C1MASK26 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK26_01               (uint16_t)(0x2C5)
#define MCP2518FD_BYTE_REGS_C1MASK26_02               (uint16_t)(0x2C6)
#define MCP2518FD_BYTE_REGS_C1MASK26_03               (uint16_t)(0x2C7)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ27_00             (uint16_t)(0x2C8) // C1FLTOBJ27 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ27_01             (uint16_t)(0x2C9)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ27_02             (uint16_t)(0x2CA)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ27_03             (uint16_t)(0x2CB)

#define MCP2518FD_BYTE_REGS_C1MASK27_00               (uint16_t)(0x2CC) // C1MASK27 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK27_01               (uint16_t)(0x2CD)
#define MCP2518FD_BYTE_REGS_C1MASK27_02               (uint16_t)(0x2CE)
#define MCP2518FD_BYTE_REGS_C1MASK27_03               (uint16_t)(0x2CF)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ28_00             (uint16_t)(0x2D0) // C1FLTOBJ28 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ28_01             (uint16_t)(0x2D1)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ28_02             (uint16_t)(0x2D2)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ28_03             (uint16_t)(0x2D3)

#define MCP2518FD_BYTE_REGS_C1MASK28_00               (uint16_t)(0x2D4) // C1MASK28 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK28_01               (uint16_t)(0x2D5)
#define MCP2518FD_BYTE_REGS_C1MASK28_02               (uint16_t)(0x2D6)
#define MCP2518FD_BYTE_REGS_C1MASK28_03               (uint16_t)(0x2D7)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ29_00             (uint16_t)(0x2D8) // C1FLTOBJ29 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ29_01             (uint16_t)(0x2D9)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ29_02             (uint16_t)(0x2DA)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ29_03             (uint16_t)(0x2DB)

#define MCP2518FD_BYTE_REGS_C1MASK29_00               (uint16_t)(0x2DC) // C1MASK29 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK29_01               (uint16_t)(0x2DD)
#define MCP2518FD_BYTE_REGS_C1MASK29_02               (uint16_t)(0x2DE)
#define MCP2518FD_BYTE_REGS_C1MASK29_03               (uint16_t)(0x2DF)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ30_00             (uint16_t)(0x2E0) // C1FLTOBJ30 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ30_01             (uint16_t)(0x2E1)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ30_02             (uint16_t)(0x2E2)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ30_03             (uint16_t)(0x2E3)

#define MCP2518FD_BYTE_REGS_C1MASK30_00               (uint16_t)(0x2E4) // C1MASK30 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK30_01               (uint16_t)(0x2E5)
#define MCP2518FD_BYTE_REGS_C1MASK30_02               (uint16_t)(0x2E6)
#define MCP2518FD_BYTE_REGS_C1MASK30_03               (uint16_t)(0x2E7)

#define MCP2518FD_BYTE_REGS_C1FLTOBJ31_00             (uint16_t)(0x2E8) // C1FLTOBJ31 REGISTER
#define MCP2518FD_BYTE_REGS_C1FLTOBJ31_01             (uint16_t)(0x2E9)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ31_02             (uint16_t)(0x2EA)
#define MCP2518FD_BYTE_REGS_C1FLTOBJ31_03             (uint16_t)(0x2EB)

#define MCP2518FD_BYTE_REGS_C1MASK31_00               (uint16_t)(0x2EC) // C1MASK31 REGISTER
#define MCP2518FD_BYTE_REGS_C1MASK31_01               (uint16_t)(0x2ED)
#define MCP2518FD_BYTE_REGS_C1MASK31_02               (uint16_t)(0x2EE)
#define MCP2518FD_BYTE_REGS_C1MASK31_03               (uint16_t)(0x2EF)

/******************************************************************************/
/* == Definition ::: Config Macros MCP2518FD_BYTE :: Access Bits Registers == */
/******************************************************************************/

/* -------- MCP2518FD_BYTE : (R/W 8) OSC -------- */
#define MCP2518FD_BYTE_OSC_RESET_VALUE                   (uint08_t)(0U)

#define MCP2518FD_BYTE_OSC_PLLEN_POS                     (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_PLLEN_MSK                     ((uint08_t)1U << MCP2518FD_BYTE_OSC_PLLEN_POS)
#define MCP2518FD_BYTE_OSC_PLLEN_WRTE(DAT)               (MCP2518FD_BYTE_OSC_PLLEN_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_PLLEN_POS))
#define MCP2518FD_BYTE_OSC_PLLEN_READ(REG)               (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_PLLEN_MSK) >> MCP2518FD_BYTE_OSC_PLLEN_POS)
#define MCP2518FD_BYTE_OSC_PLLEN_SYS_CLK_XTAL_VAL        (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_PLLEN_SYS_CLK_PLL_VAL         (uint08_t)(1U)
#define MCP2518FD_BYTE_OSC_PLLEN_SYS_CLK_PLL             (MCP2518FD_BYTE_OSC_PLLEN_SYS_CLK_PLL_VAL << MCP2518FD_BYTE_OSC_PLLEN_POS)
#define MCP2518FD_BYTE_OSC_PLLEN_SYS_CLK_XTAL            (MCP2518FD_BYTE_OSC_PLLEN_SYS_CLK_XTAL_VAL << MCP2518FD_BYTE_OSC_PLLEN_POS)

#define MCP2518FD_BYTE_OSC_OSCDIS_POS                    (uint08_t)(2U)
#define MCP2518FD_BYTE_OSC_OSCDIS_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_OSC_OSCDIS_POS)
#define MCP2518FD_BYTE_OSC_OSCDIS_WRTE(DAT)              (MCP2518FD_BYTE_OSC_OSCDIS_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_OSCDIS_POS))
#define MCP2518FD_BYTE_OSC_OSCDIS_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_OSCDIS_MSK) >> MCP2518FD_BYTE_OSC_OSCDIS_POS)
#define MCP2518FD_BYTE_OSC_OSCDIS_ENA_LCK_VAL            (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_OSCDIS_DIS_CLK_VAL            (uint08_t)(1U)
#define MCP2518FD_BYTE_OSC_OSCDIS_ENA_LCK                (MCP2518FD_BYTE_OSC_OSCDIS_ENA_LCK_VAL << MCP2518FD_BYTE_OSC_OSCDIS_POS)
#define MCP2518FD_BYTE_OSC_OSCDIS_DIS_CLKL               (MCP2518FD_BYTE_OSC_OSCDIS_ENA_LCK_VAL << MCP2518FD_BYTE_OSC_OSCDIS_POS)

#define MCP2518FD_BYTE_OSC_LPMEN_POS                     (uint08_t)(3U)
#define MCP2518FD_BYTE_OSC_LPMEN_MSK                     ((uint08_t)1U << MCP2518FD_BYTE_OSC_LPMEN_POS)
#define MCP2518FD_BYTE_OSC_LPMEN_WRTE(DAT)               (MCP2518FD_BYTE_OSC_LPMEN_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_LPMEN_POS))
#define MCP2518FD_BYTE_OSC_LPMEN_READ(REG)               (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_LPMEN_MSK) >> MCP2518FD_BYTE_OSC_LPMEN_POS)
#define MCP2518FD_BYTE_OSC_LPMEN_DIS_VAL                 (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_LPMEN_ENA_VAL                 (uint08_t)(1U)
#define MCP2518FD_BYTE_OSC_LPMEN_DIS                     (MCP2518FD_BYTE_OSC_LPMEN_DIS_VAL << MCP2518FD_BYTE_OSC_LPMEN_POS)
#define MCP2518FD_BYTE_OSC_LPMEN_ENA                     (MCP2518FD_BYTE_OSC_LPMEN_ENA_VAL << MCP2518FD_BYTE_OSC_LPMEN_POS)

#define MCP2518FD_BYTE_OSC_SCLKDIV_POS                   (uint08_t)(4U)
#define MCP2518FD_BYTE_OSC_SCLKDIV_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_OSC_SCLKDIV_POS)
#define MCP2518FD_BYTE_OSC_SCLKDIV_WRTE(DAT)             (MCP2518FD_BYTE_OSC_SCLKDIV_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_SCLKDIV_POS))
#define MCP2518FD_BYTE_OSC_SCLKDIV_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_SCLKDIV_MSK) >> MCP2518FD_BYTE_OSC_SCLKDIV_POS)
#define MCP2518FD_BYTE_OSC_SCLKDIV_DIV1_VAL              (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_SCLKDIV_DIV2_VAL              (uint08_t)(1U)
#define MCP2518FD_BYTE_OSC_SCLKDIV_DIV1                  (MCP2518FD_BYTE_OSC_SCLKDIV_DIV1_VAL << MCP2518FD_BYTE_OSC_SCLKDIV_POS)
#define MCP2518FD_BYTE_OSC_SCLKDIV_DIV2                  (MCP2518FD_BYTE_OSC_SCLKDIV_DIV2_VAL << MCP2518FD_BYTE_OSC_SCLKDIV_POS)

#define MCP2518FD_BYTE_OSC_CLKODIV_POS                   (uint08_t)(5U)
#define MCP2518FD_BYTE_OSC_CLKODIV_MSK                   ((uint08_t)3U << MCP2518FD_BYTE_OSC_CLKODIV_POS)
#define MCP2518FD_BYTE_OSC_CLKODIV_WRTE(DAT)             (MCP2518FD_BYTE_OSC_CLKODIV_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_CLKODIV_POS))
#define MCP2518FD_BYTE_OSC_CLKODIV_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_CLKODIV_MSK) >> MCP2518FD_BYTE_OSC_CLKODIV_POS)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV1_VAL              (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV2_VAL              (uint08_t)(1U)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV4_VAL              (uint08_t)(2U)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV10_VAL             (uint08_t)(3U)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV1                  (MCP2518FD_BYTE_OSC_CLKODIV_DIV1_VAL << MCP2518FD_BYTE_OSC_CLKODIV_POS)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV2                  (MCP2518FD_BYTE_OSC_CLKODIV_DIV2_VAL << MCP2518FD_BYTE_OSC_CLKODIV_POS)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV4                  (MCP2518FD_BYTE_OSC_CLKODIV_DIV4_VAL << MCP2518FD_BYTE_OSC_CLKODIV_POS)
#define MCP2518FD_BYTE_OSC_CLKODIV_DIV10                 (MCP2518FD_BYTE_OSC_CLKODIV_DIV10_VAL << MCP2518FD_BYTE_OSC_CLKODIV_POS)

#define MCP2518FD_BYTE_OSC_PLLRDY_POS                    (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_PLLRDY_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_OSC_PLLRDY_POS)
#define MCP2518FD_BYTE_OSC_PLLRDY_WRTE(DAT)              (MCP2518FD_BYTE_OSC_PLLRDY_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_PLLRDY_POS))
#define MCP2518FD_BYTE_OSC_PLLRDY_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_PLLRDY_MSK) >> MCP2518FD_BYTE_OSC_PLLRDY_POS)
#define MCP2518FD_BYTE_OSC_PLL_NOT_READY_VAL             (uint08_t)(0U)
#define MCP2518FD_BYTE_OSC_PLL_LOCKED_VAL                (uint08_t)(1U)
#define MCP2518FD_BYTE_OSC_PLL_NOT_READY                 (MCP2518FD_BYTE_OSC_PLL_NOT_READY_VAL << MCP2518FD_BYTE_OSC_CLKODIV_POS)
#define MCP2518FD_BYTE_OSC_PLL_LOCKED                    (MCP2518FD_BYTE_OSC_PLL_LOCKED_VAL << MCP2518FD_BYTE_OSC_CLKODIV_POS)

#define MCP2518FD_BYTE_OSC_OSCRDY_POS                    (uint08_t)(2U)
#define MCP2518FD_BYTE_OSC_OSCRDY_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_OSC_OSCRDY_POS)
#define MCP2518FD_BYTE_OSC_OSCRDY_WRTE(DAT)              (MCP2518FD_BYTE_OSC_OSCRDY_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_OSCRDY_POS))
#define MCP2518FD_BYTE_OSC_OSCRDY_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_OSCRDY_MSK) >> MCP2518FD_BYTE_OSC_OSCRDY_POS)

#define MCP2518FD_BYTE_OSC_SCLKRDY_POS                   (uint08_t)(4U)
#define MCP2518FD_BYTE_OSC_SCLKRDY_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_OSC_SCLKRDY_POS)
#define MCP2518FD_BYTE_OSC_SCLKRDY_WRTE(DAT)             (MCP2518FD_BYTE_OSC_SCLKRDY_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_OSC_SCLKRDY_POS))
#define MCP2518FD_BYTE_OSC_SCLKRDY_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_OSC_SCLKRDY_MSK) >> MCP2518FD_BYTE_OSC_SCLKRDY_POS)

/* -------- MCP2518FD_BYTE : (R/W 8) IOCON -------- */
#define MCP2518FD_BYTE_IOCON_RESET_VALUE                 (uint08_t)(0U)

#define MCP2518FD_BYTE_IOCON_TRIS0_POS                   (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_TRIS0_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_IOCON_TRIS0_POS)
#define MCP2518FD_BYTE_IOCON_TRIS0_WRTE(DAT)             (MCP2518FD_BYTE_IOCON_TRIS0_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_TRIS0_POS))
#define MCP2518FD_BYTE_IOCON_TRIS0_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_TRIS0_MSK) >> MCP2518FD_BYTE_IOCON_TRIS0_POS)
#define MCP2518FD_BYTE_IOCON_TRIS0_OUT_VAL               (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_TRIS0_IN_VAL                (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_TRIS0_OUT                   (MCP2518FD_BYTE_IOCON_TRIS0_OUT_VAL << MCP2518FD_BYTE_IOCON_TRIS0_POS)
#define MCP2518FD_BYTE_IOCON_TRIS0_IN                    (MCP2518FD_BYTE_IOCON_TRIS0_IN_VAL << MCP2518FD_BYTE_IOCON_TRIS0_POS)

#define MCP2518FD_BYTE_IOCON_TRIS1_POS                   (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_TRIS1_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_IOCON_TRIS1_POS)
#define MCP2518FD_BYTE_IOCON_TRIS1_WRTE(DAT)             (MCP2518FD_BYTE_IOCON_TRIS1_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_TRIS1_POS))
#define MCP2518FD_BYTE_IOCON_TRIS1_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_TRIS1_MSK) >> MCP2518FD_BYTE_IOCON_TRIS1_POS)
#define MCP2518FD_BYTE_IOCON_TRIS1_OUT_VAL               (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_TRIS1_IN_VAL                (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_TRIS1_OUT                   (MCP2518FD_BYTE_IOCON_TRIS1_OUT_VAL << MCP2518FD_BYTE_IOCON_TRIS1_POS)
#define MCP2518FD_BYTE_IOCON_TRIS1_IN                    (MCP2518FD_BYTE_IOCON_TRIS1_IN_VAL << MCP2518FD_BYTE_IOCON_TRIS1_POS)

#define MCP2518FD_BYTE_IOCON_XSTBYEN_POS                 (uint08_t)(6U)
#define MCP2518FD_BYTE_IOCON_XSTBYEN_MSK                 ((uint08_t)1U << MCP2518FD_BYTE_IOCON_XSTBYEN_POS)
#define MCP2518FD_BYTE_IOCON_XSTBYEN_WRTE(DAT)           (MCP2518FD_BYTE_IOCON_XSTBYEN_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_XSTBYEN_POS))
#define MCP2518FD_BYTE_IOCON_XSTBYEN_READ(REG)           (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_XSTBYEN_MSK) >> MCP2518FD_BYTE_IOCON_XSTBYEN_POS)
#define MCP2518FD_BYTE_IOCON_XSTBYEN_DISABLE_VAL         (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_XSTBYEN_ENABLE_VAL          (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_XSTBYEN_DISABLE             (MCP2518FD_BYTE_IOCON_XSTBYEN_DISABLE_VAL << MCP2518FD_BYTE_IOCON_XSTBYEN_POS)
#define MCP2518FD_BYTE_IOCON_XSTBYEN_ENABLE              (MCP2518FD_BYTE_IOCON_XSTBYEN_ENABLE_VAL << MCP2518FD_BYTE_IOCON_XSTBYEN_POS)

#define MCP2518FD_BYTE_IOCON_LAT0_POS                    (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_LAT0_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_IOCON_LAT0_POS)
#define MCP2518FD_BYTE_IOCON_LAT0_WRTE(DAT)              (MCP2518FD_BYTE_IOCON_LAT0_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_LAT0_POS))
#define MCP2518FD_BYTE_IOCON_LAT0_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_LAT0_POS)
#define MCP2518FD_BYTE_IOCON_LAT0_PUT_LOW_VAL            (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_LAT0_PUT_HIGH_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_LAT0_PUT_LOW                (MCP2518FD_BYTE_IOCON_LAT0_PUT_LOW_VAL << MCP2518FD_BYTE_IOCON_LAT0_POS)
#define MCP2518FD_BYTE_IOCON_LAT0_PUT_HIGH               (MCP2518FD_BYTE_IOCON_LAT0_PUT_HIGH_VAL << MCP2518FD_BYTE_IOCON_LAT0_POS)

#define MCP2518FD_BYTE_IOCON_LAT1_POS                    (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_LAT1_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_IOCON_LAT1_POS)
#define MCP2518FD_BYTE_IOCON_LAT1_WRTE(DAT)              (MCP2518FD_BYTE_IOCON_LAT1_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_LAT1_POS))
#define MCP2518FD_BYTE_IOCON_LAT1_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_LAT1_POS)
#define MCP2518FD_BYTE_IOCON_LAT1_PUT_LOW_VAL            (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_LAT1_PUT_HIGH_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_LAT1_PUT_LOW                (MCP2518FD_BYTE_IOCON_LAT1_PUT_LOW_VAL << MCP2518FD_BYTE_IOCON_LAT1_POS)
#define MCP2518FD_BYTE_IOCON_LAT1_PUT_HIGH               (MCP2518FD_BYTE_IOCON_LAT1_PUT_HIGH_VAL << MCP2518FD_BYTE_IOCON_LAT1_POS)

#define MCP2518FD_BYTE_IOCON_GPIO0_POS                   (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_GPIO0_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_IOCON_GPIO0_POS)
#define MCP2518FD_BYTE_IOCON_GPIO0_WRTE(DAT)             (MCP2518FD_BYTE_IOCON_GPIO0_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_GPIO0_POS))
#define MCP2518FD_BYTE_IOCON_GPIO0_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_GPIO0_POS)
#define MCP2518FD_BYTE_IOCON_GPIO0_LOW_VAL               (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_GPIO0_HIGH_VAL              (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_GPIO0_LOW                   (MCP2518FD_BYTE_IOCON_GPIO0_LOW_VAL << MCP2518FD_BYTE_IOCON_GPIO0_POS)
#define MCP2518FD_BYTE_IOCON_GPIO0_HIGH                  (MCP2518FD_BYTE_IOCON_GPIO0_HIGH_VAL << MCP2518FD_BYTE_IOCON_GPIO0_POS)

#define MCP2518FD_BYTE_IOCON_GPIO1_POS                   (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_GPIO1_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_IOCON_GPIO1_POS)
#define MCP2518FD_BYTE_IOCON_GPIO1_WRTE(DAT)             (MCP2518FD_BYTE_IOCON_GPIO1_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_GPIO1_POS))
#define MCP2518FD_BYTE_IOCON_GPIO1_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_GPIO1_POS)
#define MCP2518FD_BYTE_IOCON_GPIO1_LOW_VAL               (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_GPIO1_HIGH_VAL              (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_GPIO1_LOW                   (MCP2518FD_BYTE_IOCON_GPIO1_LOW_VAL << MCP2518FD_BYTE_IOCON_GPIO1_POS)
#define MCP2518FD_BYTE_IOCON_GPIO1_HIGH                  (MCP2518FD_BYTE_IOCON_GPIO1_HIGH_VAL << MCP2518FD_BYTE_IOCON_GPIO1_POS)

#define MCP2518FD_BYTE_IOCON_PM0_POS                     (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_PM0_MSK                     ((uint08_t)1U << MCP2518FD_BYTE_IOCON_PM0_POS)
#define MCP2518FD_BYTE_IOCON_PM0_WRTE(DAT)               (MCP2518FD_BYTE_IOCON_PM0_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_PM0_POS))
#define MCP2518FD_BYTE_IOCON_PM0_READ(REG)               (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_PM0_POS)
#define MCP2518FD_BYTE_IOCON_PM0_IS_GPIO_VAL             (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_PM0_IS_INT_VAL              (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_PM0_IS_GPIO                 (MCP2518FD_BYTE_IOCON_PM0_IS_GPIO_VAL << MCP2518FD_BYTE_IOCON_PM0_POS)
#define MCP2518FD_BYTE_IOCON_PM0_IS_INT                  (MCP2518FD_BYTE_IOCON_PM0_IS_INT_VAL << MCP2518FD_BYTE_IOCON_PM0_POS)

#define MCP2518FD_BYTE_IOCON_PM1_POS                     (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_PM1_MSK                     ((uint08_t)1U << MCP2518FD_BYTE_IOCON_PM1_POS)
#define MCP2518FD_BYTE_IOCON_PM1_WRTE(DAT)               (MCP2518FD_BYTE_IOCON_PM1_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_PM1_POS))
#define MCP2518FD_BYTE_IOCON_PM1_READ(REG)               (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_PM1_POS)
#define MCP2518FD_BYTE_IOCON_PM1_IS_GPIO_VAL             (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_PM1_IS_INT_VAL              (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_PM1_IS_GPIO                 (MCP2518FD_BYTE_IOCON_PM1_IS_GPIO_VAL << MCP2518FD_BYTE_IOCON_PM1_POS)
#define MCP2518FD_BYTE_IOCON_PM1_IS_INT                  (MCP2518FD_BYTE_IOCON_PM1_IS_INT_VAL << MCP2518FD_BYTE_IOCON_PM1_POS)

#define MCP2518FD_BYTE_IOCON_TXCANOD_POS                 (uint08_t)(4U)
#define MCP2518FD_BYTE_IOCON_TXCANOD_MSK                 ((uint08_t)1U << MCP2518FD_BYTE_IOCON_TXCANOD_POS)
#define MCP2518FD_BYTE_IOCON_TXCANOD_WRTE(DAT)           (MCP2518FD_BYTE_IOCON_TXCANOD_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_TXCANOD_POS))
#define MCP2518FD_BYTE_IOCON_TXCANOD_READ(REG)           (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_TXCANOD_POS)
#define MCP2518FD_BYTE_IOCON_TXCANOD_OPEN_DRAIN_VAL      (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_TXCANOD_PUSH_PULL_VAL       (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_TXCANOD_OPEN_DRAIN_OUT      (MCP2518FD_BYTE_IOCON_TXCANOD_OPEN_DRAIN_VAL << MCP2518FD_BYTE_IOCON_TXCANOD_POS)
#define MCP2518FD_BYTE_IOCON_TXCANOD_PUSH_PULL_IN        (MCP2518FD_BYTE_IOCON_TXCANOD_PUSH_PULL_VAL << MCP2518FD_BYTE_IOCON_TXCANOD_POS)

#define MCP2518FD_BYTE_IOCON_SOF_POS                     (uint08_t)(5U)
#define MCP2518FD_BYTE_IOCON_SOF_MSK                     ((uint08_t)1U << MCP2518FD_BYTE_IOCON_SOF_POS)
#define MCP2518FD_BYTE_IOCON_SOF_WRTE(DAT)               (MCP2518FD_BYTE_IOCON_SOF_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_SOF_POS))
#define MCP2518FD_BYTE_IOCON_SOF_READ(REG)               (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_SOF_POS)
#define MCP2518FD_BYTE_IOCON_SOF_SOF_CLKO_VAL            (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_SOF_CLOCK_CLKO_VAL          (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_SOF_SOF_CLKO_OUT            (MCP2518FD_BYTE_IOCON_SOF_SOF_CLKO_VAL << MCP2518FD_BYTE_IOCON_SOF_POS)
#define MCP2518FD_BYTE_IOCON_SOF_CLOCK_CLKO_IN           (MCP2518FD_BYTE_IOCON_SOF_CLOCK_CLKO_VAL << MCP2518FD_BYTE_IOCON_SOF_POS)

#define MCP2518FD_BYTE_IOCON_INTOD_POS                   (uint08_t)(6U)
#define MCP2518FD_BYTE_IOCON_INTOD_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_IOCON_INTOD_POS)
#define MCP2518FD_BYTE_IOCON_INTOD_WRTE(DAT)             (MCP2518FD_BYTE_IOCON_INTOD_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_IOCON_INTOD_POS))
#define MCP2518FD_BYTE_IOCON_INTOD_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_IOCON_LAT0_MSK) >> MCP2518FD_BYTE_IOCON_INTOD_POS)
#define MCP2518FD_BYTE_IOCON_INTOD_OPEN_DRAIN_VAL        (uint08_t)(0U)
#define MCP2518FD_BYTE_IOCON_INTOD_PUSH_PULL_VAL         (uint08_t)(1U)
#define MCP2518FD_BYTE_IOCON_INTOD_OPEN_DRAIN_OUT        (MCP2518FD_BYTE_IOCON_INTOD_OPEN_DRAIN_VAL << MCP2518FD_BYTE_IOCON_INTOD_POS)
#define MCP2518FD_BYTE_IOCON_INTOD_PUSH_PULL_IN          (MCP2518FD_BYTE_IOCON_INTOD_PUSH_PULL_VAL << MCP2518FD_BYTE_IOCON_INTOD_POS)

/* -------- MCP2518FD_BYTE : (R/W 8) CRC -------- */
#define MCP2518FD_BYTE_CRC_RESET_VALUE                   (uint08_t)(0U)

#define MCP2518FD_BYTE_CRC_CRC_POS                       (uint08_t)(0U)
#define MCP2518FD_BYTE_CRC_CRC_MSK                       ((uint08_t)65535U << MCP2518FD_BYTE_CRC_CRC_POS)
#define MCP2518FD_BYTE_CRC_CRC_WRTE(DAT)                 (MCP2518FD_BYTE_CRC_CRC_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CRC_CRC_POS))
#define MCP2518FD_BYTE_CRC_CRC_READ(REG)                 (((uint08_t)(REG) & MCP2518FD_BYTE_CRC_CRC_MSK) >> MCP2518FD_BYTE_CRC_CRC_POS)

#define MCP2518FD_BYTE_CRC_CRCERRIF_POS                  (uint08_t)(0U)
#define MCP2518FD_BYTE_CRC_CRCERRIF_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_CRC_CRCERRIF_POS)
#define MCP2518FD_BYTE_CRC_CRCERRIF_WRTE(DAT)            (MCP2518FD_BYTE_CRC_CRCERRIF_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CRC_CRCERRIF_POS))
#define MCP2518FD_BYTE_CRC_CRCERRIF_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_CRC_CRCERRIF_MSK) >> MCP2518FD_BYTE_CRC_CRCERRIF_POS)
#define MCP2518FD_BYTE_CRC_CRCERRIF_NO_ERROR_VAL         (uint08_t)(0U)
#define MCP2518FD_BYTE_CRC_CRCERRIF_ERROR_VAL            (uint08_t)(1U)
#define MCP2518FD_BYTE_CRC_CRCERRIF_NO_ERROR             (MCP2518FD_BYTE_CRC_CRCERRIF_NO_ERROR_VAL << MCP2518FD_BYTE_CRC_CRCERRIF_POS)
#define MCP2518FD_BYTE_CRC_CRCERRIF_ERROR                (MCP2518FD_BYTE_CRC_CRCERRIF_ERROR_VAL << MCP2518FD_BYTE_CRC_CRCERRIF_POS)

#define MCP2518FD_BYTE_CRC_FERRIF_POS                    (uint08_t)(1U)
#define MCP2518FD_BYTE_CRC_FERRIF_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_CRC_FERRIF_POS)
#define MCP2518FD_BYTE_CRC_FERRIF_WRTE(DAT)              (MCP2518FD_BYTE_CRC_FERRIF_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CRC_FERRIF_POS))
#define MCP2518FD_BYTE_CRC_FERRIF_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_CRC_FERRIF_MSK) >> MCP2518FD_BYTE_CRC_FERRIF_POS)
#define MCP2518FD_BYTE_CRC_FERRIF_NO_ERROR_VAL           (uint08_t)(0U)
#define MCP2518FD_BYTE_CRC_FERRIF_ERROR_VAL              (uint08_t)(1U)
#define MCP2518FD_BYTE_CRC_FERRIF_NO_ERROR               (MCP2518FD_BYTE_CRC_FERRIF_NO_ERROR_VAL << MCP2518FD_BYTE_CRC_FERRIF_POS)
#define MCP2518FD_BYTE_CRC_FERRIF_ERROR                  (MCP2518FD_BYTE_CRC_FERRIF_ERROR_VAL << MCP2518FD_BYTE_CRC_FERRIF_POS)

#define MCP2518FD_BYTE_CRC_CRCERRIE_POS                  (uint08_t)(0U)
#define MCP2518FD_BYTE_CRC_CRCERRIE_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_CRC_CRCERRIE_POS)
#define MCP2518FD_BYTE_CRC_CRCERRIE_WRTE(DAT)            (MCP2518FD_BYTE_CRC_CRCERRIE_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CRC_CRCERRIE_POS))
#define MCP2518FD_BYTE_CRC_CRCERRIE_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_CRC_CRCERRIE_MSK) >> MCP2518FD_BYTE_CRC_CRCERRIE_POS)
#define MCP2518FD_BYTE_CRC_CRCERRIE_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_CRC_CRCERRIE_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CRC_CRCERRIE_DISABLE              (MCP2518FD_BYTE_CRC_CRCERRIE_DISABLE_VAL << MCP2518FD_BYTE_CRC_CRCERRIE_POS)
#define MCP2518FD_BYTE_CRC_CRCERRIE_ENABLE               (MCP2518FD_BYTE_CRC_CRCERRIE_ENABLE_VAL << MCP2518FD_BYTE_CRC_CRCERRIE_POS)

#define MCP2518FD_BYTE_CRC_FERRIE_POS                    (uint08_t)(1U)
#define MCP2518FD_BYTE_CRC_FERRIE_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_CRC_FERRIE_POS)
#define MCP2518FD_BYTE_CRC_FERRIE_WRTE(DAT)              (MCP2518FD_BYTE_CRC_FERRIE_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CRC_FERRIE_POS))
#define MCP2518FD_BYTE_CRC_FERRIE_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_CRC_FERRIE_MSK) >> MCP2518FD_BYTE_CRC_FERRIE_POS)
#define MCP2518FD_BYTE_CRC_FERRIE_DISABLE_VAL            (uint08_t)(0U)
#define MCP2518FD_BYTE_CRC_FERRIE_ENABLE_VAL             (uint08_t)(1U)
#define MCP2518FD_BYTE_CRC_FERRIE_DISABLE                (MCP2518FD_BYTE_CRC_FERRIE_DISABLE_VAL << MCP2518FD_BYTE_CRC_FERRIE_POS)
#define MCP2518FD_BYTE_CRC_FERRIE_ENABLE                 (MCP2518FD_BYTE_CRC_FERRIE_ENABLE_VAL << MCP2518FD_BYTE_CRC_FERRIE_POS)

/* -------- MCP2518FD_BYTE : (R/W 8) ECCCON -------- */
#define MCP2518FD_BYTE_ECCCON_RESET_VALUE                (uint08_t)(0U)

#define MCP2518FD_BYTE_ECCCON_ECCEN_POS                  (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCCON_ECCEN_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_ECCCON_ECCEN_POS)
#define MCP2518FD_BYTE_ECCCON_ECCEN_WRTE(DAT)            (MCP2518FD_BYTE_ECCCON_ECCEN_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_ECCCON_ECCEN_POS))
#define MCP2518FD_BYTE_ECCCON_ECCEN_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_ECCCON_ECCEN_MSK) >> MCP2518FD_BYTE_ECCCON_ECCEN_POS)
#define MCP2518FD_BYTE_ECCCON_ECCEN_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCCON_ECCEN_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_ECCCON_ECCEN_DISABLE              (MCP2518FD_BYTE_ECCCON_ECCEN_DISABLE_VAL << MCP2518FD_BYTE_ECCCON_ECCEN_POS)
#define MCP2518FD_BYTE_ECCCON_ECCEN_ENABLE               (MCP2518FD_BYTE_ECCCON_ECCEN_ENABLE_VAL << MCP2518FD_BYTE_ECCCON_ECCEN_POS)

#define MCP2518FD_BYTE_ECCCON_SECIE_POS                  (uint08_t)(1U)
#define MCP2518FD_BYTE_ECCCON_SECIE_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_ECCCON_SECIE_POS)
#define MCP2518FD_BYTE_ECCCON_SECIE_WRTE(DAT)            (MCP2518FD_BYTE_ECCCON_SECIE_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_ECCCON_SECIE_POS))
#define MCP2518FD_BYTE_ECCCON_SECIE_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_ECCCON_SECIE_MSK) >> MCP2518FD_BYTE_ECCCON_SECIE_POS)
#define MCP2518FD_BYTE_ECCCON_SECIE_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCCON_SECIE_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_ECCCON_SECIE_DISABLE              (MCP2518FD_BYTE_ECCCON_SECIE_DISABLE_VAL << MCP2518FD_BYTE_ECCCON_SECIE_POS)
#define MCP2518FD_BYTE_ECCCON_SECIE_ENABLE               (MCP2518FD_BYTE_ECCCON_SECIE_ENABLE_VAL << MCP2518FD_BYTE_ECCCON_SECIE_POS)

#define MCP2518FD_BYTE_ECCCON_DEDIE_POS                  (uint08_t)(2U)
#define MCP2518FD_BYTE_ECCCON_DEDIE_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_ECCCON_DEDIE_POS)
#define MCP2518FD_BYTE_ECCCON_DEDIE_WRTE(DAT)            (MCP2518FD_BYTE_ECCCON_DEDIE_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_ECCCON_DEDIE_POS))
#define MCP2518FD_BYTE_ECCCON_DEDIE_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_ECCCON_DEDIE_MSK) >> MCP2518FD_BYTE_ECCCON_DEDIE_POS)
#define MCP2518FD_BYTE_ECCCON_DEDIE_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCCON_DEDIE_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_ECCCON_DEDIE_DISABLE              (MCP2518FD_BYTE_ECCCON_DEDIE_DISABLE_VAL << MCP2518FD_BYTE_ECCCON_DEDIE_POS)
#define MCP2518FD_BYTE_ECCCON_DEDIE_ENABLE               (MCP2518FD_BYTE_ECCCON_DEDIE_ENABLE_VAL << MCP2518FD_BYTE_ECCCON_DEDIE_POS)

#define MCP2518FD_BYTE_ECCCON_PARITY_POS                 (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCCON_PARITY_MSK                 ((uint08_t)127U << MCP2518FD_BYTE_ECCCON_PARITY_POS)
#define MCP2518FD_BYTE_ECCCON_PARITY_WRTE(DAT)           (MCP2518FD_BYTE_ECCCON_PARITY_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_ECCCON_PARITY_POS))
#define MCP2518FD_BYTE_ECCCON_PARITY_READ(REG)           (((uint08_t)(REG) & MCP2518FD_BYTE_ECCCON_PARITY_MSK) >> MCP2518FD_BYTE_ECCCON_PARITY_POS)

/* -------- MCP2518FD_BYTE : (R/W 8) ECCSTAT -------- */
#define MCP2518FD_BYTE_ECCSTAT_RESET_VALUE               (uint08_t)(0U)

#define MCP2518FD_BYTE_ECCSTAT_SECIF_POS                 (uint08_t)(1U)
#define MCP2518FD_BYTE_ECCSTAT_SECIF_MSK                 ((uint08_t)1U << MCP2518FD_BYTE_ECCSTAT_SECIF_POS)
#define MCP2518FD_BYTE_ECCSTAT_SECIF_WRTE(DAT)           (MCP2518FD_BYTE_ECCSTAT_SECIF_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_ECCSTAT_SECIF_POS))
#define MCP2518FD_BYTE_ECCSTAT_SECIF_READ(REG)           (((uint08_t)(REG) & MCP2518FD_BYTE_ECCSTAT_SECIF_MSK) >> MCP2518FD_BYTE_ECCSTAT_SECIF_POS)
#define MCP2518FD_BYTE_ECCSTAT_SECIF_NO_ERROR_VAL        (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCSTAT_SECIF_ERROR_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_ECCSTAT_SECIF_NO_ERROR            (MCP2518FD_BYTE_ECCSTAT_SECIF_NO_ERROR_VAL << MCP2518FD_BYTE_ECCSTAT_SECIF_POS)
#define MCP2518FD_BYTE_ECCSTAT_SECIF_ERROR               (MCP2518FD_BYTE_ECCSTAT_SECIF_ERROR_VAL << MCP2518FD_BYTE_ECCSTAT_SECIF_POS)

#define MCP2518FD_BYTE_ECCSTAT_DEDIF_POS                 (uint08_t)(2U)
#define MCP2518FD_BYTE_ECCSTAT_DEDIF_MSK                 ((uint08_t)1U << MCP2518FD_BYTE_ECCSTAT_DEDIF_POS)
#define MCP2518FD_BYTE_ECCSTAT_DEDIF_WRTE(DAT)           (MCP2518FD_BYTE_ECCSTAT_DEDIF_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_ECCSTAT_DEDIF_POS))
#define MCP2518FD_BYTE_ECCSTAT_DEDIF_READ(REG)           (((uint08_t)(REG) & MCP2518FD_BYTE_ECCSTAT_DEDIF_MSK) >> MCP2518FD_BYTE_ECCSTAT_DEDIF_POS)
#define MCP2518FD_BYTE_ECCSTAT_DEDIF_NO_ERROR_VAL        (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCSTAT_DEDIF_ERROR_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_ECCSTAT_DEDIF_NO_ERROR            (MCP2518FD_BYTE_ECCSTAT_DEDIF_NO_ERROR_VAL << MCP2518FD_BYTE_ECCSTAT_DEDIF_POS)
#define MCP2518FD_BYTE_ECCSTAT_DEDIF_ERROR               (MCP2518FD_BYTE_ECCSTAT_DEDIF_ERROR_VAL << MCP2518FD_BYTE_ECCSTAT_DEDIF_POS)

#define MCP2518FD_BYTE_ECCSTAT_ERRADDR_POS               (uint08_t)(0U)
#define MCP2518FD_BYTE_ECCSTAT_ERRADDR_MSK               ((uint08_t)4095U << MCP2518FD_BYTE_ECCSTAT_ERRADDR_POS)
#define MCP2518FD_BYTE_ECCSTAT_ERRADDR_WRTE(DAT)         (MCP2518FD_BYTE_ECCSTAT_ERRADDR_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_ECCSTAT_ERRADDR_POS))
#define MCP2518FD_BYTE_ECCSTAT_ERRADDR_READ(REG)         (((uint08_t)(REG) & MCP2518FD_BYTE_ECCSTAT_ERRADDR_MSK) >> MCP2518FD_BYTE_ECCSTAT_ERRADDR_POS)

/* -------- MCP2518FD_BYTE : (R/W 8) DEVID -------- */
#define MCP2518FD_BYTE_DEVID_RESET_VALUE                 (uint08_t)(0U)

#define MCP2518FD_BYTE_DEVID_REV_POS                     (uint08_t)(0U)
#define MCP2518FD_BYTE_DEVID_REV_MSK                     ((uint08_t)15U << MCP2518FD_BYTE_DEVID_REV_POS)
#define MCP2518FD_BYTE_DEVID_REV_WRTE(DAT)               (MCP2518FD_BYTE_DEVID_REV_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_DEVID_REV_POS))
#define MCP2518FD_BYTE_DEVID_REV_READ(REG)               (((uint08_t)(REG) & MCP2518FD_BYTE_DEVID_REV_MSK) >> MCP2518FD_BYTE_DEVID_REV_POS)

#define MCP2518FD_BYTE_DEVID_ID_POS                      (uint08_t)(4U)
#define MCP2518FD_BYTE_DEVID_ID_MSK                      ((uint08_t)15U << MCP2518FD_BYTE_DEVID_ID_POS)
#define MCP2518FD_BYTE_DEVID_ID_WRTE(DAT)                (MCP2518FD_BYTE_DEVID_ID_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_DEVID_ID_POS))
#define MCP2518FD_BYTE_DEVID_ID_READ(REG)                (((uint08_t)(REG) & MCP2518FD_BYTE_DEVID_ID_MSK) >> MCP2518FD_BYTE_DEVID_ID_POS)

/* -------- MCP2518FD_BYTE : (R/W 8) CiCON -------- */
#define MCP2518FD_BYTE_CiCON_RESET_VALUE                 (uint08_t)(0U)

#define MCP2518FD_BYTE_CiCON_DNCNT_POS                   (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_DNCNT_MSK                   ((uint08_t)31U << MCP2518FD_BYTE_CiCON_DNCNT_POS)
#define MCP2518FD_BYTE_CiCON_DNCNT_WRTE(DAT)             (MCP2518FD_BYTE_CiCON_DNCNT_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_DNCNT_POS))
#define MCP2518FD_BYTE_CiCON_DNCNT_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_DNCNT_MSK) >> MCP2518FD_BYTE_CiCON_DNCNT_POS)

#define MCP2518FD_BYTE_CiCON_ISOCRCEN_POS                (uint08_t)(5U)
#define MCP2518FD_BYTE_CiCON_ISOCRCEN_MSK                ((uint08_t)1U << MCP2518FD_BYTE_CiCON_ISOCRCEN_POS)
#define MCP2518FD_BYTE_CiCON_ISOCRCEN_WRTE(DAT)          (MCP2518FD_BYTE_CiCON_ISOCRCEN_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_ISOCRCEN_POS))
#define MCP2518FD_BYTE_CiCON_ISOCRCEN_READ(REG)          (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_ISOCRCEN_MSK) >> MCP2518FD_BYTE_CiCON_ISOCRCEN_POS)
#define MCP2518FD_BYTE_CiCON_ISOCRCEN_STUFF_OFF_VAL      (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_ISOCRCEN_STUFF_ON_VAL       (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_ISOCRCEN_STUFF_OFF          (MCP2518FD_BYTE_CiCON_ISOCRCEN_STUFF_OFF_VAL << MCP2518FD_BYTE_CiCON_ISOCRCEN_POS)
#define MCP2518FD_BYTE_CiCON_ISOCRCEN_STUFF_ON           (MCP2518FD_BYTE_CiCON_ISOCRCEN_STUFF_ON_VAL << MCP2518FD_BYTE_CiCON_ISOCRCEN_POS)

#define MCP2518FD_BYTE_CiCON_PXEDIS_POS                  (uint08_t)(6U)
#define MCP2518FD_BYTE_CiCON_PXEDIS_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_CiCON_PXEDIS_POS)
#define MCP2518FD_BYTE_CiCON_PXEDIS_WRTE(DAT)            (MCP2518FD_BYTE_CiCON_PXEDIS_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_PXEDIS_POS))
#define MCP2518FD_BYTE_CiCON_PXEDIS_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_PXEDIS_MSK) >> MCP2518FD_BYTE_CiCON_PXEDIS_POS)
#define MCP2518FD_BYTE_CiCON_PXEDIS_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_PXEDIS_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_PXEDIS_DISABLE              (MCP2518FD_BYTE_CiCON_PXEDIS_DISABLE_VAL << MCP2518FD_BYTE_CiCON_PXEDIS_POS)
#define MCP2518FD_BYTE_CiCON_PXEDIS_ENABLE               (MCP2518FD_BYTE_CiCON_PXEDIS_ENABLE_VAL << MCP2518FD_BYTE_CiCON_PXEDIS_POS)

#define MCP2518FD_BYTE_CiCON_WAKFIL_POS                  (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_WAKFIL_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_CiCON_WAKFIL_POS)
#define MCP2518FD_BYTE_CiCON_WAKFIL_WRTE(DAT)            (MCP2518FD_BYTE_CiCON_WAKFIL_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_WAKFIL_POS))
#define MCP2518FD_BYTE_CiCON_WAKFIL_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_WAKFIL_MSK) >> MCP2518FD_BYTE_CiCON_WAKFIL_POS)
#define MCP2518FD_BYTE_CiCON_WAKFIL_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_WAKFIL_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_WAKFIL_DISABLE              (MCP2518FD_BYTE_CiCON_WAKFIL_DISABLE_VAL << MCP2518FD_BYTE_CiCON_WAKFIL_POS)
#define MCP2518FD_BYTE_CiCON_WAKFIL_ENABLE               (MCP2518FD_BYTE_CiCON_WAKFIL_ENABLE_VAL << MCP2518FD_BYTE_CiCON_WAKFIL_POS)

#define MCP2518FD_BYTE_CiCON_WAKFIL_POS                  (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_WAKFIL_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_CiCON_WAKFIL_POS)
#define MCP2518FD_BYTE_CiCON_WAKFIL_WRTE(DAT)            (MCP2518FD_BYTE_CiCON_WAKFIL_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_WAKFIL_POS))
#define MCP2518FD_BYTE_CiCON_WAKFIL_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_WAKFIL_MSK) >> MCP2518FD_BYTE_CiCON_WAKFIL_POS)
#define MCP2518FD_BYTE_CiCON_WAKFIL_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_WAKFIL_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_WAKFIL_DISABLE              (MCP2518FD_BYTE_CiCON_WAKFIL_DISABLE_VAL << MCP2518FD_BYTE_CiCON_WAKFIL_POS)
#define MCP2518FD_BYTE_CiCON_WAKFIL_ENABLE               (MCP2518FD_BYTE_CiCON_WAKFIL_ENABLE_VAL << MCP2518FD_BYTE_CiCON_WAKFIL_POS)

#define MCP2518FD_BYTE_CiCON_WFT_POS                     (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_WFT_MSK                     ((uint08_t)3U << MCP2518FD_BYTE_CiCON_WFT_POS)
#define MCP2518FD_BYTE_CiCON_WFT_WRTE(DAT)               (MCP2518FD_BYTE_CiCON_WFT_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_WFT_POS))
#define MCP2518FD_BYTE_CiCON_WFT_READ(REG)               (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_WFT_MSK) >> MCP2518FD_BYTE_CiCON_WFT_POS)
#define MCP2518FD_BYTE_CiCON_WFT_T00FILTER_VAL           (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_WFT_T01FILTER_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_WFT_T10FILTER_VAL           (uint08_t)(2U)
#define MCP2518FD_BYTE_CiCON_WFT_T11FILTER_VAL           (uint08_t)(3U)
#define MCP2518FD_BYTE_CiCON_WFT_T00FILTER               (MCP2518FD_BYTE_CiCON_WFT_T00FILTER_VAL << MCP2518FD_BYTE_CiCON_WFT_POS)
#define MCP2518FD_BYTE_CiCON_WFT_T01FILTER               (MCP2518FD_BYTE_CiCON_WFT_T01FILTER_VAL << MCP2518FD_BYTE_CiCON_WFT_POS)
#define MCP2518FD_BYTE_CiCON_WFT_T10FILTER               (MCP2518FD_BYTE_CiCON_WFT_T10FILTER_VAL << MCP2518FD_BYTE_CiCON_WFT_POS)
#define MCP2518FD_BYTE_CiCON_WFT_T11FILTER               (MCP2518FD_BYTE_CiCON_WFT_T11FILTER_VAL << MCP2518FD_BYTE_CiCON_WFT_POS)

#define MCP2518FD_BYTE_CiCON_BUSY_POS                    (uint08_t)(3U)
#define MCP2518FD_BYTE_CiCON_BUSY_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_CiCON_BUSY_POS)
#define MCP2518FD_BYTE_CiCON_BUSY_WRTE(DAT)              (MCP2518FD_BYTE_CiCON_BUSY_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_BUSY_POS))
#define MCP2518FD_BYTE_CiCON_BUSY_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_BUSY_MSK) >> MCP2518FD_BYTE_CiCON_BUSY_POS)
#define MCP2518FD_BYTE_CiCON_BUSY_INACTIVE_VAL           (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_BUSY_ACTIVE_VAL             (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_BUSY_INACTIVE               (MCP2518FD_BYTE_CiCON_BUSY_INACTIVE_VAL << MCP2518FD_BYTE_CiCON_BUSY_POS)
#define MCP2518FD_BYTE_CiCON_BUSY_ACTIVE                 (MCP2518FD_BYTE_CiCON_BUSY_ACTIVE_VAL << MCP2518FD_BYTE_CiCON_BUSY_POS)

#define MCP2518FD_BYTE_CiCON_BRSDIS_POS                  (uint08_t)(4U)
#define MCP2518FD_BYTE_CiCON_BRSDIS_MSK                  ((uint08_t)1U << MCP2518FD_BYTE_CiCON_BRSDIS_POS)
#define MCP2518FD_BYTE_CiCON_BRSDIS_WRTE(DAT)            (MCP2518FD_BYTE_CiCON_BRSDIS_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_BRSDIS_POS))
#define MCP2518FD_BYTE_CiCON_BRSDIS_READ(REG)            (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_BRSDIS_MSK) >> MCP2518FD_BYTE_CiCON_BRSDIS_POS)
#define MCP2518FD_BYTE_CiCON_BRSDIS_DISABLE_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_BRSDIS_ENABLE_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_BRSDIS_DISABLE              (MCP2518FD_BYTE_CiCON_BRSDIS_DISABLE_VAL << MCP2518FD_BYTE_CiCON_BRSDIS_POS)
#define MCP2518FD_BYTE_CiCON_BRSDIS_ENABLE               (MCP2518FD_BYTE_CiCON_BRSDIS_ENABLE_VAL << MCP2518FD_BYTE_CiCON_BRSDIS_POS)

#define MCP2518FD_BYTE_CiCON_RTXAT_POS                   (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_RTXAT_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_CiCON_RTXAT_POS)
#define MCP2518FD_BYTE_CiCON_RTXAT_WRTE(DAT)             (MCP2518FD_BYTE_CiCON_RTXAT_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_RTXAT_POS))
#define MCP2518FD_BYTE_CiCON_RTXAT_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_RTXAT_MSK) >> MCP2518FD_BYTE_CiCON_RTXAT_POS)
#define MCP2518FD_BYTE_CiCON_RTXAT_DISABLE_VAL           (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_RTXAT_ENABLE_VAL            (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_RTXAT_DISABLE               (MCP2518FD_BYTE_CiCON_RTXAT_DISABLE_VAL << MCP2518FD_BYTE_CiCON_RTXAT_POS)
#define MCP2518FD_BYTE_CiCON_RTXAT_ENABLE                (MCP2518FD_BYTE_CiCON_RTXAT_ENABLE_VAL << MCP2518FD_BYTE_CiCON_RTXAT_POS)

#define MCP2518FD_BYTE_CiCON_ESIGM_POS                   (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_ESIGM_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_CiCON_ESIGM_POS)
#define MCP2518FD_BYTE_CiCON_ESIGM_WRTE(DAT)             (MCP2518FD_BYTE_CiCON_ESIGM_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_ESIGM_POS))
#define MCP2518FD_BYTE_CiCON_ESIGM_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_ESIGM_MSK) >> MCP2518FD_BYTE_CiCON_ESIGM_POS)
#define MCP2518FD_BYTE_CiCON_ESIGM_DISABLE_VAL           (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_ESIGM_ENABLE_VAL            (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_ESIGM_DISABLE               (MCP2518FD_BYTE_CiCON_ESIGM_DISABLE_VAL << MCP2518FD_BYTE_CiCON_ESIGM_POS)
#define MCP2518FD_BYTE_CiCON_ESIGM_ENABLE                (MCP2518FD_BYTE_CiCON_ESIGM_ENABLE_VAL << MCP2518FD_BYTE_CiCON_ESIGM_POS)

#define MCP2518FD_BYTE_CiCON_SERR2LOM_POS                (uint08_t)(2U)
#define MCP2518FD_BYTE_CiCON_SERR2LOM_MSK                ((uint08_t)1U << MCP2518FD_BYTE_CiCON_SERR2LOM_POS)
#define MCP2518FD_BYTE_CiCON_SERR2LOM_WRTE(DAT)          (MCP2518FD_BYTE_CiCON_SERR2LOM_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_SERR2LOM_POS))
#define MCP2518FD_BYTE_CiCON_SERR2LOM_READ(REG)          (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_SERR2LOM_MSK) >> MCP2518FD_BYTE_CiCON_SERR2LOM_POS)
#define MCP2518FD_BYTE_CiCON_SERR2LOM_TX_RESTRICTED_VAL  (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_SERR2LOM_TX_ONLY_LISTEN_VAL (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_SERR2LOM_TX_RESTRICTED      (MCP2518FD_BYTE_CiCON_SERR2LOM_TX_RESTRICTED_VAL << MCP2518FD_BYTE_CiCON_SERR2LOM_POS)
#define MCP2518FD_BYTE_CiCON_SERR2LOM_TX_ONLY_LISTEN     (MCP2518FD_BYTE_CiCON_SERR2LOM_TX_ONLY_LISTEN_VAL << MCP2518FD_BYTE_CiCON_SERR2LOM_POS)

#define MCP2518FD_BYTE_CiCON_STEF_POS                    (uint08_t)(3U)
#define MCP2518FD_BYTE_CiCON_STEF_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_CiCON_STEF_POS)
#define MCP2518FD_BYTE_CiCON_STEF_WRTE(DAT)              (MCP2518FD_BYTE_CiCON_STEF_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_STEF_POS))
#define MCP2518FD_BYTE_CiCON_STEF_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_STEF_MSK) >> MCP2518FD_BYTE_CiCON_STEF_POS)
#define MCP2518FD_BYTE_CiCON_STEF_NO_TEF_VAL             (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_STEF_TEF_RAM_VAL            (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_STEF_NO_TEF                 (MCP2518FD_BYTE_CiCON_STEF_NO_TEF_VAL << MCP2518FD_BYTE_CiCON_STEF_POS)
#define MCP2518FD_BYTE_CiCON_STEF_TEF_RAM                (MCP2518FD_BYTE_CiCON_STEF_TEF_RAM_VAL << MCP2518FD_BYTE_CiCON_STEF_POS)

#define MCP2518FD_BYTE_CiCON_TXQEN_POS                   (uint08_t)(4U)
#define MCP2518FD_BYTE_CiCON_TXQEN_MSK                   ((uint08_t)1U << MCP2518FD_BYTE_CiCON_TXQEN_POS)
#define MCP2518FD_BYTE_CiCON_TXQEN_WRTE(DAT)             (MCP2518FD_BYTE_CiCON_TXQEN_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_TXQEN_POS))
#define MCP2518FD_BYTE_CiCON_TXQEN_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_TXQEN_MSK) >> MCP2518FD_BYTE_CiCON_TXQEN_POS)
#define MCP2518FD_BYTE_CiCON_TXQEN_NO_TQX_VAL            (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_TXQEN_TQX_RAM_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_TXQEN_NO_TQX                (MCP2518FD_BYTE_CiCON_TXQEN_NO_TQX_VAL << MCP2518FD_BYTE_CiCON_TXQEN_POS)
#define MCP2518FD_BYTE_CiCON_TXQEN_TQX_RAM               (MCP2518FD_BYTE_CiCON_TXQEN_TQX_RAM_VAL << MCP2518FD_BYTE_CiCON_TXQEN_POS)

#define MCP2518FD_BYTE_CiCON_OPMOD_POS                   (uint08_t)(5U)
#define MCP2518FD_BYTE_CiCON_OPMOD_MSK                   ((uint08_t)7U << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_WRTE(DAT)             (MCP2518FD_BYTE_CiCON_OPMOD_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_OPMOD_POS))
#define MCP2518FD_BYTE_CiCON_OPMOD_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_OPMOD_MSK) >> MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_NORMAL_FD_VAL         (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_OPMOD_SLEEP_VAL             (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_OPMOD_LOOPBACK_VAL          (uint08_t)(2U)
#define MCP2518FD_BYTE_CiCON_OPMOD_LISTEN_VAL            (uint08_t)(3U)
#define MCP2518FD_BYTE_CiCON_OPMOD_CONFIG_VAL            (uint08_t)(4U)
#define MCP2518FD_BYTE_CiCON_OPMOD_EXTERNAL_VAL          (uint08_t)(5U)
#define MCP2518FD_BYTE_CiCON_OPMOD_NORMAL_2_VAL          (uint08_t)(6U)
#define MCP2518FD_BYTE_CiCON_OPMOD_RESTRICTED_VAL        (uint08_t)(7U)
#define MCP2518FD_BYTE_CiCON_OPMOD_NORMAL_FD             (MCP2518FD_BYTE_CiCON_OPMOD_NORMAL_FD_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_SLEEP                 (MCP2518FD_BYTE_CiCON_OPMOD_SLEEP_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_LOOPBACK              (MCP2518FD_BYTE_CiCON_OPMOD_LOOPBACK_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_LISTEN                (MCP2518FD_BYTE_CiCON_OPMOD_LISTEN_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_CONFIG                (MCP2518FD_BYTE_CiCON_OPMOD_CONFIG_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_EXTERNAL              (MCP2518FD_BYTE_CiCON_OPMOD_EXTERNAL_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_NORMAL_2              (MCP2518FD_BYTE_CiCON_OPMOD_NORMAL_2_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)
#define MCP2518FD_BYTE_CiCON_OPMOD_RESTRICTED            (MCP2518FD_BYTE_CiCON_OPMOD_NORMAL_2_VAL << MCP2518FD_BYTE_CiCON_OPMOD_POS)

#define MCP2518FD_BYTE_CiCON_REQOP_POS                   (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_REQOP_MSK                   ((uint08_t)7U << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_WRTE(DAT)             (MCP2518FD_BYTE_CiCON_REQOP_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_REQOP_POS))
#define MCP2518FD_BYTE_CiCON_REQOP_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_REQOP_MSK) >> MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_NORMAL_FD_VAL         (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_REQOP_SLEEP_VAL             (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_REQOP_LOOPBACK_VAL          (uint08_t)(2U)
#define MCP2518FD_BYTE_CiCON_REQOP_LISTEN_VAL            (uint08_t)(3U)
#define MCP2518FD_BYTE_CiCON_REQOP_CONFIG_VAL            (uint08_t)(4U)
#define MCP2518FD_BYTE_CiCON_REQOP_EXTERNAL_VAL          (uint08_t)(5U)
#define MCP2518FD_BYTE_CiCON_REQOP_NORMAL_2_VAL          (uint08_t)(6U)
#define MCP2518FD_BYTE_CiCON_REQOP_RESTRICTED_VAL        (uint08_t)(7U)
#define MCP2518FD_BYTE_CiCON_REQOP_NORMAL_FD             (MCP2518FD_BYTE_CiCON_REQOP_NORMAL_FD_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_SLEEP                 (MCP2518FD_BYTE_CiCON_REQOP_SLEEP_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_LOOPBACK              (MCP2518FD_BYTE_CiCON_REQOP_LOOPBACK_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_LISTEN                (MCP2518FD_BYTE_CiCON_REQOP_LISTEN_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_CONFIG                (MCP2518FD_BYTE_CiCON_REQOP_CONFIG_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_EXTERNAL              (MCP2518FD_BYTE_CiCON_REQOP_EXTERNAL_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_NORMAL_2              (MCP2518FD_BYTE_CiCON_REQOP_NORMAL_2_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)
#define MCP2518FD_BYTE_CiCON_REQOP_RESTRICTED            (MCP2518FD_BYTE_CiCON_REQOP_NORMAL_2_VAL << MCP2518FD_BYTE_CiCON_REQOP_POS)

#define MCP2518FD_BYTE_CiCON_ABAT_POS                    (uint08_t)(3U)
#define MCP2518FD_BYTE_CiCON_ABAT_MSK                    ((uint08_t)1U << MCP2518FD_BYTE_CiCON_ABAT_POS)
#define MCP2518FD_BYTE_CiCON_ABAT_WRTE(DAT)              (MCP2518FD_BYTE_CiCON_ABAT_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_ABAT_POS))
#define MCP2518FD_BYTE_CiCON_ABAT_READ(REG)              (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_ABAT_MSK) >> MCP2518FD_BYTE_CiCON_ABAT_POS)
#define MCP2518FD_BYTE_CiCON_ABAT_CLEAR_VAL              (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_ABAT_ABORT_VAL              (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_ABAT_CLEAR                  (MCP2518FD_BYTE_CiCON_ABAT_CLEAR_VAL << MCP2518FD_BYTE_CiCON_ABAT_POS)
#define MCP2518FD_BYTE_CiCON_ABAT_ABORT                  (MCP2518FD_BYTE_CiCON_ABAT_ABORT_VAL << MCP2518FD_BYTE_CiCON_ABAT_POS)

#define MCP2518FD_BYTE_CiCON_TXBWS_POS                   (uint08_t)(4U)
#define MCP2518FD_BYTE_CiCON_TXBWS_MSK                   ((uint08_t)15U << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_WRTE(DAT)             (MCP2518FD_BYTE_CiCON_TXBWS_MSK & ((uint08_t)(VALUE) << MCP2518FD_BYTE_CiCON_TXBWS_POS))
#define MCP2518FD_BYTE_CiCON_TXBWS_READ(REG)             (((uint08_t)(REG) & MCP2518FD_BYTE_CiCON_TXBWS_MSK) >> MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_NO_DELAY_VAL          (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_TXBWS_2_TIMES_VAL           (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_TXBWS_4_TIMES_VAL           (uint08_t)(2U)
#define MCP2518FD_BYTE_CiCON_TXBWS_8_TIMES_VAL           (uint08_t)(3U)
#define MCP2518FD_BYTE_CiCON_TXBWS_16_TIMES_VAL          (uint08_t)(4U)
#define MCP2518FD_BYTE_CiCON_TXBWS_32_TIMES_VAL          (uint08_t)(5U)
#define MCP2518FD_BYTE_CiCON_TXBWS_64_TIMES_VAL          (uint08_t)(6U)
#define MCP2518FD_BYTE_CiCON_TXBWS_128_TIMES_VAL         (uint08_t)(7U)
#define MCP2518FD_BYTE_CiCON_TXBWS_256_TIMES_VAL         (uint08_t)(0U)
#define MCP2518FD_BYTE_CiCON_TXBWS_512_TIMES_VAL         (uint08_t)(1U)
#define MCP2518FD_BYTE_CiCON_TXBWS_1024_TIMES_VAL        (uint08_t)(2U)
#define MCP2518FD_BYTE_CiCON_TXBWS_2048_TIMES_VAL        (uint08_t)(4U)
#define MCP2518FD_BYTE_CiCON_TXBWS_4096_TIMES_VAL        (uint08_t)(15U)
#define MCP2518FD_BYTE_CiCON_TXBWS_NO_DELAY              (MCP2518FD_BYTE_CiCON_TXBWS_NO_DELAY_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_2_TIMES               (MCP2518FD_BYTE_CiCON_TXBWS_2_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_4_TIMES               (MCP2518FD_BYTE_CiCON_TXBWS_4_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_8_TIMES               (MCP2518FD_BYTE_CiCON_TXBWS_8_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_16_TIMES              (MCP2518FD_BYTE_CiCON_TXBWS_16_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_32_TIMES              (MCP2518FD_BYTE_CiCON_TXBWS_32_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_64_TIMES              (MCP2518FD_BYTE_CiCON_TXBWS_64_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_128_TIMES             (MCP2518FD_BYTE_CiCON_TXBWS_128_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_256_TIMES             (MCP2518FD_BYTE_CiCON_TXBWS_256_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_512_TIMES             (MCP2518FD_BYTE_CiCON_TXBWS_512_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_1024_TIMES            (MCP2518FD_BYTE_CiCON_TXBWS_1024_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_2048_TIMES            (MCP2518FD_BYTE_CiCON_TXBWS_2048_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)
#define MCP2518FD_BYTE_CiCON_TXBWS_4096_TIMES            (MCP2518FD_BYTE_CiCON_TXBWS_4096_TIMES_VAL << MCP2518FD_BYTE_CiCON_TXBWS_POS)

#endif /* CONTROL_MOD_MCP2518FD_BYTE_H */
