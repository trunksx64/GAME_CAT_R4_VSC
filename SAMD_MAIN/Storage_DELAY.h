#ifndef STORAGE_DELAY_H
#define STORAGE_DELAY_H

/* Configuration Main Settings */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Configuration Macros = Values for Delays == */
/******************************************************************************/

#define vStorage_DELAY_SE(D) vStorage_DELAY((uint32_t)(((uint64_t)D) * (FSC_CLOCK_SYSTEM) / 7UL / 1ULL))
#define vStorage_DELAY_MS(D) vStorage_DELAY((uint32_t)(((uint64_t)D) * (FSC_CLOCK_SYSTEM) / 7UL / 1000ULL))
#define vStorage_DELAY_US(D) vStorage_DELAY((uint32_t)(((uint64_t)D) * (FSC_CLOCK_SYSTEM) / 7UL / 1000000ULL))

/******************************************************************************/
/* == Prototype Delay in Memory Ram for ARM == */
/******************************************************************************/

__attribute__((section(".RamFunc"))) void vStorage_DELAY(volatile uint32_t VALUE);

#endif /* STORAGE_DELAY_H */
