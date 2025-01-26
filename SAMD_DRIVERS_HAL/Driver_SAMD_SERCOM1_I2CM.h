#ifndef DRIVER_SAMD_SERCOM1_I2CM_H
#define	DRIVER_SAMD_SERCOM1_I2CM_H

/* Include ::: Header Storage */
#include "Storage_CLASS.h"

/******************************************************************************/
/* == Definition ::: Configuration Macros :: Speed I2C == */
/******************************************************************************/
#define SERCOM1_I2C_BAUD_RATE_CALC(F_OSC,F_SCL)	(uint08_t)((((F_OSC/(F_SCL/10UL))-(F_OSC/1000000UL)-100UL)/2UL)/10UL)
#define SERCOM1_I2C_BAUD_RATE					(100000UL) // (((F_OSC/F_SCL)-(F_OSC*Trise)-10)/2)

/******************************************************************************/
/* == Definition ::: Configuration Macros :: Format Messages == */
/******************************************************************************/
#define SERCOM1_I2C_STATUS_NONE                 (uint08_t)(0U)
#define SERCOM1_I2C_STATUS_NACK                 (uint08_t)(1U)
#define SERCOM1_I2C_STATUS_ACK                  (uint08_t)(2U)
#define SERCOM1_I2C_ERROR_LENERR                (uint08_t)(3U)
#define SERCOM1_I2C_ERROR_SEXTTOUT              (uint08_t)(4U)
#define SERCOM1_I2C_ERROR_MEXTTOUT              (uint08_t)(5U)
#define SERCOM1_I2C_ERROR_CLKHOLD               (uint08_t)(6U)
#define SERCOM1_I2C_ERROR_LOWTOUT               (uint08_t)(7U)
#define SERCOM1_I2C_ERROR_ARBLOST               (uint08_t)(8U)
#define SERCOM1_I2C_ERROR_BUSERR                (uint08_t)(9U)

/******************************************************************************/
/* == Prototype Configuration Hardware SAMC == */
/******************************************************************************/

void vDriver_SAMD_SERCOM1_I2CM_CONFIGURE(void);

uint08_t xDriver_SAMD_SERCOM1_I2C_GET_ERROR(void);
uint01_t xDriver_SAMD_SERCOM1_I2C_POLL(uint8_t ADDRESS);

void vDriver_SAMD_SERCOM1_I2C_SET_ACK(uint01_t ACK);
void vDriver_SAMD_SERCOM1_I2C_SET_STOP(void);

uint08_t xDriver_SAMD_SERCOM1_I2C_SET_START(uint08_t ADDRESS);
uint08_t xDriver_SAMD_SERCOM1_I2C_SET_RESTART(void);

uint08_t xDriver_SAMD_SERCOM1_I2C_PUT(uint08_t DATA);
uint01_t xDriver_SAMD_SERCOM1_I2C_GET(uint08_t *DATA);

uint01_t xDriver_SAMD_SERCOM1_I2C_PUTS(uint08_t *DATA, uint16_t LENGTH);
uint01_t xDriver_SAMD_SERCOM1_I2C_GETS(uint08_t *DATA, uint16_t LENGTH);

#endif	/* DRIVER_SAMD_SERCOM1_I2CM_H */

