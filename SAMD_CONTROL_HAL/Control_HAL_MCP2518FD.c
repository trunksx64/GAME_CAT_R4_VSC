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

#define vCANFD_MCP2518FD_SS_ENABLE()           CANFD_SS_CLR(); vStorage_DELAY_US(5U)
#define vCANFD_MCP2518FD_SS_DISABLE()		   vStorage_DELAY_US(5U); CANFD_SS_SET()	

/******************************************************************************/
/* == Definition ::: Config Macros MCP2518FD Commands == */
/******************************************************************************/
#define CMD_MCP2518FD_RESET        (uint08_t)(0x0) // Resets internal registers to default state; selects Configuration mode
#define CMD_MCP2518FD_READ         (uint08_t)(0x3) // Read SFR/RAM from address A
#define CMD_MCP2518FD_WRITE        (uint08_t)(0x2) // Write SFR/RAM to address A
#define CMD_MCP2518FD_READ_CRC     (uint08_t)(0xB) // Read SFR/RAM from address A. N data bytes. Two bytes CRC, CRC is calculated on C, A, N and D
#define CMD_MCP2518FD_WRITE_CRC    (uint08_t)(0xA) // Write SFR/RAM to address A. N data bytes. Two bytes CRC, CRC is calculated on C, A, N and D
#define CMD_MCP2518FD_WRITE_SAFE   (uint08_t)(0xC) // Write SFR/RAM to address A. Check CRC before write. CRC is calculated on C, A and D

/******************************************************************************/
/* == Development Auxiliar Functions == */

/******************************************************************************/

void vAuxliar_MCP2518FD_RESET (void) {
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

uint32_t xAuxliar_MCP2518FD_GET (uint16_t ADDRESS) {
    /* Variables ::: Locals */
    uint32_t DATA = 0U;

    /* Enable ::: Module CAN */
    vCANFD_MCP2518FD_SS_ENABLE();
    {
        /* Send ::: Command Read */
        vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_READ << 4U) | ((ADDRESS >> 8U) & 0x0F));
        vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
        *((uint08_t*) & DATA + 0U) = xCANFD_MCP2518FD_GET();
        *((uint08_t*) & DATA + 1U) = xCANFD_MCP2518FD_GET();
        *((uint08_t*) & DATA + 2U) = xCANFD_MCP2518FD_GET();
        *((uint08_t*) & DATA + 3U) = xCANFD_MCP2518FD_GET();
    }
    /* Disable ::: Module CAN */
    vCANFD_MCP2518FD_SS_DISABLE();

    /* Return ::: Data */
    return (DATA);
}

void vAuxliar_MCP2518FD_GETS (uint16_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGHT) {
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

void vAuxliar_MCP2518FD_PUT (uint16_t ADDRESS, uint32_t DATA) {
    /* Enable ::: Module CAN */
    vCANFD_MCP2518FD_SS_ENABLE();
    {
        /* Send ::: Command Write */
        vCANFD_MCP2518FD_PUT((CMD_MCP2518FD_WRITE << 4U) | ((ADDRESS >> 8U) & 0x0F));
        vCANFD_MCP2518FD_PUT(ADDRESS & 0xFF);
        vCANFD_MCP2518FD_PUT(*((uint08_t*) & DATA + 0U));
        vCANFD_MCP2518FD_PUT(*((uint08_t*) & DATA + 1U));
        vCANFD_MCP2518FD_PUT(*((uint08_t*) & DATA + 2U));
        vCANFD_MCP2518FD_PUT(*((uint08_t*) & DATA + 3U));
    }
    /* Disable ::: Module CAN */
    vCANFD_MCP2518FD_SS_DISABLE();
}

void vAuxliar_MCP2518FD_PUTS (uint16_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGHT) {
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

/******************************************************************************/
/* == Development Configuration Functions == */
/******************************************************************************/

void vControl_MCP2518FD_CONFIGURE (void) {
    /* Send ::: Reset Command*/
    vAuxliar_MCP2518FD_RESET();
}