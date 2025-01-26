#ifndef LIBRARY_CONTROLLET_CAN_H
#define	LIBRARY_CONTROLLET_CAN_H

/* Include ::: Header Storage */
#include "Storage_CLASS.h"
#include "Storage_DELAY.h"

/* Declaration ::: Typedefs CAN CONTROL ------------------------------------- */
typedef struct CLOCK_BUS_CAN {
    uint08_t BRP; // BRP-1 (Baud Rate Prescaler)
    uint08_t PROPSEG; // Propagation Delay
    uint08_t PHSEG1; // Phase Segment 1
    uint08_t PHSEG2; // Phase Segment 2
    uint08_t SJW; // Syncronization Jump Width
} CanClockBus_t;

typedef struct MASK_FILTER_CAN {
    uint32_t MASK0;
    uint32_t MASK1;
    uint32_t FILTER0;
    uint32_t FILTER1;
    uint32_t FILTER2;
    uint32_t FILTER3;
    uint32_t FILTER4;
    uint32_t FILTER5;
} CanMaskFilter_t;

typedef struct CAN_TX_BUFFER_MESSAGE {
    uint32_t ID;
    uint01_t XTD;
    uint01_t REMOTE;
    uint08_t LENGTH;
    uint08_t DATA[8U];
    uint08_t PRIORITY;
} CantTxBufferMessage_t;

typedef union OPTION_RX_MESSAGE {
    uint08_t Register;

    struct {
        uint08_t FILTER : 3;
        uint01_t OVERFLOW : 1;
        uint01_t INVALID : 1;
        uint01_t DOUBLED : 1;
        uint08_t RESERVED : 2;
    } Bit;
} OptionRxMessage_t;

typedef struct CAN_RX_BUFFER_MESSAGE {
    uint32_t ID;
    uint01_t XTD;
    uint01_t REMOTE;
    uint08_t LENGTH;
    uint08_t DATA[8];
    OptionRxMessage_t OPTIONS;
} CantRxBufferMessage_t;

