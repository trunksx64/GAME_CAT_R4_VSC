/* Include ::: Headers */
#include "Driver_SAMD_PM.h"

/******************************************************************************/
/* == Development Configuration Functions == */
/******************************************************************************/

void vDriver_SAMD_PM_CONFIGURE(void) {
  /* Break ::: DEBUG */
  pdNOP();

  /*--------------------------------------------------------------------------*/

  /* Set Flash wait states for 48 MHz - 3.3V */
  NVMCTRL_REGS->NVMCTRL_CTRLB |= NVMCTRL_CTRLB_RWS(2U);

  /*--------------------------------------------------------------------------*/

  /* Setting ::: Clock Select */
  PM_REGS->PM_CPUSEL = (PM_CPUSEL_CPUDIV_DIV2); // CPU Prescaler Selection

  /* Setting ::: Clock Select APBx */
  PM_REGS->PM_APBASEL = (PM_APBASEL_APBADIV_DIV2); // APBA Prescaler Selection
  PM_REGS->PM_APBBSEL = (PM_APBBSEL_APBBDIV_DIV2); // APBB Prescaler Selection
  PM_REGS->PM_APBCSEL = (PM_APBCSEL_APBCDIV_DIV2); // APBC Prescaler Selection
}
