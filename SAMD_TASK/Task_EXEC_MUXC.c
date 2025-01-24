/* Include ::: Header :: Threads */
#include "Settings_TASKS.h"

/******************************************************************************/
/** Configuration Macros = Time Control Thread                                */
/******************************************************************************/

#define TASK_TIME_RECURRING ((TickType_t)(10U / portTICK_PERIOD_MS))

/******************************************************************************/
/* == Statement CTRL Machine Variables == */

/******************************************************************************/

typedef enum {
    READ_BUTTONS, READ_LIGTH, READ_TEMP
} xTask_State_Machine_Mux_enum_t;

/******************************************************************************/
/** Development Control Functions = Thread                                    */

/******************************************************************************/

void vTask_EXEC_MUXC(void *pvParameters) {
    /****************************************************************************/
    /** Local = Variables                                                       */
    /****************************************************************************/

    /* Initialize ::: Current Tick */
    TickType_t xLAST_WAKE_THREAD = xTaskGetTickCount();

    /*--------------------------------------------------------------------------*/

    /* Machine State ::: Variables */
    xTask_State_Machine_Mux_enum_t CTRL_READ = READ_BUTTONS;

    /*--------------------------------------------------------------------------*/

    /* Statament ::: Mux Control */
    xBufferJoystick_t BUFFER_JOYSTICK = {0U};
    uint08_t MUX_PORT = 0U;
    uint16_t SENSE_LIGTH = 0U;
    uint16_t SENSE_TEMP = 0U;
    uint08_t CHECK = pdCLR;

    /****************************************************************************/
    /** Execution = Infinite Loop Task                                          */

    /****************************************************************************/

    START_TASK() {
        /* Break ::: DEBUG */
        pdNOP();

        /************************************************************************/
        /** Execution ::: State Machine                                         */
        /************************************************************************/

        switch (CTRL_READ) {
            case READ_BUTTONS:
                /* Write & Read ::: Next Value for Multiplexer */
                xReadValueJoystick(&BUFFER_JOYSTICK, &MUX_PORT, xDriver_SAMD_ADC_READ(ADC_INPUTCTRL_MUXPOS_PIN2));

                /* Check ::: MUX_PORT */
                if (MUX_PORT == 0U) {
                    /* Change ::: CTRL_READ */
                    CTRL_READ = READ_LIGTH;
                }
                break;
            case READ_LIGTH:
                /* Read ::: Sense ADC AN3 for Ligth Value */
                SENSE_LIGTH = xDriver_SAMD_ADC_READ(ADC_INPUTCTRL_MUXPOS_PIN3);
                /* Change ::: CTRL_READ */
                CTRL_READ = READ_TEMP;
                break;
            case READ_TEMP:
                /* Read ::: Sense ADC AN4 for Temperature Value */
                SENSE_TEMP = xDriver_SAMD_ADC_READ(ADC_INPUTCTRL_MUXPOS_PIN4);
                /* Change ::: CTRL_READ */
                CTRL_READ = READ_BUTTONS;
                break;
        }

        xControl_HAL_EEP_24CM01_CHECK();

        /**************************************************************************/
        /** Delay Until ::: Task Time Recurring                                   */
        /**************************************************************************/

        vTaskDelayUntil(&xLAST_WAKE_THREAD, TASK_TIME_RECURRING);
    }
    /* End of Execution ::: Task */
    END_TASK();
}