/* Definition ::: Macros de Control :: MCP2518FD CONTROLLER REGISTER MAP ------ */
#define MCP2518FD_CTRL_RXF0SIDH           0x00    // FILTER n STANDARD IDENTIFIER REGISTER HIGH 
#define MCP2518FD_CTRL_RXF0SIDL           0x01    // FILTER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXF0EID8           0x02    // FILTER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXF0EID0           0x03    // FILTER n EXTENDED 1 REGISTER LOW
#define MCP2518FD_CTRL_RXF1SIDH           0x04    // FILTER n STANDARD IDENTIFIER REGISTER HIGH 
#define MCP2518FD_CTRL_RXF1SIDL           0x05    // FILTER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXF1EID8           0x06    // FILTER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXF1EID0           0x07    // FILTER n EXTENDED 1 REGISTER LOW
#define MCP2518FD_CTRL_RXF2SIDH           0x08    // FILTER n STANDARD IDENTIFIER REGISTER HIGH 
#define MCP2518FD_CTRL_RXF2SIDL           0x09    // FILTER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXF2EID8           0x0A    // FILTER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXF2EID0           0x0B    // FILTER n EXTENDED 1 REGISTER LOW
#define MCP2518FD_CTRL_BFPCTRL            0x0C    // RXnBF PIN CONTROL AND STATUS REGISTER
#define MCP2518FD_CTRL_TXRTSCTRL          0x0D    // TXnRTS PIN CONTROL AND STATUS REGISTER
#define MCP2518FD_CTRL_CANSTAT0           0x0E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL0           0x0F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CTRL_RXF3SIDH           0x10    // FILTER n STANDARD IDENTIFIER REGISTER HIGH 
#define MCP2518FD_CTRL_RXF3SIDL           0x11    // FILTER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXF3EID8           0x12    // FILTER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXF3EID0           0x13    // FILTER n EXTENDED 1 REGISTER LOW
#define MCP2518FD_CTRL_RXF4SIDH           0x14    // FILTER n STANDARD IDENTIFIER REGISTER HIGH 
#define MCP2518FD_CTRL_RXF4SIDL           0x15    // FILTER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXF4EID8           0x16    // FILTER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXF4EID0           0x17    // FILTER n EXTENDED 1 REGISTER LOW
#define MCP2518FD_CTRL_RXF5SIDH           0x18    // FILTER n STANDARD IDENTIFIER REGISTER HIGH 
#define MCP2518FD_CTRL_RXF5SIDL           0x19    // FILTER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXF5EID8           0x1A    // FILTER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXF5EID0           0x1B    // FILTER n EXTENDED 1 REGISTER LOW
#define MCP2518FD_CTRL_TEC                0x1C    // TRANSMIT ERROR COUNTER REGISTER
#define MCP2518FD_CTRL_REC                0x1D    // RECEIVE ERROR COUNTER REGISTER
#define MCP2518FD_CTRL_CANSTAT1           0x1E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL1           0x1F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CTRL_RXM0SIDH           0x20    // MASK n STANDARD IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXM0SIDL           0x21    // MASK n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXM0EID8           0x22    // MASK n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXM0EID0           0x23    // MASK n EXTENDED IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXM1SIDH           0x24    // MASK n STANDARD IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXM1SIDL           0x25    // MASK n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXM1EID8           0x26    // MASK n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXM1EID0           0x27    // MASK n EXTENDED IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_CNF3               0x28    // CONFIGURATION REGISTER 3
#define MCP2518FD_CTRL_CNF2               0x29    // CONFIGURATION REGISTER 2
#define MCP2518FD_CTRL_CNF1               0x2A    // CONFIGURATION REGISTER 1
#define MCP2518FD_CTRL_CANINTE            0x2B    // CAN INTERRUPT ENABLE REGISTER
#define MCP2518FD_CTRL_CANINTF            0x2C    // CAN INTERRUPT FLAG REGISTER
#define MCP2518FD_CTRL_EFLG               0x2D    // ERROR FLAG REGISTER
#define MCP2518FD_CTRL_CANSTAT2           0x2E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL2           0x2F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CTRL_TXB0CTRL           0x30    // TRANSMIT BUFFER n CONTROL REGISTER
#define MCP2518FD_CTRL_TXB0SIDH           0x31    // TRANSMIT BUFFER n STANDARD IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_TXB0SIDL           0x32    // TRANSMIT BUFFER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_TXB0EID8           0x33    // TRANSMIT BUFFER n EXTENDED IDENTIFIER 8 REGISTER HIGH
#define MCP2518FD_CTRL_TXB0EID0           0x34    // TRANSMIT BUFFER n EXTENDED IDENTIFIER 0 REGISTER LOW
#define MCP2518FD_CTRL_TXB0DLC            0x35    // TRANSMIT BUFFER n DATA LENGTH CODE REGISTER
#define MCP2518FD_CTRL_TXB0D0             0x36    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB0D1             0x37    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB0D2             0x38    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB0D3             0x39    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB0D4             0x3A    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB0D5             0x3B    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB0D6             0x3C    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB0D7             0x3D    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_CANSTAT3           0x3E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL3           0x3F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CTRL_TXB1CTRL           0x40    // TRANSMIT BUFFER n CONTROL REGISTER
#define MCP2518FD_CTRL_TXB1SIDH           0x41    // TRANSMIT BUFFER n STANDARD IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_TXB1SIDL           0x42    // TRANSMIT BUFFER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_TXB1EID8           0x43    // TRANSMIT BUFFER n EXTENDED IDENTIFIER 8 REGISTER HIGH
#define MCP2518FD_CTRL_TXB1EID0           0x44    // TRANSMIT BUFFER n EXTENDED IDENTIFIER 0 REGISTER LOW
#define MCP2518FD_CTRL_TXB1DLC            0x45    // TRANSMIT BUFFER n DATA LENGTH CODE REGISTER
#define MCP2518FD_CTRL_TXB1D0             0x46    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB1D1             0x47    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB1D2             0x48    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB1D3             0x49    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB1D4             0x4A    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB1D5             0x4B    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB1D6             0x4C    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB1D7             0x4D    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_CANSTAT4           0x4E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL4           0x4F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CTRL_TXB2CTRL           0x50    // TRANSMIT BUFFER n CONTROL REGISTER
#define MCP2518FD_CTRL_TXB2SIDH           0x51    // TRANSMIT BUFFER n STANDARD IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_TXB2SIDL           0x52    // TRANSMIT BUFFER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_TXB2EID8           0x53    // TRANSMIT BUFFER n EXTENDED IDENTIFIER 8 REGISTER HIGH
#define MCP2518FD_CTRL_TXB2EID0           0x54    // TRANSMIT BUFFER n EXTENDED IDENTIFIER 0 REGISTER LOW
#define MCP2518FD_CTRL_TXB2DLC            0x55    // TRANSMIT BUFFER n DATA LENGTH CODE REGISTER
#define MCP2518FD_CTRL_TXB2D0             0x56    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB2D1             0x57    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB2D2             0x58    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB2D3             0x59    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB2D4             0x5A    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB2D5             0x5B    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB2D6             0x5C    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_TXB2D7             0x5D    // TRANSMIT BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_CANSTAT5           0x5E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL5           0x5F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CTRL_RXB0CTRL           0x60    // RECEIVE BUFFER 0 CONTROL REGISTER
#define MCP2518FD_CTRL_RXB0SIDH           0x61    // RECEIVE BUFFER n STANDARD IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXB0SIDL           0x62    // RECEIVE BUFFER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXB0EID8           0x63    // RECEIVE BUFFER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXB0EID0           0x64    // RECEIVE BUFFER n EXTENDED IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXB0DLC            0x65    // RECEIVE BUFFER n DATA LENGTH CODE REGISTER
#define MCP2518FD_CTRL_RXB0D0             0x66    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB0D1             0x67    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB0D2             0x68    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB0D3             0x69    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB0D4             0x6A    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB0D5             0x6B    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB0D6             0x6C    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB0D7             0x6D    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_CANSTAT6           0x6E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL6           0x6F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CTRL_RXB1CTRL           0x70    // RECEIVE BUFFER 1 CONTROL REGISTER
#define MCP2518FD_CTRL_RXB1SIDH           0x71    // RECEIVE BUFFER n STANDARD IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXB1SIDL           0x72    // RECEIVE BUFFER n STANDARD IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXB1EID8           0x73    // RECEIVE BUFFER n EXTENDED IDENTIFIER REGISTER HIGH
#define MCP2518FD_CTRL_RXB1EID0           0x74    // RECEIVE BUFFER n EXTENDED IDENTIFIER REGISTER LOW
#define MCP2518FD_CTRL_RXB1DLC            0x75    // RECEIVE BUFFER n DATA LENGTH CODE REGISTER
#define MCP2518FD_CTRL_RXB1D0             0x76    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB1D1             0x77    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB1D2             0x78    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB1D3             0x79    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB1D4             0x7A    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB1D5             0x7B    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB1D6             0x7C    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_RXB1D7             0x7D    // RECEIVE BUFFER n DATA BYTE m REGISTER
#define MCP2518FD_CTRL_CANSTAT7           0x7E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CTRL_CANCTRL7           0x7F    // CANCTRL: CAN CONTROL REGISTER

