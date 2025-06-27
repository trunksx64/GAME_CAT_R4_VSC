#ifndef DRIVER_SAMD_GCLK_H
#define DRIVER_SAMD_GCLK_H

/* Include ::: Header Storage */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Configuration Macros = GCLK = Config Speed Clock == */
/******************************************************************************/

#define configGCLK0_96MHZ (uint32_t)(96000000UL)
#define configGCLK1_48MHZ (uint32_t)(48000000UL)
#define configGCLK2_32MHZ (uint32_t)(32000000UL)
#define configGCLK3_24MHZ (uint32_t)(24000000UL)
#define configGCLK4_16MHZ (uint32_t)(16000000UL)
#define configGCLK5_8MHZ  (uint32_t)(8000000UL)

/******************************************************************************/
/* == Prototype Configuration Hardware STM32 == */
/******************************************************************************/

void vDriver_SAMD_GCLK_CONFIGURE(void);

#endif /* DRIVER_SAMD_GCLK_H */
