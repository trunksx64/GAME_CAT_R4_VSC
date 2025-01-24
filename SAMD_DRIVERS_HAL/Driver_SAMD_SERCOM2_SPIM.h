#ifndef DRIVER_SAMC_SERCOM2_SPIM_H
#define	DRIVER_SAMC_SERCOM2_SPIM_H

/* Include ::: Header Storage */
#include "Storage_CLASS.h"
#include "Storage_DELAY.h"

/******************************************************************************/
/* == Definition ::: Configuration Macros :: Speed SERCOM SPI == */
/******************************************************************************/
#define SERCOM2_SPI_BAUD_RATE_CALC(F_OSC,F_CLK)	(uint08_t)((F_OSC/(2U*F_CLK))-1U)
#define SERCOM2_SPI_BAUD_RATE					(500000UL)	// ((F_Clock/(2*F_Baud))-1)

/******************************************************************************/
/* == Prototype Configuration Hardware SAMC == */
/******************************************************************************/

void vDriver_SAMD_SERCOM2_SPIM_CONFIGURE(void);

void vDriver_SAMD_SERCOM2_SPIM_PUT(uint16_t DATA);
uint16_t xDriver_SAMD_SERCOM2_SPIM_GET(void);

void vDriver_SAMD_SERCOM2_SPIM_PUTS(uint08_t *BUFFER, uint08_t LENGTH);
void vDriver_SAMD_SERCOM2_SPIM_GETS(uint08_t *BUFFER, uint08_t LENGTH);

#endif	/* DRIVER_SAMC_SERCOM2_SPIM_H */