/* Definition ::: Macros de Control :: MCP2518FD CONTROL REGISTER MAP --------- */
#define MCP2518FD_CONF_BFPCTRL            0x0C
#define MCP2518FD_CONF_TXRTSCTRL          0x0D    // TXnRTS PIN CONTROL AND STATUS REGISTER
#define MCP2518FD_CONF_CANSTAT            0x0E    // CANSTAT: CAN STATUS REGISTER
#define MCP2518FD_CONF_CANCTRL            0x0F    // CANCTRL: CAN CONTROL REGISTER
#define MCP2518FD_CONF_TEC                0x1C    // TRANSMIT ERROR COUNTER REGISTER
#define MCP2518FD_CONF_REC                0x1D    // RECEIVE ERROR COUNTER REGISTER
#define MCP2518FD_CONF_CNF3               0x28    // CONFIGURATION REGISTER 3
#define MCP2518FD_CONF_CNF2               0x29    // CONFIGURATION REGISTER 2
#define MCP2518FD_CONF_CNF1               0x2A    // CONFIGURATION REGISTER 1
#define MCP2518FD_CONF_CANINTE            0x2B    // CAN INTERRUPT ENABLE REGISTER
#define MCP2518FD_CONF_CANINTF            0x2C    // CAN INTERRUPT FLAG REGISTER
#define MCP2518FD_CONF_EFLG               0x2D    // ERROR FLAG REGISTER
#define MCP2518FD_CONF_TXB0CTRL           0x30    // TRANSMIT BUFFER n CONTROL REGISTER
#define MCP2518FD_CONF_TXB1CTRL           0x40    // TRANSMIT BUFFER n CONTROL REGISTER
#define MCP2518FD_CONF_TXB2CTRL           0x50    // TRANSMIT BUFFER n CONTROL REGISTER
#define MCP2518FD_CONF_RXB0CTRL           0x60    // RECEIVE BUFFER 0 CONTROL REGISTER
#define MCP2518FD_CONF_RXB1CTRL           0x70    // RECEIVE BUFFER 0 CONTROL REGISTER

