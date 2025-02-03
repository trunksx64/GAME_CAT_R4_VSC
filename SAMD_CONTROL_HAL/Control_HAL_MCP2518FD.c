/* Include ::: Headers :: Origin */
#include "Control_HAL_MCP2518FD.h"
/* Include ::: Header Drivers */
#include "Driver_SAMD_PORT.h"
#include "Driver_SAMD_SERCOM3_SPIM.h"

/******************************************************************************/
/* == Configuration Macros = Defines Controls  == */
/******************************************************************************/
#define vCANFD_MCP2518FD_PUT(D)                vDriver_SAMD_SERCOM3_SPIM_PUT(D)
#define xCANFD_MCP2518FD_GET()                 xDriver_SAMD_SERCOM3_SPIM_GET()
#define xCANFD_MCP2518FD_PUTS(D,L)             vDriver_SAMD_SERCOM3_SPIM_PUTS(D,L)
#define xCANFD_MCP2518FD_GETS(D,L)             vDriver_SAMD_SERCOM3_SPIM_GETS(D,L)

#define vCANFD_MCP2518FD_SS_ENABLE()           CANFD_SS_CLR();	vStorage_DELAY_US(5U)
#define vCANFD_MCP2518FD_SS_DISABLE()		   CANFD_SS_SET();	vStorage_DELAY_US(5U)

/******************************************************************************/
/* == Definition ::: Config Macros MCP2518FD Commands == */
/******************************************************************************/
#define vCMD_MCP2518FD_RESET        (uint08_t)(0x0) // Resets internal registers to default state; selects Configuration mode
#define vCMD_MCP2518FD_READ         (uint08_t)(0x3) // Read SFR/RAM from address A
#define vCMD_MCP2518FD_WRITE        (uint08_t)(0x2) // Write SFR/RAM to address A
#define vCMD_MCP2518FD_READ_CRC     (uint08_t)(0xB) // Read SFR/RAM from address A. N data bytes. Two bytes CRC, CRC is calculated on C, A, N and D
#define vCMD_MCP2518FD_WRITE_CRC    (uint08_t)(0xA) // Write SFR/RAM to address A. N data bytes. Two bytes CRC, CRC is calculated on C, A, N and D
#define vCMD_MCP2518FD_WRITE_SAFE   (uint08_t)(0xC) // Write SFR/RAM to address A. Check CRC before write. CRC is calculated on C, A and D

/******************************************************************************/
/* == Development Auxiliar Functions == */

/******************************************************************************/

void vAuxliar_MCP2518FD_SEND_RESET (void) {
    /* Enable ::: Module CAN */
    vCANFD_MCP2518FD_SS_ENABLE();
    {
        /* Send ::: Command Reset */
        vCANFD_MCP2518FD_PUT(vCMD_MCP2518FD_RESET);
        vCANFD_MCP2518FD_PUT(0U);
    }
    /* Disable ::: Module CAN */
    vCANFD_MCP2518FD_SS_DISABLE();
}

void vAuxliar_MCP2518FD_WRITE_REGISTER (uint16_t ADDRESS, uint32_t DATA) {
    /* Enable ::: Module CAN */
    vCANFD_MCP2518FD_SS_ENABLE();
    {

    }
    /* Disable ::: Module CAN */
    vCANFD_MCP2518FD_SS_DISABLE();
}

uint32_t vAuxliar_MCP2518FD_READ_REGISTER (uint16_t ADDRESS) {
    /* Enable ::: Module CAN */
    vCANFD_MCP2518FD_SS_ENABLE();
    {

    }
    /* Disable ::: Module CAN */
    vCANFD_MCP2518FD_SS_DISABLE();
}

/******************************************************************************/
/* == Development Configuration Functions == */

/******************************************************************************/

void vControl_MCP2518FD_CONFIGURE (void) {


}