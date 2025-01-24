#ifndef DRIVER_SAMD_ADC_H
#define	DRIVER_SAMD_ADC_H

/* Include ::: Header Storage */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Prototype Configuration Hardware STM32 == */
/******************************************************************************/

void vDriver_SAMD_ADC_CONFIGURE(void);
uint16_t xDriver_SAMD_ADC_READ(uint08_t INPUT);

#endif	/* DRIVER_SAMD_ADC_H */