/* Definition ::: Macros de Control :: MCP2518FD COMMAD CONTROL --------------- */
#define MCP2518FD_CMD_RESET               0xC0    // Resets internal registers to the default state, sets Configuration mode
#define MCP2518FD_CMD_WRITE               0x02    // Writes data to the register beginning at the selected address
#define MCP2518FD_CMD_READ                0x03    // Reads data from the register beginning at selected address
#define MCP2518FD_CMD_BIT_MODIFY          0x05    // Allows the user to set or clear individual bits in a particular register
#define MCP2518FD_CMD_LOAD_TX_BUFFER      0x40    // When loading a transmit buffer, reduces the overhead of a normal WRITE command by placing the Address Pointer at one of six locations, as indicated by ?a,b,c?.
#define MCP2518FD_CMD_REQUEST_TO_SEND     0x80    // Instructs controller to begin message transmission sequence for any of the transmit buffers
#define MCP2518FD_CMD_READ_RX_BUFFER      0x90    // When reading a receive buffer, reduces the overhead of a normal READ command by placing the Address Pointer at one of four locations, as indicated by ?n,m?.
#define MCP2518FD_CMD_READ_STATUS         0xA0    // Quick polling command that reads several status bits for transmit and receive functions
#define MCP2518FD_CMD_RX_STATUS           0xB0    // Quick polling command that indicates filter match and message type (standard, extended and/or remote) of received message

#define MCP2518FD_BUF_RXB0SIDH            0x00    // Receive Buffer 0, Start at RXB0SIDH
#define MCP2518FD_BUF_RXB1SIDH            0x01    // Receive Buffer 1, Start at RXB1SIDH
#define MCP2518FD_BUF_RXB0D0              0x02    // Receive Buffer 0, Start at RXB0D0
#define MCP2518FD_BUF_RXB1D0              0x03    // Receive Buffer 1, Start at RXB1D0

#define MCP2518FD_LOAD_TXB0SIDH           0x00    // Receive Buffer 0, Start at TXB0SIDH
#define MCP2518FD_LOAD_TXB0D0             0x01    // Receive Buffer 0, Start at TXB0D0
#define MCP2518FD_LOAD_TXB1SIDH           0x02    // Receive Buffer 0, Start at TXB1SIDH
#define MCP2518FD_LOAD_TXB1D0             0x03    // Receive Buffer 0, Start at TXB1D0
#define MCP2518FD_LOAD_TXB2SIDH           0x04    // Receive Buffer 0, Start at TXB2SIDH
#define MCP2518FD_LOAD_TXB2D0             0x05    // Receive Buffer 0, Start at TXB2D0

