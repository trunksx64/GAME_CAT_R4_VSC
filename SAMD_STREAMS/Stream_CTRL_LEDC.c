/* Include ::: Header :: Stream */
#include "Stream_CTRL_LEDC.h"
/* Include ::: Header :: Threads */
#include "Settings_TASKS.h"

/******************************************************************************/
/* == Development Control Functions = LED == */
/******************************************************************************/

uint01_t xStream_LED_COMMAND(uint08_t LED, uint08_t COMMAND, uint32_t TIME) {
  /* Local ::: Variables */
  uint01_t RETURN = pdCLR;
  xStream_Led_Config_t COMPILE_BUFFER = {0U};

  /* CHK :::: Parameters */
  if (COMMAND && (COMMAND <= CMD_LED_TMR)) {
    /* Compiled ::: Data to Send to Buffer */
    COMPILE_BUFFER.NUMBER_LED = LED;
    COMPILE_BUFFER.COMMAND = COMMAND;
    COMPILE_BUFFER.TIMER = TIME;

    /* PUT ::: Data to Queue :: GET_CONTROL_LEDS */
    RETURN = xQueueSend(xStatementSystemOS.QUEUE.CONF_LED, &COMPILE_BUFFER, 1U);
  }

  /* Return ::: Control */
  return (RETURN);
}
