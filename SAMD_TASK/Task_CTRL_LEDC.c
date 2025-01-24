/* Include ::: Header :: Threads */
#include "Settings_TASKS.h"

/******************************************************************************/
/* == Configuration Macros = Time Control Thread ==                           */
/******************************************************************************/

#define TASK_TIME_RECURRING ((TickType_t)(1U / portTICK_PERIOD_MS))

/******************************************************************************/
/* == Statement Conts Variables == */
/******************************************************************************/

const uint32_t GPIO_LEDS[2U][2U] = {
    {GPIO_PORTA, PORT_PA30}, // WRITE ::: LED Busy
    {GPIO_PORTA, PORT_PA31}, // WRITE ::: LED Ctrl
};

/******************************************************************************/
/* == Development Control Functions = Thread ==                               */

/******************************************************************************/

void vTask_CTRL_LEDC(void *pvParameters) {

    /****************************************************************************/
    /* == Local = Variables                                                     */
    /****************************************************************************/

    /* Initialize ::: Current Tick */
    TickType_t xLAST_WAKE_THREAD = xTaskGetTickCount();

    /*--------------------------------------------------------------------------*/

    /* Control  ::: Variables */
    xStream_Led_Config_t BUFFER_LED_DATA = {0U}; // Buffer Queue
    xStream_Led_Counter_t COUNTER_LED[sizeof (GPIO_LEDS) / sizeof (uint64_t)] = {0U}; // Control LEDS

    /* Toggle ::: Toggle LED Check Hardware */
    xStream_LED_COMMAND(NUM_LED_BUSY, CMD_LED_TGL, 100U);
    /* Toggle ::: Toggle LED Check Hardware */
    xStream_LED_COMMAND(NUM_LED_CTRL, CMD_LED_TGL, 100U);

    /****************************************************************************/
    /* == Execution = Infinite Loop Task                                        */
    /****************************************************************************/

    /* Execution ::: Task */
    START_TASK() {
        /* Break ::: DEBUG */
        pdNOP();

        /**************************************************************************/
        /** Check Buffer ::: Waiting Messages Control                             */
        /**************************************************************************/

        if (uxQueueMessagesWaiting(xStatementSystemOS.QUEUE.CONF_LED)) {
            /* Break ::: DEBUG */
            pdNOP();

            /* Execute ::: Queue is Full */
            do {
                /* GET :: Message from Buffer */
                if (xQueueReceive(xStatementSystemOS.QUEUE.CONF_LED, (void *) &BUFFER_LED_DATA, 0U)) {
                    /* Check ::: maximun LEDS */
                    if (BUFFER_LED_DATA.NUMBER_LED < (sizeof (COUNTER_LED) / sizeof (xStream_Led_Counter_t))) {
                        /* SET ::: Control */
                        COUNTER_LED[BUFFER_LED_DATA.NUMBER_LED].COMMAD = BUFFER_LED_DATA.COMMAND;

                        /* CHK ::: Toggle or Timer */
                        if ((BUFFER_LED_DATA.COMMAND == CMD_LED_TGL) || (BUFFER_LED_DATA.COMMAND == CMD_LED_TMR)) {
                            /* Getting ::: Current Time */
                            COUNTER_LED[BUFFER_LED_DATA.NUMBER_LED].TIME_OVERFLOW = BUFFER_LED_DATA.TIMER;
                            COUNTER_LED[BUFFER_LED_DATA.NUMBER_LED].TIME_LAST = xTaskGetTickCount();
                            /* CLR ::: Current LED Loop */
                            PORT_REGS->GROUP[GPIO_LEDS[BUFFER_LED_DATA.NUMBER_LED][0U]].PORT_OUTCLR = GPIO_LEDS[BUFFER_LED_DATA.NUMBER_LED][1U];
                        }
                    }
                }
            } while (uxQueueMessagesWaiting(xStatementSystemOS.QUEUE.CONF_LED));
        }


        /**************************************************************************/
        /** Loop ::: Control One Led Time                                         */
        /**************************************************************************/

        for (uint08_t COUNTER = 0U; (COUNTER < (sizeof (COUNTER_LED) / sizeof (xStream_Led_Counter_t))); COUNTER++) {
            /* Break ::: DEBUG */
            pdNOP();

            /* Control ::: LED Command Storage */
            switch (COUNTER_LED[COUNTER].COMMAD) {
                case CMD_LED_CLR:
                    /* CLR ::: Current LED Loop */
                    PORT_REGS->GROUP[GPIO_LEDS[COUNTER][0U]].PORT_OUTCLR = GPIO_LEDS[COUNTER][1U];
                    break;
                case CMD_LED_SET:
                    /* SET ::: Current LED Loop */
                    PORT_REGS->GROUP[GPIO_LEDS[COUNTER][0U]].PORT_OUTSET = GPIO_LEDS[COUNTER][1U];
                    break;
                case CMD_LED_TGL:
                    /* CHK ::: Overflow Time */
                    if ((xTaskGetTickCount() - COUNTER_LED[COUNTER].TIME_LAST) >= (COUNTER_LED[COUNTER].TIME_OVERFLOW / 2U)) {
                        /* UDP ::: Last Time */
                        COUNTER_LED[COUNTER].TIME_LAST = xTaskGetTickCount();
                        /* TGL ::: Current LED Loop */
                        PORT_REGS->GROUP[GPIO_LEDS[COUNTER][0U]].PORT_OUTTGL = GPIO_LEDS[COUNTER][1U];
                    }
                    break;
                case CMD_LED_TMR:
                    /* CHK ::: LED Enabled */
                    if (!!(PORT_REGS->GROUP[GPIO_LEDS[COUNTER][0U]].PORT_OUTCLR & GPIO_LEDS[COUNTER][1U])) {
                        /* CHK ::: Overflow Time */
                        if ((xTaskGetTickCount() - COUNTER_LED[COUNTER].TIME_LAST) >= COUNTER_LED[COUNTER].TIME_OVERFLOW) {
                            /* CLR ::: Variable Output */
                            PORT_REGS->GROUP[GPIO_LEDS[COUNTER][0U]].PORT_OUTCLR = GPIO_LEDS[COUNTER][1U];
                        }
                    }
                    break;
            }
        }


        /**************************************************************************/
        /** Delay Until ::: Task Time Recurring                                   */
        /**************************************************************************/

        vTaskDelayUntil(&xLAST_WAKE_THREAD, TASK_TIME_RECURRING);
    }
    /* End of Execution ::: Task */
    END_TASK();
}
