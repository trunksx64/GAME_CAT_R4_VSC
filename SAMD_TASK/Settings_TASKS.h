#ifndef CONFIGURATION_TASK_H
#define CONFIGURATION_TASK_H

/******************************************************************************/
/* == Configuration Include = Header Storage == */
/******************************************************************************/

#include "Storage_INCLUDE.h"

/******************************************************************************/
/* == Configuration Include = Streams == */
/******************************************************************************/

#include "Stream_CTRL_LEDC.h"

/******************************************************************************/
/* == Configuration Include = FreeRTOS == */
/******************************************************************************/

#include "FreeRTOS.h"
#include "event_groups.h"
#include "queue.h"
#include "semphr.h"
#include "task.h"
#include "timers.h"

/******************************************************************************/
/* == Typedef Control Variables = Struct for Statmets FreeRTOS == */

/******************************************************************************/

typedef struct __StatementSystemOS {

    struct {
        EventGroupHandle_t STATUS_CONTROL; // Control Events
    } EVENT;

    struct {
    } SEMAPHORE;

    struct {
        SemaphoreHandle_t SPI_BUS_BLOCK; // Block and Use the SPI BUS
        SemaphoreHandle_t I2C_BUS_BLOCK; // Block and Use the I2C BUS
    } MUTEX;

    struct {
        QueueHandle_t CONF_LED; // Queue Control LEDS
        QueueHandle_t CANC_RXD; // Queue Data To BUS-CAN RXD
        QueueHandle_t CANC_TXD; // Queue Data To BUS-CAN TXD
    } QUEUE;

    struct {
        TaskHandle_t CTRL_CANC; // Task Control de BUS-CAN
        TaskHandle_t CTRL_LEDC; // Task Control del LED
        TaskHandle_t CTRL_MUXC; // Task Control de MUX
    } TASK;

} xStatementSystemOS_t;

/******************************************************************************/
/* == Configuration Macros = Yield Cooperative Scheduling == */
/******************************************************************************/

#define START_TASK() while (RUN_TASK) {

#if (configUSE_PREEMPTION == 0U)
#define END_TASK()                                                                                                                                                                                                                                                                                       \
    taskYIELD();                                                                                                                                                                                                                                                                                           \
    }
#else
#define END_TASK() }
#endif

/******************************************************************************/
/* == Configuration Macros = Control Priority Task == */
/******************************************************************************/

#define TASK_PRIORITY_LOW_01    (UBaseType_t)(0U)
#define TASK_PRIORITY_LOW_02    (UBaseType_t)(1U)
#define TASK_PRIORITY_LOW_03    (UBaseType_t)(2U)
#define TASK_PRIORITY_MED_01    (UBaseType_t)(3U)
#define TASK_PRIORITY_MED_02    (UBaseType_t)(4U)
#define TASK_PRIORITY_MED_03    (UBaseType_t)(5U)
#define TASK_PRIORITY_HIG_01    (UBaseType_t)(6U)
#define TASK_PRIORITY_HIG_02    (UBaseType_t)(7U)
#define TASK_PRIORITY_HIG_03    (UBaseType_t)(8U)

/******************************************************************************/
/* == Configuration Macros = Control Timers Read Flags == */
/******************************************************************************/

#define FLAG_CLEAR_ON_EXIT      pdTRUE
#define FLAG_HOLD_ON_EXIT       pdFALSE

#define FLAG_WAIT_4_ALL_BITS    pdTRUE
#define FLAG_N0_WAIT_4_ALL_BITS pdFALSE

/******************************************************************************/
/* == Configuration Macros = Enable Timers Read Flags == */
/******************************************************************************/

#define TIMER_RELOAD_ENABLE     pdTRUE
#define TIMER_RELOAD_DISABLE    pdFALSE

/******************************************************************************/
/* == Configuration Macros = (Events)(24Bits) Flags Senses Inputs == */
/******************************************************************************/

/******************************************************************************/
/* == Configuration Macros = (Events)(24Bits) Flags Status Control == */
/******************************************************************************/

/******************************************************************************/
/* == Configuration Macros = (Events)(24Bits) Flags Status Devices == */
/******************************************************************************/

/******************************************************************************/
/* == Statement External Variables == */
/******************************************************************************/

extern xStatementSystemOS_t xStatementSystemOS;

/******************************************************************************/
/* == Prototype Configuration Functions = Config FreeRTOS == */
/******************************************************************************/

void vSystemOS_EVENT_GROUPS_CONFIGURE(void);
void vSystemOS_SEMAPHORES_CONFIGURE(void);
void vSystemOS_MUTEX_CONFIGURE(void);
void vSystemOS_QUEUES_CONFIGURE(void);
void vSystemOS_TASKS_CONFIGURE(void);

/******************************************************************************/
/* == Prototype Configuration Functions = Taks FreeRTOS == */
/******************************************************************************/

void vTask_CTRL_CANC(void *pvParameters);
void vTask_CTRL_LEDC(void *pvParameters);
void vTask_EXEC_MUXC(void *pvParameters);

#endif /* CONFIGURATION_TASK_H */
