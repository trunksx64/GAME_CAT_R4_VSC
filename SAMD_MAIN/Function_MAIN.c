/* Setting ::: Header :: Storage */
#include "Settings_TASKS.h"

/******************************************************************************/
/* == Development Main Functions == */

/******************************************************************************/

int main (void) {
    /* BRK ::: DEBUG */
    pdNOP();

    /*--------------------------------------------------------------------------*/

    /* Setting ::: Hardware :: Clock System ------------------------------------*/
    vDriver_SAMD_PM_CONFIGURE();
    vDriver_SAMD_SYSCTRL_CONFIGURE();
    vDriver_SAMD_GCLK_CONFIGURE();
    /* Setting ::: Hardware :: GPIO --------------------------------------------*/
    vDriver_SAMD_PORT_CONFIGURE();
    /* Setting ::: Hardware :: ADC ---------------------------------------------*/
    vDriver_SAMD_ADC_CONFIGURE();
    /* Setting ::: Hardware :: SERCOM1 (I2C) -----------------------------------*/
    vDriver_SAMD_SERCOM1_I2CM_CONFIGURE();
    /* Setting ::: Hardware :: SERCOM2 (SPI) -----------------------------------*/
    vDriver_SAMD_SERCOM2_SPIM_CONFIGURE();
    /* Setting ::: Hardware :: SERCOM2 (SPI) -----------------------------------*/
    vDriver_SAMD_SERCOM3_SPIM_CONFIGURE();
    /* Setting ::: Hardware :: SERCOM2 (SPI) -----------------------------------*/
    vDriver_SAMD_SERCOM4_SPIM_CONFIGURE();

    /*--------------------------------------------------------------------------*/

    /* Setting ::: Control :: CANFD --------------------------------------------*/
    vControl_MCP2518FD_CONFIGURE();
    
    /*--------------------------------------------------------------------------*/

    /* Setting ::: Resource :: Events ------------------------------------------*/
    vSystemOS_EVENT_GROUPS_CONFIGURE();
    /* Setting ::: Resource :: Semaphores --------------------------------------*/
    vSystemOS_SEMAPHORES_CONFIGURE();
    /* Setting ::: Resource :: Mutex -------------------------------------------*/
    vSystemOS_MUTEX_CONFIGURE();
    /* Setting ::: Resource :: Queues ------------------------------------------*/
    vSystemOS_QUEUES_CONFIGURE();
    /* Setting ::: Resource :: Threads -----------------------------------------*/
    vSystemOS_TASKS_CONFIGURE();

    /* - RTOS ------------------------------------------------------------------*/
    vTaskStartScheduler(); // Start the scheduler
}
