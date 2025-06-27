#ifndef LIBRARY_CONTROLLET_CAN_H
#define LIBRARY_CONTROLLET_CAN_H

/* Include ::: Header Storage */
#include "Storage_CLASS.h"
#include "Storage_DELAY.h"

/******************************************************************************/
/* == Declaration :::  Typedefs Speed CAN CONTROL  == */
/******************************************************************************/

typedef struct CLOCK_BUS_CAN {
  uint08_t BRP;   // BRP-1 (Baud Rate Prescaler)
  uint08_t TSEG1; // Time Segment 1
  uint08_t TSEG2; // Time Segment 2
  uint08_t SJW;   // Syncronization Jump Width
} xCAN_Clock_Bus_t;

typedef struct CAN_TX_BUFFER_MESSAGE {
  uint32_t ID;        // Value Standard/Extended ID
  uint01_t XTD;       // Select Standard/Extended ID
  uint01_t RTR;       // Select Remote Transmit Request
  uint01_t FDF;       // Select FD Format selection
  uint01_t BRS;       // Select Bit Rate Switch, CAN FD frame
  uint08_t LENGTH;    // Set Data Length Code
  uint08_t DATA[64U]; // Put Data Buffer
} xCAN_TX_Buffer_Message_t;

/******************************************************************************/
/* == Prototype Configuration Functions == */
/******************************************************************************/

void vControl_MCP2518FD_CONFIGURE(void);
void vControl_MCP2518FD_SEND_TXQ_MESSAGE(xCAN_TX_Buffer_Message_t *pxBUFFER);

#endif /* LIBRARY_CONTROLLET_CAN_H */