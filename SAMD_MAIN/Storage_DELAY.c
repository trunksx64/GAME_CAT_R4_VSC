/* Include ::: Headers */
#include "Storage_DELAY.h"

/******************************************************************************/
/* == Development Delay in Memory Ram for ARM == */
/******************************************************************************/

/* Function ::: Into Memory Ram */
__attribute__((section(".RamFunc"))) void vStorage_DELAY(volatile uint32_t VALUE) {
    /* Decrement ::: Value for Loop Delay */
    __asm volatile("   LOOP: DMB          \n"
            "   SUB r0, r0, #1     \n"
            "   CMP r0, #0         \n"
            "   BNE LOOP           \n");
}
