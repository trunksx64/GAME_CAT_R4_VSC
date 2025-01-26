///* Include ::: Header File */
//#include "Library_Controllet_CAN.h"
///* Include :::: Driver Header */
//#include "Driver_MUX_PIN_CTRL.h"
//#include "Driver_SERCOM1_SPI.h"
//
///* Definition ::: Macros de Control :: Function Read/Write SPI -------------- */
//#define vWriteMCP2518FD(Data)         vSendSercom1SPI(Data)
//#define xReadMCP2518FD()              vReceiveSercom1SPI()
//
///* Definition ::: Values MASKs & FILTER To Buffers -------------------------- */
//const CanMaskFilter_t MASKFILTERValue = {
//    .MASK0 = 0x07FF,
//    .MASK0 = 0x07FF,
//    .FILTER0 = 0x0000,
//    .FILTER0 = 0x0000,
//    .FILTER0 = 0x0000,
//    .FILTER0 = 0x0000,
//    .FILTER0 = 0x0000,
//    .FILTER0 = 0x0000,
//};
//
///* Definition ::: Macros de Control :: Speed BUS CAN ------------------------ */
//#define FREQ_100Khz         0 // Speed 100Khz
//#define FREQ_250Khz         1 // Speed 100Khz
//#define FREQ_500Khz         2 // Speed 100Khz
//#define SPEED_BUS_CAN       FREQ_100Khz
//
///* Variables ::: Globales :: Parametros en PROGM :: Quanta 8Tq -------------- */
//const CanClockBus_t CANBaud[3] = {
//    {.BRP = 4, .PROPSEG = 1, .PHSEG1 = 3, .PHSEG2 = 3, .SJW = 1}, // 100Khz (8Mhz/BRP=4)
//    {.BRP = 1, .PROPSEG = 1, .PHSEG1 = 3, .PHSEG2 = 3, .SJW = 1}, // 250khz (8Mhz/BRP=1)
//    {.BRP = 0, .PROPSEG = 1, .PHSEG1 = 8, .PHSEG2 = 3, .SJW = 1}, // 500Khz (8Mhz/BRP=0) 
//};
//
///* Functions ::: Auxiliars -------------------------------------------------- */
//uint32_t xWriteIDCANModule(uint1_t XTD, uint32_t Value);
//uint1_t xReadIDCANModule(uint32_t *Register, uint32_t Value);
//
///* Development ::: Control Functions */
//uint1_t xConfigureMCP2518FD(void) {
//    /* Locals ::: Variables  */
//    CanMaskFilter_t MASKFILTERConfig;
//
//    /* Reset ::: Module */
//    vMCP2518FDAbortAll();
//    vMCP2518FDReset();
//
//    /* Setting ::: Configuration Mode MCP2518FD ------------------------------- */
//
//    /* Set ::: Set Configuration Mode */
//    vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANCTRL, MCP2518FD_REQOPE_MASK, MCP2518FD_REQOPE_CONFIG);
//    /* While ::: Set Configuration Mode */
//    while (MCP2518FD_REQOPE_CONFIG != (xMCP1515ReadRegister(MCP2518FD_CONF_CANSTAT) & MCP2518FD_REQOPE_MASK));
//
//    /* Write ::: Baud Rate CAN */
//    vMCP2518FDWriteRegister(MCP2518FD_CONF_CNF1, MCP2518FD_CNF1_CONFIG((CANBaud[SPEED_BUS_CAN].BRP), (CANBaud[SPEED_BUS_CAN].SJW - 1)));
//    vMCP2518FDWriteRegister(MCP2518FD_CONF_CNF2, MCP2518FD_CNF2_CONFIG((CANBaud[SPEED_BUS_CAN].PROPSEG - 1), (CANBaud[SPEED_BUS_CAN].PHSEG1 - 1), pdSET, pdSET));
//    vMCP2518FDWriteRegister(MCP2518FD_CONF_CNF3, MCP2518FD_CNF3_CONFIG((CANBaud[SPEED_BUS_CAN].PHSEG2 - 1), pdSET, pdCLR));
//
//    /* Configuration ::: Acceptance MASK for Buffers0/1 */
//    vMCP2518FDWriteRegister(MCP2518FD_CONF_RXB0CTRL, MCP2518FD_RXB0_ENABLE_FILTERS | MCP2518FD_RXB0_ROLLOVER_DISABLE);
//    vMCP2518FDWriteRegister(MCP2518FD_CONF_RXB1CTRL, MCP2518FD_RXB1_ENABLE_FILTERS);
//
//    /* Configuration ::: MASK to Buffer0/1 STANDARD ID */
//    MASKFILTERConfig.MASK0 = xWriteIDCANModule(pdCLR, MASKFILTERValue.MASK0);
//    MASKFILTERConfig.MASK1 = xWriteIDCANModule(pdCLR, MASKFILTERValue.MASK1);
//
//    /* Configuration ::: FILTERs to Buffer0/1/2/3/4/5 STANDARD ID */
//    MASKFILTERConfig.FILTER0 = xWriteIDCANModule(pdCLR, MASKFILTERValue.FILTER0);
//    MASKFILTERConfig.FILTER1 = xWriteIDCANModule(pdCLR, MASKFILTERValue.FILTER1);
//    MASKFILTERConfig.FILTER2 = xWriteIDCANModule(pdCLR, MASKFILTERValue.FILTER2);
//    MASKFILTERConfig.FILTER3 = xWriteIDCANModule(pdCLR, MASKFILTERValue.FILTER3);
//    MASKFILTERConfig.FILTER4 = xWriteIDCANModule(pdCLR, MASKFILTERValue.FILTER4);
//    MASKFILTERConfig.FILTER5 = xWriteIDCANModule(pdCLR, MASKFILTERValue.FILTER5);
//
//    /* Write ::: MASK to Buffer0/1 */
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXM0SIDH, (void*) &MASKFILTERConfig.MASK0, sizeof (uint32_t));
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXM1SIDH, (void*) &MASKFILTERConfig.MASK1, sizeof (uint32_t));
//
//    /* Write ::: FILTER to Buffer0/1/2/3/4/5 */
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXF0SIDH, (void*) &MASKFILTERConfig.FILTER0, sizeof (uint32_t));
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXF1SIDH, (void*) &MASKFILTERConfig.FILTER1, sizeof (uint32_t));
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXF2SIDH, (void*) &MASKFILTERConfig.FILTER2, sizeof (uint32_t));
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXF3SIDH, (void*) &MASKFILTERConfig.FILTER3, sizeof (uint32_t));
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXF4SIDH, (void*) &MASKFILTERConfig.FILTER4, sizeof (uint32_t));
//    vMCP2518FDPutsRegister(MCP2518FD_CTRL_RXF5SIDH, (void*) &MASKFILTERConfig.FILTER5, sizeof (uint32_t));
//
//    vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANCTRL, MCP2518FD_REQOPE_MASK, MCP2518FD_REQOPE_NORMAL);
//    /* While ::: Set Configuration Mode */
//    while (MCP2518FD_REQOPE_NORMAL != (xMCP1515ReadRegister(MCP2518FD_CONF_CANSTAT) & MCP2518FD_REQOPE_MASK));
//
//    /* Configuration ::: Interrupts :: Enable Int Receive Buffer0/1 */
//    vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANINTE, (MCP2518FD_INT_BIT_RX0I | MCP2518FD_INT_BIT_RX1I), (MCP2518FD_INT_BIT_RX0I | MCP2518FD_INT_BIT_RX1I));
//    /* Configuration ::: Interrupts :: Clear Flag Receive Buffer0/1 */
//    vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANINTF, (MCP2518FD_INT_BIT_RX0I | MCP2518FD_INT_BIT_RX1I), pdCLR);
//}
//
///*----------------------------------------------------------------------------*/
//
//void vMCP2518FDWriteRegister(uint8_t Address, uint8_t Data) {
//    /* Enable ::: Module CAN */
//    EXT_CAN_SS_ENABLE();
//    /* Send ::: Command Write */
//    vWriteMCP2518FD(MCP2518FD_CMD_WRITE);
//    /* Send ::: Address Byte */
//    vWriteMCP2518FD(Address);
//    /* Send ::: Data Byte */
//    vWriteMCP2518FD(Data);
//    /* Disable ::: Module CAN */
//    EXT_CAN_SS_DISABLE();
//}
//
//uint8_t xMCP1515ReadRegister(uint8_t Address) {
//    /* Locals ::: Variables  */
//    uint8_t Receive = 0;
//
//    /* Enable ::: Module CAN */
//    EXT_CAN_SS_ENABLE();
//    /* Send ::: Command Write */
//    vWriteMCP2518FD(MCP2518FD_CMD_READ);
//    /* Send ::: Address Byte */
//    vWriteMCP2518FD(Address);
//    /* Receive ::: Data Byte */
//    Receive = xReadMCP2518FD();
//    /* Disable ::: Module CAN */
//    EXT_CAN_SS_DISABLE();
//
//    /* Return ::: Data */
//    return (Receive);
//}
//
//void vMCP2518FDPutsRegister(uint8_t Address, uint8_t *Data, uint8_t Length) {
//    /* Check ::: Length */
//    if (Length) {
//        /* Enable ::: Module CAN */
//        EXT_CAN_SS_ENABLE();
//        /* Send ::: Command Write */
//        vWriteMCP2518FD(MCP2518FD_CMD_WRITE);
//        /* Send ::: Address Byte */
//        vWriteMCP2518FD(Address);
//        /* Write ::: Buffer SPI to Send */
//        while (Length--) vWriteMCP2518FD(*Data++);
//        /* Disable ::: Module CAN */
//        EXT_CAN_SS_DISABLE();
//    } else;
//}
//
//void vMCP1515GetsRegister(uint8_t Address, uint8_t *Data, uint8_t Length) {
//    /* Check ::: Length */
//    if (Length) {
//        /* Enable ::: Module CAN */
//        EXT_CAN_SS_ENABLE();
//        /* Send ::: Command Write */
//        vWriteMCP2518FD(MCP2518FD_CMD_READ);
//        /* Send ::: Address Byte */
//        vWriteMCP2518FD(Address);
//        /* Write ::: Buffer SPI to Send */
//        while (Length--) *Data++ = xReadMCP2518FD();
//        /* Disable ::: Module CAN */
//        EXT_CAN_SS_DISABLE();
//    } else;
//}
//
///*----------------------------------------------------------------------------*/
//
//void vMCP2518FDBitModifyCMD(uint8_t Address, uint8_t Mask, uint8_t Data) {
//    /* Enable ::: Module CAN */
//    EXT_CAN_SS_ENABLE();
//    /* Send ::: Command Write */
//    vWriteMCP2518FD(MCP2518FD_CMD_BIT_MODIFY);
//    /* Send ::: Address Byte */
//    vWriteMCP2518FD(Address);
//    /* Send ::: Mask Byte */
//    vWriteMCP2518FD(Mask);
//    /* Send ::: Data Byte */
//    vWriteMCP2518FD(Data);
//    /* Disable ::: Module CAN */
//    EXT_CAN_SS_DISABLE();
//}
//
//void vMCP2518FDLoadTXBuffer(uint8_t Buffer, uint8_t *Data, uint8_t Length) {
//    /* Check ::: Length */
//    if (Length) {
//        /* Enable ::: Module CAN */
//        EXT_CAN_SS_ENABLE();
//        /* Send ::: Command Write */
//        vWriteMCP2518FD(MCP2518FD_LOAD_TX_BUFFER(Buffer));
//        /* Write ::: Buffer SPI to Send */
//        while (Length--) vWriteMCP2518FD(*Data++);
//        /* Disable ::: Module CAN */
//        EXT_CAN_SS_DISABLE();
//    } else;
//}
//
//void vMCP2518FDReadRXBuffer(uint8_t Buffer, uint8_t *Data, uint8_t Length) {
//    /* Check ::: Length */
//    if (Length) {
//        /* Enable ::: Module CAN */
//        EXT_CAN_SS_ENABLE();
//        /* Send ::: Command Write */
//        vWriteMCP2518FD(MCP2518FD_READ_RX_BUFFER(Buffer));
//        /* Write ::: Buffer SPI to Send */
//        while (Length--) vWriteMCP2518FD(*Data++);
//        /* Disable ::: Module CAN */
//        EXT_CAN_SS_DISABLE();
//    } else;
//}
//
///*----------------------------------------------------------------------------*/
//
//uint8_t xMCP2518FDRxErrorCount(void) {
//    /* Read ::; Count Rx Errors */
//    return (xMCP1515ReadRegister(MCP2518FD_CONF_REC));
//}
//
//void vMCP2518FDAbortAll(void) {
//    /* Abort ::: All Messages */
//    vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANCTRL, MCP2518FD_ABORT_MASK, MCP2518FD_ABORT_TRANSMISSIONS);
//}
//
//void vMCP2518FDReset(void) {
//    /* Enable ::: Module CAN */
//    EXT_CAN_SS_ENABLE();
//    /* Send ::: Command Reset */
//    vWriteMCP2518FD(MCP2518FD_CMD_RESET);
//    /* Disable ::: Module CAN */
//    EXT_CAN_SS_DISABLE();
//}
//
//void vMCP2518FDRTS(uint8_t Buffer) {
//    /* Enable ::: Module CAN */
//    EXT_CAN_SS_ENABLE();
//    /* Send ::: Command Reset */
//    vWriteMCP2518FD(MCP2518FD_REQUEST_TO_SEND(Buffer));
//    /* Disable ::: Module CAN */
//    EXT_CAN_SS_DISABLE();
//}
//
///*----------------------------------------------------------------------------*/
//
//uint8_t xMCP2518FDReadStatus(void) {
//    /* Locals ::: Variables  */
//    uint8_t Receive = 0;
//
//    /* Enable ::: Module CAN */
//    EXT_CAN_SS_ENABLE();
//    /* Send ::: Command Reset */
//    vWriteMCP2518FD(MCP2518FD_CMD_READ_STATUS);
//    /* Receive ::: Data Byte */
//    Receive = xReadMCP2518FD();
//    /* Disable ::: Module CAN */
//    EXT_CAN_SS_DISABLE();
//
//    /* Return ::: Data */
//    return (Receive);
//}
//
//uint8_t xMCP2518FDRxStatus(void) {
//    /* Locals ::: Variables  */
//    uint8_t Receive = 0;
//
//    /* Enable ::: Module CAN */
//    EXT_CAN_SS_ENABLE();
//    /* Send ::: Command Reset */
//    vWriteMCP2518FD(MCP2518FD_CMD_RX_STATUS);
//    /* Receive ::: Data Byte */
//    Receive = xReadMCP2518FD();
//    /* Disable ::: Module CAN */
//    EXT_CAN_SS_DISABLE();
//
//    /* Return ::: Data */
//    return (Receive);
//}
//
///*----------------------------------------------------------------------------*/
//
//uint1_t xMCP2518FDSendMessasge0(CantTxBufferMessage_t *Buffer) {
//    /* Locals ::: Variables  */
//    uint32_t ID = 0;
//
//    /* Check ::: Buffer is not Zero */
//    if (Buffer) {
//        /* Check ::: Message Transmit Request */
//        if (!!(xMCP2518FDReadStatus() & MCP2518FD_READ_STATUS_BIT_TX0REQ)) {
//            /* Return ::: Buffer Busy */
//            return (pdCLR);
//        } else {
//            /* Set ::: Priority Buffer */
//            vMCP2518FDBitModifyCMD(MCP2518FD_CONF_TXB0CTRL, MCP2518FD_TXBnCTRL_TXP_MSK, Buffer->PRIORITY);
//
//            /* Check ::: STD or XTD Message */
//            if (Buffer->XTD) ID = xWriteIDCANModule(pdSET, Buffer->ID);
//            else ID = xWriteIDCANModule(pdCLR, Buffer->ID);
//
//            /* Load ::: STD or XTD Message */
//            vMCP2518FDLoadTXBuffer(MCP2518FD_LOAD_TXB0SIDH, (void*) &ID, sizeof (uint32_t));
//            /* Set ::: Length of Data & Remote Frame*/
//            vMCP2518FDWriteRegister(MCP2518FD_CTRL_TXB0DLC, MCP2518FD_TXBnDLC(Buffer->LENGTH, Buffer->REMOTE));
//            /* Load ::: Buffer Data[8] */
//            vMCP2518FDLoadTXBuffer(MCP2518FD_LOAD_TXB0D0, (void*) Buffer->DATA, Buffer->LENGTH);
//            /* Send ::: Message Request-to-Send */
//            vMCP2518FDRTS(MCP2518FD_RTS_TXB0);
//
//            /* Return ::: Buffer Write */
//            return (pdSET);
//        }
//    } else {
//        /* Return ::: Buffer NULL */
//        return (pdCLR);
//    }
//}
//
//uint1_t xMCP2518FDSendMessasge1(CantTxBufferMessage_t *Buffer) {
//    /* Locals ::: Variables  */
//    uint32_t ID = 0;
//
//    /* Check ::: Buffer is not Zero */
//    if (Buffer) {
//        /* Check ::: Message Transmit Request */
//        if (!!(xMCP2518FDReadStatus() & MCP2518FD_READ_STATUS_BIT_TX1REQ)) {
//            /* Return ::: Buffer Busy */
//            return (pdCLR);
//        } else {
//            /* Set ::: Priority Buffer */
//            vMCP2518FDBitModifyCMD(MCP2518FD_CONF_TXB1CTRL, MCP2518FD_TXBnCTRL_TXP_MSK, Buffer->PRIORITY);
//
//            /* Check ::: STD or XTD Message */
//            if (Buffer->XTD) ID = xWriteIDCANModule(pdSET, Buffer->ID);
//            else ID = xWriteIDCANModule(pdCLR, Buffer->ID);
//
//            /* Load ::: STD or XTD Message */
//            vMCP2518FDLoadTXBuffer(MCP2518FD_LOAD_TXB1SIDH, (void*) &ID, sizeof (uint32_t));
//            /* Set ::: Length of Data & Remote Frame*/
//            vMCP2518FDWriteRegister(MCP2518FD_CTRL_TXB1DLC, MCP2518FD_TXBnDLC(Buffer->LENGTH, Buffer->REMOTE));
//            /* Load ::: Buffer Data[8] */
//            vMCP2518FDLoadTXBuffer(MCP2518FD_LOAD_TXB1D0, (void*) Buffer->DATA, Buffer->LENGTH);
//            /* Send ::: Message Request-to-Send */
//            vMCP2518FDRTS(MCP2518FD_RTS_TXB1);
//
//            /* Return ::: Buffer Write */
//            return (pdSET);
//        }
//    } else {
//        /* Return ::: Buffer NULL */
//        return (pdCLR);
//    }
//}
//
//uint1_t xMCP2518FDSendMessasge2(CantTxBufferMessage_t *Buffer) {
//    /* Locals ::: Variables  */
//    uint32_t ID = 0;
//
//    /* Check ::: Buffer is not Zero */
//    if (Buffer) {
//
//        /* Check ::: Message Transmit Request */
//        if (!!(xMCP2518FDReadStatus() & MCP2518FD_READ_STATUS_BIT_TX2REQ)) {
//            /* Return ::: Buffer Busy */
//            return (pdCLR);
//        } else {
//            /* Set ::: Priority Buffer */
//            vMCP2518FDBitModifyCMD(MCP2518FD_CONF_TXB2CTRL, MCP2518FD_TXBnCTRL_TXP_MSK, Buffer->PRIORITY);
//
//            /* Check ::: STD or XTD Message */
//            if (Buffer->XTD) ID = xWriteIDCANModule(pdSET, Buffer->ID);
//            else ID = xWriteIDCANModule(pdCLR, Buffer->ID);
//
//            /* Load ::: STD or XTD Message */
//            vMCP2518FDLoadTXBuffer(MCP2518FD_LOAD_TXB2SIDH, (void*) &ID, sizeof (uint32_t));
//            /* Set ::: Length of Data & Remote Frame*/
//            vMCP2518FDWriteRegister(MCP2518FD_CTRL_TXB2DLC, MCP2518FD_TXBnDLC(Buffer->LENGTH, Buffer->REMOTE));
//            /* Load ::: Buffer Data[8] */
//            vMCP2518FDLoadTXBuffer(MCP2518FD_LOAD_TXB2D0, (void*) Buffer->DATA, Buffer->LENGTH);
//            /* Send ::: Message Request-to-Send */
//            vMCP2518FDRTS(MCP2518FD_RTS_TXB2);
//
//            /* Return ::: Buffer Write */
//            return (pdSET);
//        }
//    } else {
//
//        /* Return ::: Buffer NULL */
//        return (pdCLR);
//    }
//}
//
//uint1_t xMCP2518FDReceiveMessasge0(CantRxBufferMessage_t *Buffer) {
//    /* Locals ::: Variables  */
//    uint32_t IDRXBO = 0;
//    uint32_t IDMSN0 = 0;
//
//    /* Check ::: Buffer is not Zero */
//    if (Buffer) {
//        /* Clear ::: Buffer */
//        memset((void*) Buffer, pdCLR, sizeof (CantRxBufferMessage_t));
//
//        /* Check ::: Buffer Wait Data Receive */
//        if (!!(xMCP2518FDReadStatus() & MCP2518FD_READ_STATUS_BIT_RX0IF) && !!(xMCP2518FDRxStatus() & MCP2518FD_RX_STATUS_MSN_RXB0)) {
//            /* Copy ::: Options */
//            Buffer->OPTIONS.Bit.FILTER = (xMCP1515ReadRegister(MCP2518FD_CTRL_RXB0CTRL) & MCP2518FD_RXB0_FILTER_MATCH_MASK);
//            Buffer->OPTIONS.Bit.OVERFLOW = !!(xMCP1515ReadRegister(MCP2518FD_CTRL_EFLG) & MCP2518FD_READ_EFLG_BIT_RX0OVR);
//
//            /* Clear ::: Interruption Flag */
//            vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANINTF, MCP2518FD_INT_BIT_RX0I, pdCLR);
//
//            /* Read ::: STD or XTD Message */
//            vMCP2518FDReadRXBuffer(MCP2518FD_CTRL_RXB0SIDH, (void*) &IDRXBO, sizeof (uint32_t));
//            /* Ajust ::: STD or XTD Message */
//            Buffer->XTD = xReadIDCANModule((void*) &IDMSN0, IDRXBO);
//            /* Ajust ::: Data Length */
//            Buffer->LENGTH = MCP2518FD_RXBnDLC_DLC(xMCP1515ReadRegister(MCP2518FD_CTRL_RXB0DLC)); // Data Length Code bits
//
//            /* Ajust ::: Frame Remote Transmission */
//            if (Buffer->XTD) Buffer->REMOTE = MCP2518FD_RXBnDLC_XTD_RTR(xMCP1515ReadRegister(MCP2518FD_CTRL_RXB0DLC)); // Extended Frame Remote Transmission 
//            else Buffer->REMOTE = MCP2518FD_RXBnDLC_STD_RTR(IDRXBO);
//
//            /* Read ::: Buffer Data[8] */
//            vMCP2518FDReadRXBuffer(MCP2518FD_CTRL_RXB0D0, (void*) Buffer->DATA, Buffer->LENGTH);
//
//        } else {
//            /* Return ::: Buffer Empthy */
//            return (pdCLR);
//        }
//
//        /* Copy ::: Options */
//        if (!!(xMCP1515ReadRegister(MCP2518FD_CTRL_CANINTF) & MCP2518FD_INT_BIT_MERR)) {
//            /* Clear ::: Interruption Flag */
//            vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANINTF, MCP2518FD_INT_BIT_MERR, pdCLR);
//            /* Set ::: Invalid Message Receive */
//            Buffer->OPTIONS.Bit.INVALID = pdSET;
//        } else;
//    } else {
//
//        /* Return ::: Buffer NULL */
//        return (pdCLR);
//    }
//}
//
//uint1_t xMCP2518FDReceiveMessasge1(CantRxBufferMessage_t *Buffer) {
//    /* Locals ::: Variables  */
//    uint32_t IDRXB1 = 0;
//    uint32_t IDMSN1 = 0;
//
//    /* Check ::: Buffer is not Zero */
//    if (Buffer) {
//        /* Clear ::: Buffer */
//        memset((void*) Buffer, pdCLR, sizeof (CantRxBufferMessage_t));
//
//        /* Check ::: Buffer Wait Data Receive */
//        if (!!(xMCP2518FDReadStatus() & MCP2518FD_READ_STATUS_BIT_RX1IF) && !!(xMCP2518FDRxStatus() & MCP2518FD_RX_STATUS_MSN_RXB1)) {
//            /* Copy ::: Options */
//            Buffer->OPTIONS.Bit.FILTER = (xMCP1515ReadRegister(MCP2518FD_CTRL_RXB1CTRL) & MCP2518FD_RXB1_FILTER_MATCH_MASK);
//            Buffer->OPTIONS.Bit.OVERFLOW = !!(xMCP1515ReadRegister(MCP2518FD_CTRL_EFLG) & MCP2518FD_READ_EFLG_BIT_RX1OVR);
//
//            /* Clear ::: Interruption Flag */
//            vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANINTF, MCP2518FD_INT_BIT_RX1I, pdCLR);
//
//            /* Read ::: STD or XTD Message */
//            vMCP2518FDReadRXBuffer(MCP2518FD_CTRL_RXB1SIDH, (void*) &IDRXB1, sizeof (uint32_t));
//            /* Ajust ::: STD or XTD Message */
//            Buffer->XTD = xReadIDCANModule((void*) &IDMSN1, IDRXB1);
//            /* Ajust ::: Data Length */
//            Buffer->LENGTH = MCP2518FD_RXBnDLC_DLC(xMCP1515ReadRegister(MCP2518FD_CTRL_RXB1DLC)); // Data Length Code bits
//
//            /* Ajust ::: Frame Remote Transmission */
//            if (Buffer->XTD) Buffer->REMOTE = MCP2518FD_RXBnDLC_XTD_RTR(xMCP1515ReadRegister(MCP2518FD_CTRL_RXB1DLC)); // Extended Frame Remote Transmission 
//            else Buffer->REMOTE = MCP2518FD_RXBnDLC_STD_RTR(IDRXB1);
//
//            /* Read ::: Buffer Data[8] */
//            vMCP2518FDReadRXBuffer(MCP2518FD_CTRL_RXB1D0, (void*) Buffer->DATA, Buffer->LENGTH);
//
//        } else {
//            /* Return ::: Buffer Empthy */
//            return (pdCLR);
//        }
//
//        /* Copy ::: Options */
//        if (!!(xMCP1515ReadRegister(MCP2518FD_CTRL_CANINTF) & MCP2518FD_INT_BIT_MERR)) {
//            /* Clear ::: Interruption Flag */
//            vMCP2518FDBitModifyCMD(MCP2518FD_CONF_CANINTF, MCP2518FD_INT_BIT_MERR, pdCLR);
//            /* Set ::: Invalid Message Receive */
//            Buffer->OPTIONS.Bit.INVALID = pdSET;
//        } else;
//    } else {
//
//        /* Return ::: Buffer NULL */
//        return (pdCLR);
//    }
//}
//
///*----------------------------------------------------------------------------*/
//
//uint32_t xWriteIDCANModule(uint1_t XTD, uint32_t Value) {
//    /* Locals ::: Variables  */
//    uint32_t Register = 0;
//
//    if (XTD == pdSET) {// Set EXT Remote ID
//        /* Copy SIDH ::: EXT ID Message... */
//        *((uint8_t *) (&Register) + 0) = (*((uint8_t *) (&Value) + 2) >> 5);
//        *((uint8_t *) (&Register) + 0) |= (*((uint8_t *) (&Value) + 3) << 3);
//        /* Copy SIDL ::: EXT ID Message... */
//        *((uint8_t *) (&Register) + 1) = ((*((uint8_t *) (&Value) + 2) << 3) & 0xE0);
//        *((uint8_t *) (&Register) + 1) |= (*((uint8_t *) (&Value) + 2) & 0x3);
//        /* Set ::: Accept extended ID messages */
//        *((uint8_t *) (&Register) + 1) |= 0x08;
//        /* Copy EIDH ::: EXT ID Message... */
//        *((uint8_t *) (&Register) + 2) = *((uint8_t *) (&Value) + 1);
//        /* Copy EIDL ::: EXT ID Message... */
//        *((uint8_t *) (&Register) + 3) = *((uint8_t *) (&Value) + 0);
//    } else {// Set STD Remote ID
//
//        /* Copy SIDH ::: STD ID Message... */
//        *((uint8_t *) (&Register) + 0) = (uint8_t) (Value >> 3);
//        /* Copy SIDL ::: STD ID Message... */
//        *((uint8_t *) (&Register) + 1) = (uint8_t) (Value << 5);
//    }
//}
//
//uint1_t xReadIDCANModule(uint32_t *Register, uint32_t Value) {
//    /* Check ::: STD or EXT ID and Copy Data... */
//    if (*(Register + 1) & 0x08) { // Extend ID        
//        *((uint8_t *) (Value) + 2) = (uint8_t) (*Register << 5);
//        *((uint8_t *) (Value) + 3) = (uint8_t) (*Register++ >> 3);
//        *((uint8_t *) (Value) + 2) |= (uint8_t) (*Register & 0x03);
//        *((uint8_t *) (Value) + 2) |= (uint8_t) ((*Register++ & 0xE0) >> 3);
//        *((uint8_t *) (Value) + 1) = (uint8_t) * Register++;
//        *((uint8_t *) (Value) + 0) = (uint8_t) * Register;
//
//        /* Return ::: XTD ID */
//        return (pdSET);
//    } else { // STD ID        
//        *((uint8_t *) (Value) + 0) = (uint8_t) (*Register << 3);
//        *((uint8_t *) (Value) + 1) |= (uint8_t) ((*Register++ & 0xE0) >> 5);
//        *((uint8_t *) (Value) + 0) |= (uint8_t) (*Register >> 5);
//        *((uint8_t *) (Value) + 2) = 0;
//        *((uint8_t *) (Value) + 3) = 0;
//
//        /* Return ::: STD ID */
//        return (pdCLR);
//    }
//}
