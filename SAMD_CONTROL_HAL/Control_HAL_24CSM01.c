/* Include ::: Headers :: Origin */
#include "Control_HAL_24CSM01.h"
/* Include ::: Header Drivers */
#include "Driver_SAMD_SERCOM1_I2CM.h"
/* Include ::: Header Storage */
#include "Storage_DELAY.h"

/******************************************************************************/
/* == Configuration Macros = Defines Controls  == */
/******************************************************************************/
#define xCONTROL_HAL_EEP_24CM01_POLL(D)          xDriver_SAMD_SERCOM1_I2C_POLL(D)
#define xCONTROL_HAL_EEP_24CM01_SET_ACK(D)       vDriver_SAMD_SERCOM1_I2C_SET_ACK(D)
#define xCONTROL_HAL_EEP_24CM01_SET_STOP()       vDriver_SAMD_SERCOM1_I2C_SET_STOP()
#define xCONTROL_HAL_EEP_24CM01_PUT_START(D)     xDriver_SAMD_SERCOM1_I2C_SET_START(D)
#define xCONTROL_HAL_EEP_24CM01_PUT_RESTART()    xDriver_SAMD_SERCOM1_I2C_SET_RESTART()
#define xCONTROL_HAL_EEP_24CM01_PUT_BYTE(D)      xDriver_SAMD_SERCOM1_I2C_PUT(D)
#define xCONTROL_HAL_EEP_24CM01_GET_BYTE(D)      xDriver_SAMD_SERCOM1_I2C_GET(D)
#define xCONTROL_HAL_EEP_24CM01_PUT_BUFFER(D,L)  xDriver_SAMD_SERCOM1_I2C_PUTS(D,L)
#define xCONTROL_HAL_EEP_24CM01_GET_BUFFER(D,L)  xDriver_SAMD_SERCOM1_I2C_GETS(D,L)

/******************************************************************************/
/* == Development Configuration Functions == */
/******************************************************************************/

uint01_t xControl_HAL_EEP_24CM01_CHECK(void) {
    /* Return ::: ACK */
    return (xCONTROL_HAL_EEP_24CM01_POLL(CONTROL_HAL_EEP_24CM01_DEVICE_WRITE));
}

uint01_t xControl_HAL_EEP_24CM01_BLANK(uint08_t BANK, uint08_t VALUE) {
}

uint01_t xControl_HAL_EEP_24CM01_PUT(uint08_t BANK, uint08_t ADDRESS, uint08_t DATA) {
}

uint08_t xControl_HAL_EEP_24CM01_GET(uint08_t BANK, uint08_t ADDRESS) {
}

uint01_t xControl_HAL_EEP_24CM01_PUTS(uint08_t BANK, uint08_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH) {
}

uint01_t xControl_HAL_EEP_24CM01_GETS(uint08_t BANK, uint08_t ADDRESS, uint08_t *pxBUFFER, uint08_t LENGTH) {
}
