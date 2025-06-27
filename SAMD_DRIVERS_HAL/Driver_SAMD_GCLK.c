/* Include ::: Headers */
#include "Driver_SAMD_GCLK.h"

/******************************************************************************/
/* == Development Configuration Functions == *********************************/

/******************************************************************************/

void vDriver_SAMD_GCLK_CONFIGURE(void) {
  /* Break ::: DEBUG */
  pdNOP();

  /*--------------------------------------------------------------------------*/

  /* Clear ::: Resets all Registers in the GCLK */
  GCLK_REGS->GCLK_CTRL = GCLK_CTRL_SWRST(pdSET);
  /* While ::: Sync Register */
  while (GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY(pdSET)) {}

  /*------------------------------------------------------------------------*/

  /* Configuration ::: GCLK : Generic Clock Source 0 with 96Mhz ----------- */

  /* Configuration ::: GCLK :: GENDIV */
  GCLK_REGS->GCLK_GENDIV = (GCLK_GENDIV_ID(0U) |  // Generic Clock Generator Selection
                            GCLK_GENDIV_DIV(1U)); // Division Factor

  /* Configuration ::: GCLK :: GENCTRL */
  GCLK_REGS->GCLK_GENCTRL = (GCLK_GENCTRL_RUNSTDBY(pdCLR) | // Run in Standby
                             GCLK_GENCTRL_DIVSEL_DIV1 |     // Divide Selection
                             GCLK_GENCTRL_OE(pdCLR) |       // Output Enable
                             GCLK_GENCTRL_OOV(pdCLR) |      // Output Off Value
                             GCLK_GENCTRL_IDC(pdSET) |      // Improve Duty Cycle
                             GCLK_GENCTRL_GENEN(pdSET) |    // Generic Clock Generator Enable
                             GCLK_GENCTRL_SRC_DPLL96M |     // Source Select
                             GCLK_GENCTRL_ID(0U));          // Generic Clock Generator Selection

  /* Configuration ::: GCLK : Generic Clock Source 1 with 48Mhz ----------- */

  /* Configuration ::: GCLK :: GENDIV */
  GCLK_REGS->GCLK_GENDIV = (GCLK_GENDIV_ID(1U) |  // Generic Clock Generator Selection
                            GCLK_GENDIV_DIV(2U)); // Division Factor

  /* Configuration ::: GCLK :: GENCTRL */
  GCLK_REGS->GCLK_GENCTRL = (GCLK_GENCTRL_RUNSTDBY(pdCLR) | // Run in Standby
                             GCLK_GENCTRL_DIVSEL_DIV1 |     // Divide Selection
                             GCLK_GENCTRL_OE(pdCLR) |       // Output Enable
                             GCLK_GENCTRL_OOV(pdCLR) |      // Output Off Value
                             GCLK_GENCTRL_IDC(pdSET) |      // Improve Duty Cycle
                             GCLK_GENCTRL_GENEN(pdSET) |    // Generic Clock Generator Enable
                             GCLK_GENCTRL_SRC_DPLL96M |     // Source Select
                             GCLK_GENCTRL_ID(1U));          // Generic Clock Generator Selection

  /* Configuration ::: GCLK : Generic Clock Source 2 with 32Mhz ----------- */

  /* Configuration ::: GCLK :: GENDIV */
  GCLK_REGS->GCLK_GENDIV = (GCLK_GENDIV_ID(2U) |  // Generic Clock Generator Selection
                            GCLK_GENDIV_DIV(3U)); // Division Factor

  /* Configuration ::: GCLK :: GENCTRL */
  GCLK_REGS->GCLK_GENCTRL = (GCLK_GENCTRL_RUNSTDBY(pdCLR) | // Run in Standby
                             GCLK_GENCTRL_DIVSEL_DIV1 |     // Divide Selection
                             GCLK_GENCTRL_OE(pdCLR) |       // Output Enable
                             GCLK_GENCTRL_OOV(pdCLR) |      // Output Off Value
                             GCLK_GENCTRL_IDC(pdSET) |      // Improve Duty Cycle
                             GCLK_GENCTRL_GENEN(pdSET) |    // Generic Clock Generator Enable
                             GCLK_GENCTRL_SRC_DPLL96M |     // Source Select
                             GCLK_GENCTRL_ID(2U));          // Generic Clock Generator Selection

  /* Configuration ::: GCLK : Generic Clock Source 3 with 24Mhz ----------- */

  /* Configuration ::: GCLK :: GENDIV */
  GCLK_REGS->GCLK_GENDIV = (GCLK_GENDIV_ID(3U) |  // Generic Clock Generator Selection
                            GCLK_GENDIV_DIV(4U)); // Division Factor

  /* Configuration ::: GCLK :: GENCTRL */
  GCLK_REGS->GCLK_GENCTRL = (GCLK_GENCTRL_RUNSTDBY(pdCLR) | // Run in Standby
                             GCLK_GENCTRL_DIVSEL_DIV1 |     // Divide Selection
                             GCLK_GENCTRL_OE(pdCLR) |       // Output Enable
                             GCLK_GENCTRL_OOV(pdCLR) |      // Output Off Value
                             GCLK_GENCTRL_IDC(pdSET) |      // Improve Duty Cycle
                             GCLK_GENCTRL_GENEN(pdSET) |    // Generic Clock Generator Enable
                             GCLK_GENCTRL_SRC_DPLL96M |     // Source Select
                             GCLK_GENCTRL_ID(3U));          // Generic Clock Generator Selection

  /* Configuration ::: GCLK : Generic Clock Source 4 with 16Mhz ----------- */

  /* Configuration ::: GCLK :: GENDIV */
  GCLK_REGS->GCLK_GENDIV = (GCLK_GENDIV_ID(4U) |  // Generic Clock Generator Selection
                            GCLK_GENDIV_DIV(6U)); // Division Factor

  /* Configuration ::: GCLK :: GENCTRL */
  GCLK_REGS->GCLK_GENCTRL = (GCLK_GENCTRL_RUNSTDBY(pdCLR) | // Run in Standby
                             GCLK_GENCTRL_DIVSEL_DIV1 |     // Divide Selection
                             GCLK_GENCTRL_OE(pdCLR) |       // Output Enable
                             GCLK_GENCTRL_OOV(pdCLR) |      // Output Off Value
                             GCLK_GENCTRL_IDC(pdSET) |      // Improve Duty Cycle
                             GCLK_GENCTRL_GENEN(pdSET) |    // Generic Clock Generator Enable
                             GCLK_GENCTRL_SRC_DPLL96M |     // Source Select
                             GCLK_GENCTRL_ID(4U));          // Generic Clock Generator Selection

  /* Configuration ::: GCLK : Generic Clock Source 5 with 8Mhz ------------ */

  /* Configuration ::: GCLK :: GENDIV */
  GCLK_REGS->GCLK_GENDIV = (GCLK_GENDIV_ID(5U) |   // Generic Clock Generator Selection
                            GCLK_GENDIV_DIV(12U)); // Division Factor

  /* Configuration ::: GCLK :: GENCTRL */
  GCLK_REGS->GCLK_GENCTRL = (GCLK_GENCTRL_RUNSTDBY(pdCLR) | // Run in Standby
                             GCLK_GENCTRL_DIVSEL_DIV1 |     // Divide Selection
                             GCLK_GENCTRL_OE(pdCLR) |       // Output Enable
                             GCLK_GENCTRL_OOV(pdCLR) |      // Output Off Value
                             GCLK_GENCTRL_IDC(pdSET) |      // Improve Duty Cycle
                             GCLK_GENCTRL_GENEN(pdSET) |    // Generic Clock Generator Enable
                             GCLK_GENCTRL_SRC_DPLL96M |     // Source Select
                             GCLK_GENCTRL_ID(5U));          // Generic Clock Generator Selection
}