#define MCP2518FD_RTS_TXB0                0x01    // Request-to-Send for TXB0
#define MCP2518FD_RTS_TXB1                0x02    // Request-to-Send for TXB1
#define MCP2518FD_RTS_TXB2                0x04    // Request-to-Send for TXB2

/* Definition ::: Macros de Control :: MCP2518FD WRITE CMD CONTROL ------------ */
#define MCP2518FD_READ_RX_BUFFER(B)       (MCP2518FD_CMD_READ_RX_BUFFER | (B << 1))
#define MCP2518FD_LOAD_TX_BUFFER(B)       (MCP2518FD_CMD_LOAD_TX_BUFFER | (B & 0x03))
#define MCP2518FD_REQUEST_TO_SEND(B)      (MCP2518FD_CMD_REQUEST_TO_SEND | (B & 0x03))

/* Definition ::: Configuration Mode Operation :: CNF1/2/3 ------------------ */
#define MCP2518FD_CNF1_CONFIG(B,J)        ((B & 0x3F) | ((J & 0x02) << 6))
#define MCP2518FD_CNF2_CONFIG(PR,P1,S,B)  ((PR & 0x03 ) | ((P1 & 0x03 ) << 3) | (S << 6) |(B << 7))
#define MCP2518FD_CNF3_CONFIG(P,W,S)      ((P & 0x03) | (W << 6) | (S << 7))

/* Definition ::: Configuration Mode Operation :: CANCTRL ------------------- */
#define MCP2518FD_REQOPE_MASK             0xE0    // Masking Data
#define MCP2518FD_REQOPE_NORMAL           0x00    // Requests Normal mode
#define MCP2518FD_REQOPE_SLEEP            0x20    // Disabled/Sleep mode
#define MCP2518FD_REQOPE_LOOP             0x40    // Requests Loopback mode
#define MCP2518FD_REQOPE_LISTEN           0x60    // Requests Listen Only mode
#define MCP2518FD_REQOPE_CONFIG           0x80    // Requests Configuration mode

#define MCP2518FD_ABORT_MASK              0x10    // Masking Data
#define MCP2518FD_ABORT_TRANSMISSIONS     0x10    // Abort All Pending Transmissions

#define MCP2518FD_ONE_SHOT_M0DE_MASK      0x08    // Masking Data
#define MCP2518FD_ONE_SHOT_M0DE_ENABLE    0x08    // Enabled; messages will only attempt to transmit one time
#define MCP2518FD_ONE_SHOT_M0DE_DISABLE   0x00    // Disabled; messages will reattempt transmission if required

#define MCP2518FD_CLK_OUT_MASK            0x08    // Masking Data
#define MCP2518FD_CLK_OUT_ENABLE          0x04    // CLKOUT pin is enabled
#define MCP2518FD_CLK_OUT_DISABLE         0x00    // CLKOUT pin is disabled (pin is in high-impedance state)

#define MCP2518FD_CLK_PRESCALERT_MASK     0x03    // Masking Data
#define MCP2518FD_CLK_PRESCALER_DIV1      0x00    // System Clock/1
#define MCP2518FD_CLK_PRESCALER_DIV2      0x01    // System Clock/2
#define MCP2518FD_CLK_PRESCALER_DIV4      0x02    // System Clock/4
#define MCP2518FD_CLK_PRESCALER_DIV6      0x04    // System Clock/8

/* Definition ::: Configuration Mode Operation :: RXB0CTRL: ----------------- */
#define MCP2518FD_RXB0_RECEIVE_ANY_MSG    0x60
#define MCP2518FD_RXB0_ENABLE_FILTERS     0x00
#define MCP2518FD_RXB0_ROLLOVER_ENABLE    0x40
#define MCP2518FD_RXB0_ROLLOVER_DISABLE   0x00
#define MCP2518FD_RXB0_FILTER_MATCH_MASK  0x01    // MASK

