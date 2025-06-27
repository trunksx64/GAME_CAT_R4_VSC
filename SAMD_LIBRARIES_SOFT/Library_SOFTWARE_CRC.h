#ifndef LIBRARY_SOFTWARE_CRC_H
#define	LIBRARY_SOFTWARE_CRC_H

/* Configuration Main Settings */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Prototype Configuration Functions == */
/******************************************************************************/

uint01_t xLibray_POLYNOMIAL_CRC01(uint01_t PARITY, uint08_t BUFFER);
uint08_t xLibray_POLYNOMIAL_CRC03(uint08_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH);
uint08_t xLibray_POLYNOMIAL_CRC08(uint08_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH);
uint16_t xLibray_POLYNOMIAL_CRC16(uint16_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH);
uint32_t xLibray_POLYNOMIAL_CRC32(uint32_t CRC_VAL, uint08_t *pxBUFFER, uint16_t LENGTH);

#endif	/* LIBRARY_SOFTWARE_CRC_H */

