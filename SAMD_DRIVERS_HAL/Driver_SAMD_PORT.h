#ifndef DRIVER_SAMD_GPIO_H
#define DRIVER_SAMD_GPIO_H

/* Include ::: Header Storage */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Configuration Macros = GPIO = PORT_GROUP[p] == */
/******************************************************************************/
#define GPIO_PORTA             (uint08_t)(0U)
#define GPIO_PORTB             (uint08_t)(1U)

/******************************************************************************/
/* == Configuration Macros = GPIO = PORT_PINCFG[p] == */
/******************************************************************************/
#define GPIO_P00               (uint08_t)(0U)
#define GPIO_P01               (uint08_t)(1U)
#define GPIO_P02               (uint08_t)(2U)
#define GPIO_P03               (uint08_t)(3U)
#define GPIO_P04               (uint08_t)(4U)
#define GPIO_P05               (uint08_t)(5U)
#define GPIO_P06               (uint08_t)(6U)
#define GPIO_P07               (uint08_t)(7U)
#define GPIO_P08               (uint08_t)(8U)
#define GPIO_P09               (uint08_t)(9U)
#define GPIO_P10               (uint08_t)(10U)
#define GPIO_P11               (uint08_t)(11U)
#define GPIO_P12               (uint08_t)(12U)
#define GPIO_P13               (uint08_t)(13U)
#define GPIO_P14               (uint08_t)(14U)
#define GPIO_P15               (uint08_t)(15U)
#define GPIO_P16               (uint08_t)(16U)
#define GPIO_P17               (uint08_t)(17U)
#define GPIO_P18               (uint08_t)(18U)
#define GPIO_P19               (uint08_t)(19U)
#define GPIO_P20               (uint08_t)(20U)
#define GPIO_P21               (uint08_t)(21U)
#define GPIO_P22               (uint08_t)(22U)
#define GPIO_P23               (uint08_t)(23U)
#define GPIO_P24               (uint08_t)(24U)
#define GPIO_P25               (uint08_t)(25U)
#define GPIO_P26               (uint08_t)(26U)
#define GPIO_P27               (uint08_t)(27U)
#define GPIO_P28               (uint08_t)(28U)
#define GPIO_P29               (uint08_t)(29U)
#define GPIO_P30               (uint08_t)(30U)
#define GPIO_P31               (uint08_t)(31U)

/******************************************************************************/
/* == Configuration Macros = GPIO = Write/Read :: Outputs/Inputs == */
/******************************************************************************/
#define PUT_PORT_CLR_BIT(P, B) (PORT_REGS->GROUP[P].PORT_OUTSET = B)
#define PUT_PORT_SET_BIT(P, B) (PORT_REGS->GROUP[P].PORT_OUTCLR = B)
#define PUT_PORT_TGL_BIT(P, B) (PORT_REGS->GROUP[P].PORT_OUTTGL = B)
#define GET_PORT_BIT(P, B)     (!!(PORT_REGS->GROUP[P].PORT_OUT & B))

/******************************************************************************/
/* == Configuration Macros = GPIO = PORT_PMUX[n] == */
/******************************************************************************/
#define GPIO_MUX00             (uint08_t)(0U)
#define GPIO_MUX01             (uint08_t)(0U)
#define GPIO_MUX02             (uint08_t)(1U)
#define GPIO_MUX03             (uint08_t)(1U)
#define GPIO_MUX04             (uint08_t)(2U)
#define GPIO_MUX05             (uint08_t)(2U)
#define GPIO_MUX06             (uint08_t)(3U)
#define GPIO_MUX07             (uint08_t)(3U)
#define GPIO_MUX08             (uint08_t)(4U)
#define GPIO_MUX09             (uint08_t)(4U)
#define GPIO_MUX10             (uint08_t)(5U)
#define GPIO_MUX11             (uint08_t)(5U)
#define GPIO_MUX12             (uint08_t)(6U)
#define GPIO_MUX13             (uint08_t)(6U)
#define GPIO_MUX14             (uint08_t)(7U)
#define GPIO_MUX15             (uint08_t)(7U)
#define GPIO_MUX16             (uint08_t)(8U)
#define GPIO_MUX17             (uint08_t)(8U)
#define GPIO_MUX18             (uint08_t)(9U)
#define GPIO_MUX19             (uint08_t)(9U)
#define GPIO_MUX20             (uint08_t)(10U)
#define GPIO_MUX21             (uint08_t)(10U)
#define GPIO_MUX22             (uint08_t)(11U)
#define GPIO_MUX23             (uint08_t)(11U)
#define GPIO_MUX24             (uint08_t)(12U)
#define GPIO_MUX25             (uint08_t)(12U)
#define GPIO_MUX26             (uint08_t)(13U)
#define GPIO_MUX27             (uint08_t)(13U)
#define GPIO_MUX28             (uint08_t)(14U)
#define GPIO_MUX29             (uint08_t)(14U)
#define GPIO_MUX30             (uint08_t)(15U)
#define GPIO_MUX31             (uint08_t)(15U)