/* Definition ::: Configuration Mode Operation :: RXB1CTRL: ----------------- */
#define MCP2518FD_RXB1_RECEIVE_ANY_MSG    0x60
#define MCP2518FD_RXB1_ENABLE_FILTERS     0x00
#define MCP2518FD_RXB1_FILTER_MATCH_MASK  0x03    // MASK

/* Definition ::: Configuration Mode Operation :: CANINTE/CANINTF: ---------- */
#define MCP2518FD_INT_BIT_RX0I            0x01
#define MCP2518FD_INT_BIT_RX1I            0x02
#define MCP2518FD_INT_BIT_TX0I            0x04
#define MCP2518FD_INT_BIT_TX1I            0x08
#define MCP2518FD_INT_BIT_TX2I            0x10
#define MCP2518FD_INT_BIT_ERRI            0x20
#define MCP2518FD_INT_BIT_WAKI            0x40
#define MCP2518FD_INT_BIT_MERR            0x80

/* Definition ::: Configuration Mode Operation :: TXBnCTRL: ----------------- */
#define MCP2518FD_TXBnCTRL_TXP0           0x01
#define MCP2518FD_TXBnCTRL_TXP1           0x02
#define MCP2518FD_TXBnCTRL_TXP_MSK        0x03    // Mask
#define MCP2518FD_TXBnCTRL_TXREQ          0x08
#define MCP2518FD_TXBnCTRL_TXERR          0x10
#define MCP2518FD_TXBnCTRL_MLOA           0x20
#define MCP2518FD_TXBnCTRL_ABTF           0x40

/* Definition ::: Configuration Mode Operation :: TXBnDLC: ------------------ */
#define MCP2518FD_TXBnDLC(L,R)            ((L & 0x0F) | (R << 6))

/* Definition ::: Configuration Mode Operation :: RXBnDLC: ------------------ */
#define MCP2518FD_RXBnDLC_DLC(D)          (D & 0x0F)
#define MCP2518FD_RXBnDLC_XTD_RTR(D)      ((D & 0x40) >> 6)
#define MCP2518FD_RXBnDLC_STD_RTR(D)      (!!(D & 0x00000010))

/* Definition ::: Configuration Mode Operation :: EFLG: --------------------- */
#define MCP2518FD_READ_EFLG_BIT_EWARN     0x01    // Error Warning Flag bit
#define MCP2518FD_READ_EFLG_BIT_RXWAR     0x02    // Receive Error Warning Flag bit
#define MCP2518FD_READ_EFLG_BIT_TXWAR     0x04    // Transmit Error Warning Flag bit
#define MCP2518FD_READ_EFLG_BIT_RXEP      0x08    // Receive Error-Passive Flag bit
#define MCP2518FD_READ_EFLG_BIT_TXEP      0x10    // Transmit Error-Passive Flag bit
#define MCP2518FD_READ_EFLG_BIT_TXBO      0x20    // Bus-Off Error Flag bit
#define MCP2518FD_READ_EFLG_BIT_RX0OVR    0x40    // Receive Buffer 0 Overflow Flag bit
#define MCP2518FD_READ_EFLG_BIT_RX1OVR    0x80    // Receive Buffer 1 Overflow Flag bit

/* Definition ::: Configuration Mode Operation :: CMD READ STATUS: ---------- */
#define MCP2518FD_READ_STATUS_BIT_RX0IF   0x01    // (CANINTF[0]
#define MCP2518FD_READ_STATUS_BIT_RX1IF   0x02    // (CANINTF[1])
#define MCP2518FD_READ_STATUS_BIT_TX0REQ  0x04    // (TXB0CTRL[3])
#define MCP2518FD_READ_STATUS_BIT_TX0IF   0x08    // (CANINTF[2])
#define MCP2518FD_READ_STATUS_BIT_TX1REQ  0x10    // (TXB1CTRL[3])
#define MCP2518FD_READ_STATUS_BIT_TX1IF   0x20    // (CANINTF[3])
#define MCP2518FD_READ_STATUS_BIT_TX2REQ  0x40    // (TXB2CTRL[3])
#define MCP2518FD_READ_STATUS_BIT_TX2IF   0x80    // (CANINTF[4])

