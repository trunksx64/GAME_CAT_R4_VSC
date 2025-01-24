/* Setting ::: Header :: Threads */
#include "Settings_TASKS.h"

/******************************************************************************/
/* == Development Interruptions Hardware SAMC = TRAPS == */
/******************************************************************************/

/*- (Non-Maskable Interrupt) - */
void NonMaskableInt_Handler(void) {
    /* Loop ::: Failure... */
    while (RUN_LOOP) {
        /* NOP ::: Instruction... */
        NOP();
    }
}

/*- (HardFault Interrupt) - */
void HardFault_Handler(void) {
    /* Variables ::: Locales */
    volatile uint8_t CauseFault;

    /* GET ::: IPSR*/
    CauseFault = __get_IPSR();

    /* Loop ::: Failure... */
    while (RUN_LOOP) {
        /* GET ::: Fault */
        (void) CauseFault;
        /* NOP ::: Instruction... */
        NOP();
    }
}

/*- (Non-Maskable Interrupt) - */
void Dummy_Handler(void) {
    /* Loop ::: Failure... */
    while (RUN_LOOP) {
        /* NOP ::: Instruction... */
        NOP();
    }
}
