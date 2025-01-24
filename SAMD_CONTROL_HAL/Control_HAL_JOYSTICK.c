/* Include ::: Header File */
#include "Control_HAL_JOYSTICK.h"
/* Include ::: Header Ports */
#include "Driver_SAMD_PORT.h"

/*----------------------------------------------------------------------------*/

/* Development ::: Control Functions */
uint01_t xReadValueJoystick(xBufferJoystick_t *BUFFER, uint08_t *CHANNEL_MUX, uint16_t ADC_DATA) {
    /* Variable :: Locals */
    uint01_t RETURN = pdCLR;

    /* Check ::: BUFFER */
    if ((BUFFER != NULL) && (CHANNEL_MUX != NULL)) {
        /* Seleccion ::: Entrada a registrar */
        switch (*CHANNEL_MUX) {
            case CHANNEL_BUTTON_A:
                /* Saved value Into the Buffer Joystick... */
                BUFFER->BUTTONS.BITS.BA = (ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE) ? pdCLR : pdSET);
                break;
            case CHANNEL_BUTTON_B:
                /* Saved value Into the Buffer Joystick... */
                BUFFER->BUTTONS.BITS.BB = (ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE) ? pdCLR : pdSET);
                break;
            case CHANNEL_BUTTON_X:
                /* Saved value Into the Buffer Joystick... */
                BUFFER->BUTTONS.BITS.BX = (ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE) ? pdCLR : pdSET);
                break;
            case CHANNEL_BUTTON_Y:
                /* Saved value Into the Buffer Joystick... */
                BUFFER->BUTTONS.BITS.BY = (ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE) ? pdCLR : pdSET);
                break;
            case CHANNEL_BUTTON_L:
                /* Saved value Into the Buffer Joystick... */
                BUFFER->BUTTONS.BITS.BL = (ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE) ? pdCLR : pdSET);
                break;
            case CHANNEL_BUTTON_R:
                /* Saved value Into the Buffer Joystick... */
                BUFFER->BUTTONS.BITS.BR = (ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE) ? pdCLR : pdSET);
                break;
            case CHANNEL_BUTTON_Z:
                /* Saved value Into the Buffer Joystick... */
                BUFFER->BUTTONS.BITS.BZ = ((JOYSTICK_BUTTON_Z() == pdCLR) ? pdSET : pdCLR);
                break;
            case CHANNEL_AXIS_X:
                /* Read :: ADC_DATA... */
                BUFFER->ANALOG.WORDS.AXISX = ADC_DATA;

                /* Selectec Digital Arrow... */
                BUFFER->BUTTONS.BITS.JL = ((ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE)) ? pdSET : pdCLR);
                BUFFER->BUTTONS.BITS.JR = ((ADC_DATA < (JOYSTICK_MIDDLE_ZONE - JOYSTICK_DEAD_ZONE)) ? pdSET : pdCLR);
                break;
            case CHANNEL_AXIS_Y:
                /* Read :: ADC_DATA... */
                BUFFER->ANALOG.WORDS.AXISY = ADC_DATA;

                /* Selectec Digital Arrow... */
                BUFFER->BUTTONS.BITS.JU = ((ADC_DATA < (JOYSTICK_MIDDLE_ZONE - JOYSTICK_DEAD_ZONE)) ? pdSET : pdCLR);
                BUFFER->BUTTONS.BITS.JD = ((ADC_DATA > (JOYSTICK_MIDDLE_ZONE + JOYSTICK_DEAD_ZONE)) ? pdSET : pdCLR);
                break;
        }

        /* Check ::: Maximun ADC_DATA */
        *CHANNEL_MUX = (*CHANNEL_MUX < 8U ? (*CHANNEL_MUX + 1U) : 0U);

        /* Write ::: BITS of CHANNEL Multiplexer */
        MUX_PINA_OUT(!!(*CHANNEL_MUX & 1U));
        MUX_PINB_OUT(!!(*CHANNEL_MUX & 2U));
        MUX_PINC_OUT(!!(*CHANNEL_MUX & 4U));

        /* Set ::: RETURN */
        RETURN = pdSET;
    }

    /* Return ::: Control */
    return (RETURN);
}
