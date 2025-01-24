#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/******************************************************************************/
/* Configuration Include = Header Storage. ************************************/
/******************************************************************************/

#include "Storage_CLASS.h"

/******************************************************************************/
/* Hardware description related definitions. **********************************/
/******************************************************************************/

#define configCPU_CLOCK_HZ                          (FSC_CLOCK_SYSTEM)

/******************************************************************************/
/* Scheduling behaviour related definitions. **********************************/
/******************************************************************************/

#define configTICK_RATE_HZ                          (1000U)
#define configUSE_PREEMPTION                        1U
#define configUSE_TIME_SLICING                      1U
#define configUSE_PORT_OPTIMISED_TASK_SELECTION     0U
#define configUSE_TICKLESS_IDLE                     0U
#define configMAX_PRIORITIES                        9U
#define configMINIMAL_STACK_SIZE                    ((size_t)(128U))
#define configMAX_TASK_NAME_LEN                     10U
#define configIDLE_SHOULD_YIELD                     0U
#define configTASK_NOTIFICATION_ARRAY_ENTRIES       1U
#define configQUEUE_REGISTRY_SIZE                   0U
#define configENABLE_BACKWARD_COMPATIBILITY         0U
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS     0U
#define configSTACK_DEPTH_TYPE                      size_t
#define configMESSAGE_BUFFER_LENGTH_TYPE            size_t
#define configUSE_NEWLIB_REENTRANT                  0U
#define configENABLE_MPU                            0U
#define configUSE_16_BIT_TICKS                      0U
#define configCHECK_HANDLER_INSTALLATION            0U
#define configSYSTEM_CALL_STACK_SIZE                1U

/******************************************************************************/
/* Software timer related definitions. ****************************************/
/******************************************************************************/

#define configUSE_TIMERS                            0U
#define configTIMER_TASK_PRIORITY                   (configMAX_PRIORITIES - 1U)
#define configTIMER_TASK_STACK_DEPTH                ((size_t)(256U))
#define configTIMER_QUEUE_LENGTH                    10U

/******************************************************************************/
/* Memory allocation related definitions. *************************************/
/******************************************************************************/

#define configSUPPORT_STATIC_ALLOCATION              0U
#define configSUPPORT_DYNAMIC_ALLOCATION             1U
#define configTOTAL_HEAP_SIZE                        ((size_t)(1024U * 4U))
#define configAPPLICATION_ALLOCATED_HEAP             0U
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP    0U
#define configUSE_MINI_LIST_ITEM                     0U

/******************************************************************************/
/* Interrupt nesting behaviour configuration. *********************************/
/******************************************************************************/

#define configKERNEL_INTERRUPT_PRIORITY             0U
#define configMAX_SYSCALL_INTERRUPT_PRIORITY        0U
#define configMAX_API_CALL_INTERRUPT_PRIORITY       0U

/******************************************************************************/
/* Hook and callback function related definitions. ****************************/
/******************************************************************************/

#define configUSE_IDLE_HOOK                         0U
#define configUSE_TICK_HOOK                         0U
#define configUSE_MALLOC_FAILED_HOOK                0U
#define configUSE_DAEMON_TASK_STARTUP_HOOK          0U
#define configCHECK_FOR_STACK_OVERFLOW              0U

/******************************************************************************/
/* Run time and task stats gathering related definitions. *********************/
/******************************************************************************/

#define configGENERATE_RUN_TIME_STATS               0U
#define configUSE_TRACE_FACILITY                    0U
#define configUSE_STATS_FORMATTING_FUNCTIONS        0U
#define configKERNEL_PROVIDED_STATIC_MEMORY         0U

/******************************************************************************/
/* Definitions that include or exclude functionality. *************************/
/******************************************************************************/

#define configUSE_TASK_NOTIFICATIONS                0U
#define configUSE_MUTEXES                           1U
#define configUSE_RECURSIVE_MUTEXES                 0U
#define configUSE_COUNTING_SEMAPHORES               0U
#define configUSE_QUEUE_SETS                        0U
#define configUSE_APPLICATION_TASK_TAG              0U
#define INCLUDE_vTaskPrioritySet                    0U
#define INCLUDE_uxTaskPriorityGet                   0U
#define INCLUDE_vTaskDelete                         0U
#define INCLUDE_vTaskSuspend                        0U
#define INCLUDE_vTaskDelayUntil                     1U
#define INCLUDE_vTaskDelay                          1U
#define INCLUDE_xTaskGetSchedulerState              0U
#define INCLUDE_xTaskGetCurrentTaskHandle           0U
#define INCLUDE_uxTaskGetStackHighWaterMark         0U
#define INCLUDE_xTaskGetIdleTaskHandle              0U
#define INCLUDE_eTaskGetState                       0U
#define INCLUDE_xTimerPendFunctionCall              0U
#define INCLUDE_xTaskAbortDelay                     0U
#define INCLUDE_xTaskGetHandle                      0U
#define INCLUDE_xTaskResumeFromISR                  0U

/* Normal assert() semantics without relying on the provision of an assert.h
header file. */
#define configASSERT( x ) if( ( x ) == 0U ) { taskDISABLE_INTERRUPTS(); for( ;; ); }

/* Definitions that map the FreeRTOS port interrupt handlers to their CMSIS
standard names - or at least those used in the unmodified vector table. */
#define xPortPendSVHandler PendSV_Handler
#define xPortSysTickHandler SysTick_Handler

#endif /* FREERTOS_CONFIG_H */

