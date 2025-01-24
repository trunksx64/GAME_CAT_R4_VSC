/* Include ::: Headers */
#include "Driver_SAMD_SYSCTRL.h"

/******************************************************************************/
/* == Development Configuration Functions == */

/******************************************************************************/

void vDriver_SAMD_SYSCTRL_CONFIGURE(void) {
    /* Break ::: DEBUG */
    pdNOP();

    /*--------------------------------------------------------------------------*/

    /* Configure ::: SYSCTRL : XOSC32Khz */
    SYSCTRL_REGS->SYSCTRL_XOSC32K = (
            SYSCTRL_XOSC32K_WRTLOCK(pdCLR) | // Write Lock
            SYSCTRL_XOSC32K_STARTUP_CYCLE32 | // Oscillator Start-Up Time
            SYSCTRL_XOSC32K_ONDEMAND(pdCLR) | // On Demand Control
            SYSCTRL_XOSC32K_RUNSTDBY(pdCLR) | // Run in Standby
            SYSCTRL_XOSC32K_AAMPEN(pdCLR) | // Automatic Amplitude Control
            SYSCTRL_XOSC32K_EN32K(pdSET) | // 32kHz Output Enable
            SYSCTRL_XOSC32K_EN1K(pdCLR) | // 1kHz Output Enable
            SYSCTRL_XOSC32K_XTALEN(pdSET) | // Crystal Oscillator
            SYSCTRL_XOSC32K_ENABLE(pdSET)); // Oscillator Enable

    /* While ::: Stable XOSC32K */
    while (!(SYSCTRL_REGS->SYSCTRL_PCLKSR & SYSCTRL_PCLKSR_XOSC32KRDY(pdSET))) {
    }

    /*--------------------------------------------------------------------------*/

    /* Configuration ::: SYSCTRL :: DPLLRATIO : FDPLL96M=(48Mhz) */
    SYSCTRL_REGS->SYSCTRL_DPLLRATIO = (SYSCTRL_DPLLRATIO_LDRFRAC(11U) | // Loop Divider Ratio Fractional Part
            SYSCTRL_DPLLRATIO_LDR(2928U)); // Loop Divider Ratio FOR 96Mhz

    /* Configuration ::: SYSCTRL :: DPLLCTRLB */
    SYSCTRL_REGS->SYSCTRL_DPLLCTRLB = (
            SYSCTRL_DPLLCTRLB_DIV(1U) | // Clock Divider    
            SYSCTRL_DPLLCTRLB_LBYPASS(pdSET) | // Lock Bypass
            SYSCTRL_DPLLCTRLB_LTIME_10MS | // Time-out if no lock within 10ms
            SYSCTRL_DPLLCTRLB_REFCLK_REF0 | // XOSC32K clock reference
            SYSCTRL_DPLLCTRLB_WUF(pdSET) | // Wake Up Fast
            SYSCTRL_DPLLCTRLB_LPEN(pdCLR) | // Low-Power Enable
            SYSCTRL_DPLLCTRLB_FILTER_DEFAULT); // Proportional Integral Filter Selection

    /* Configuration ::: SYSCTRL :: DPLLCTRLA */
    SYSCTRL_REGS->SYSCTRL_DPLLCTRLA = (SYSCTRL_DPLLCTRLA_ONDEMAND(pdCLR) | // The DPLL is always on, if enabled
            SYSCTRL_DPLLCTRLA_RUNSTDBY(pdCLR) | // The DPLL is disabled in standby
            SYSCTRL_DPLLCTRLA_ENABLE(pdSET)); // DPLL Enable

    /* While ::: Enable PLL */
    while (!(SYSCTRL_REGS->SYSCTRL_DPLLSTATUS & SYSCTRL_DPLLSTATUS_ENABLE(pdSET))) {
    }
    /* While ::: The DPLL is Trying to reach the target frequency */
    while (!((SYSCTRL_REGS->SYSCTRL_DPLLSTATUS & SYSCTRL_DPLLSTATUS_LOCK(pdSET)) || (SYSCTRL_REGS->SYSCTRL_DPLLSTATUS & SYSCTRL_DPLLSTATUS_CLKRDY(pdSET)))) {
    }
}