/******************************************************************************/
/* == Configuration Macros = GPIO = PORT_PMUX[n]=PMUXO[x],PMUXE[x] == */
/******************************************************************************/
#define DEV_MUXA               (uint08_t)(0U)
#define DEV_MUXB               (uint08_t)(1U)
#define DEV_MUXC               (uint08_t)(2U)
#define DEV_MUXD               (uint08_t)(3U)
#define DEV_MUXE               (uint08_t)(4U)
#define DEV_MUXF               (uint08_t)(5U)
#define DEV_MUXG               (uint08_t)(6U)
#define DEV_MUXH               (uint08_t)(7U)
#define DEV_MUXI               (uint08_t)(8U)

/******************************************************************************/
/* == Configuration Macros = GPIO = Led Outputs == */
/******************************************************************************/

/* Configuration ::: Ports(Pins) :: LED(BUSY) : (PA15) ------------------- */
#define LED_BUSY_CLR()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA30)
#define LED_BUSY_SET()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA30)
#define LED_BUSY_TGL()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA30)

/* Configuration ::: Ports(Pins) :: LED(CTRL) : (PA08) ------------------- */
#define LED_CTRL_CLR()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA31)
#define LED_CTRL_SET()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA31)
#define LED_CTRL_TGL()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA31)

/******************************************************************************/
/* == Configuration Macros = GPIO = Mux Outputs == */
/******************************************************************************/

/* Configuration ::: Ports(Pins) :: MUXA : (PA20) ------------------- */
#define MUX_PINA_CLR()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA20)
#define MUX_PINA_SET()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA20)
#define MUX_PINA_TGL()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA20)
#define MUX_PINA_OUT(D)         (((!!D) ? (MUX_PINA_SET()) : (MUX_PINA_CLR())))

/* Configuration ::: Ports(Pins) :: MUXB : (PA20) ------------------- */
#define MUX_PINB_CLR()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA19)
#define MUX_PINB_SET()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA19)
#define MUX_PINB_TGL()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA19)
#define MUX_PINB_OUT(D)         (((!!D) ? (MUX_PINB_SET()) : (MUX_PINB_CLR())))

/* Configuration ::: Ports(Pins) :: MUXC : (PA20) ------------------- */
#define MUX_PINC_CLR()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA18)
#define MUX_PINC_SET()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA18)
#define MUX_PINC_TGL()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA18)
#define MUX_PINC_OUT(D)         (((!!D) ? (MUX_PINC_SET()) : (MUX_PINC_CLR())))

/******************************************************************************/
/* == Definition ::: Configuration Macros for Inputs Control == */
/******************************************************************************/

/* Control ::: Read Senses */
#define JOYSTICK_BUTTON_Z()     !!(PORT_REGS->GROUP[GPIO_PORTA].PORT_IN & PORT_PA03)

/******************************************************************************/
/* == Configuration Macros = GPIO = FLASH Outputs == */
/******************************************************************************/

/* Configuration ::: Ports(Pins) :: MUXA : (PA20) ------------------- */
#define FLASH_SS_CLR()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA07)
#define FLASH_SS_SET()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA07)
#define FLASH_SS_TGL()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA07)
#define FLASH_SS_OUT(D)         (((!!D) ? (FLASH_SS_SET()) : (FLASH_SS_CLR())))

/******************************************************************************/
/* == Configuration Macros = GPIO = SRAM Outputs == */
/******************************************************************************/

/* Configuration ::: Ports(Pins) :: MUXA : (PA20) ------------------- */
#define SRAM_SS_CLR()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA08)
#define SRAM_SS_SET()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA08)
#define SRAM_SS_TGL()          (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA08)
#define SRAM_SS_OUT(D)         (((!!D) ? (SRAM_SS_SET()) : (SRAM_SS_CLR())))

/******************************************************************************/
/* == Configuration Macros = GPIO = SRAM Outputs == */
/******************************************************************************/

/* Configuration ::: Ports(Pins) :: MUXA : (PA20) ------------------- */
#define CANFD_SS_CLR()         (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA28)
#define CANFD_SS_SET()         (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA28)
#define CANFD_SS_TGL()         (PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTTGL = PORT_PA28)
#define CANFD_SS_OUT(D)        (((!!D) ? (CANFD_SS_SET()) : (CANFD_SS_CLR())))

/******************************************************************************/
/* == Prototype Configuration Hardware SAMD :: GPIO == */
/******************************************************************************/

void vDriver_SAMD_PORT_CONFIGURE(void);

#endif /* DRIVER_SAMD_GPIO_H */