/* Definition ::: Configuration Mode Operation :: CDM RX STATUS: ------------ */
#define MCP2518FD_RX_STATUS_MSN_NO        0x00    // No RX message
#define MCP2518FD_RX_STATUS_MSN_RXB0      0x40    // Message in RXB0
#define MCP2518FD_RX_STATUS_MSN_RXB1      0x80    // Message in RXB1
#define MCP2518FD_RX_STATUS_MSN_BOTH      0xC0    // Messages in both buffers* Buffer 0 has higher priority; therefore, RXB0 status is reflected in bits[4:0].

#define MCP2518FD_RX_STATUS_MSN_STD       0x00    // Standard data frame
#define MCP2518FD_RX_STATUS_FRM_STD       0x08    // Standard remote frame
#define MCP2518FD_RX_STATUS_MSN_EXT       0x10    // Extended data frame
#define MCP2518FD_RX_STATUS_FRM_EXT       0x18    // Extended remote frame

#define MCP2518FD_RX_FILTER_MATCH_MASK    0x07    // MASK
#define MCP2518FD_RX_FILTER_MATCH_RXF0    0x00    // RXF0
#define MCP2518FD_RX_FILTER_MATCH_RXF1    0x01    // RXF1
#define MCP2518FD_RX_FILTER_MATCH_RXF2    0x02    // RXF2
#define MCP2518FD_RX_FILTER_MATCH_RXF3    0x03    // RXF3
#define MCP2518FD_RX_FILTER_MATCH_RXF4    0x04    // RXF4
#define MCP2518FD_RX_FILTER_MATCH_RXF5    0x05    // RXF5
#define MCP2518FD_RX_FILTER_MATCH_RXF0R   0x06    // RXF0 (rollover to RXB1)
#define MCP2518FD_RX_FILTER_MATCH_RXF1R   0x07    // RXF1 (rollover to RXB1)

/* Prototype ::: Control Functions */
uint01_t xConfigureMCP2518FD(void);

/*----------------------------------------------------------------------------*/

void vMCP2518FDWriteRegister(uint08_t Address, uint08_t Data);
uint08_t xMCP1515ReadRegister(uint08_t Address);

void vMCP2518FDPutsRegister(uint08_t Address, uint08_t *Data, uint08_t Length);
void vMCP1515GetsRegister(uint08_t Address, uint08_t *Data, uint08_t Length);

/*----------------------------------------------------------------------------*/

void vMCP2518FDBitModifyCMD(uint08_t Address, uint08_t Mask, uint08_t Data);
void vMCP2518FDLoadTXBuffer(uint08_t Buffer, uint08_t *Data, uint08_t Length);
void vMCP2518FDReadRXBuffer(uint08_t Buffer, uint08_t *Data, uint08_t Length);

/*----------------------------------------------------------------------------*/

uint08_t xMCP2518FDTxErrorCount(void);
uint08_t xMCP2518FDRxErrorCount(void);

void vMCP2518FDAbortAll(void);
void vMCP2518FDReset(void);
void vMCP2518FDRTS(uint08_t Buffer);

/*----------------------------------------------------------------------------*/

uint08_t xMCP2518FDReadStatus(void);
uint08_t xMCP2518FDRxStatus(void);

/*----------------------------------------------------------------------------*/

uint01_t xMCP2518FDSendMessasge0(CantTxBufferMessage_t *Buffer);
uint01_t xMCP2518FDSendMessasge1(CantTxBufferMessage_t *Buffer);
uint01_t xMCP2518FDSendMessasge2(CantTxBufferMessage_t *Buffer);

uint01_t xMCP2518FDReceiveMessasge0(CantRxBufferMessage_t *Buffer);
uint01_t xMCP2518FDReceiveMessasge1(CantRxBufferMessage_t *Buffer);\

#endif	/* LIBRARY_CONTROLLET_CAN_H */

