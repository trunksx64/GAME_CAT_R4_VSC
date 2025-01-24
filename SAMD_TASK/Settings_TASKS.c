/* Include ::: Header :: Threads */
#include "Settings_TASKS.h"

/******************************************************************************/
/* == Statement External Variables == */
/******************************************************************************/

xStatementSystemOS_t xStatementSystemOS = {0U};

/******************************************************************************/
/* == Development Thread Functions = EventGroups == */

/******************************************************************************/

void vSystemOS_EVENT_GROUPS_CONFIGURE(void) {
    /* Creation ::: EventGroups :: Status Control ----------------------------- */
    xStatementSystemOS.EVENT.STATUS_CONTROL = xEventGroupCreate();
}

/******************************************************************************/
/* == Development Thread Functions = Semaphores == */

/******************************************************************************/

void vSystemOS_SEMAPHORES_CONFIGURE(void) {

}

/******************************************************************************/
/* == Development Thread Functions = Mutex == */

/******************************************************************************/

void vSystemOS_MUTEX_CONFIGURE(void) {
    /* Creation ::: Mutex :: Stream I2C --------------------------------------- */
    xStatementSystemOS.MUTEX.SPI_BUS_BLOCK = xSemaphoreCreateMutex();
    /* Creation ::: Mutex :: Stream I2C --------------------------------------- */
    xStatementSystemOS.MUTEX.I2C_BUS_BLOCK = xSemaphoreCreateMutex();
}

/******************************************************************************/
/* == Development Thread Functions = Queues == */

/******************************************************************************/

void vSystemOS_QUEUES_CONFIGURE(void) {
    /* Creation ::: Queue CONTROL LED Controls ------------------------------ */
    xStatementSystemOS.QUEUE.CONF_LED = xQueueCreate(8U, sizeof (xStream_Led_Config_t));

    /* Creation ::: Queue CAN Received Buffers Controls --------------------- */
    xStatementSystemOS.QUEUE.CANC_RXD = xQueueCreate(16U, sizeof (uint08_t));
    xStatementSystemOS.QUEUE.CANC_TXD = xQueueCreate(8U, sizeof (uint08_t));
}

/******************************************************************************/
/* == Development Thread Functions = Task == */

/******************************************************************************/

void vSystemOS_TASKS_CONFIGURE(void) {
    /* Creation ::: System Execution Threads ---------------------------------- */
    xTaskCreate(vTask_CTRL_CANC, "CTRL_CANC", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_MED_01, &xStatementSystemOS.TASK.CTRL_CANC);
    xTaskCreate(vTask_CTRL_LEDC, "CTRL_LEDC", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_LOW_01, &xStatementSystemOS.TASK.CTRL_LEDC);
    xTaskCreate(vTask_EXEC_MUXC, "CTRL_MUXC", configMINIMAL_STACK_SIZE, NULL, TASK_PRIORITY_MED_01, &xStatementSystemOS.TASK.CTRL_MUXC);
}
