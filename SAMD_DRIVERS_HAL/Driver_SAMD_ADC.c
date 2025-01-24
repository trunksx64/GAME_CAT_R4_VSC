/* Include ::: Headers */
#include "Driver_SAMD_ADC.h"
/* Include ::: Header Storage */
#include "Storage_DELAY.h"

/******************************************************************************/
/** Development Configuration Hardware SAMC :: ADC                           **/
/******************************************************************************/

void vDriver_SAMD_ADC_CONFIGURE(void) {
    /* Local ::: Variables */
    uint08_t BIAS = 0U;
    uint08_t LINEARITY = 0U;

    /*--------------------------------------------------------------------------*/

    /* Break ::: DEBUG */
    pdNOP();

    /*--------------------------------------------------------------------------*/

    /* Enable ::: Device */
    PM_REGS->PM_APBCMASK |= PM_APBCMASK_ADC(pdSET); // ADC APBC Mask Clock Enable

    /* Set Source Main Clock */
    GCLK_REGS->GCLK_CLKCTRL = (
            GCLK_CLKCTRL_ID_ADC | // Generic Clock Selection ID
            GCLK_CLKCTRL_GEN_GCLK2 | // Generic Clock Generator
            GCLK_CLKCTRL_CLKEN(pdSET) | // Clock Enable
            GCLK_CLKCTRL_WRTLOCK(pdCLR)); // Write Lock
    /* While ::: Sync */
    while (GCLK_REGS->GCLK_STATUS & GCLK_STATUS_SYNCBUSY(pdSET));

    /*--------------------------------------------------------------------------*/

    /* Reset ::: Configuration ADC */
    ADC_REGS->ADC_CTRLA |= ADC_CTRLA_SWRST(pdSET); // Reset Module for Configuration
    /* While ::: Sync Status SYNCBUSY */
    while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET));

    /*--------------------------------------------------------------------------*/

    /* Load ::: ADC Calibration */
    BIAS = ((OTP4_FUSES_REGS->FUSES_OTP4_WORD_1 & FUSES_OTP4_WORD_1_ADC_BIASCAL_Msk) >> FUSES_OTP4_WORD_1_ADC_BIASCAL_Pos);
    LINEARITY = ((OTP4_FUSES_REGS->FUSES_OTP4_WORD_0 & FUSES_OTP4_WORD_0_ADC_LINEARITY_0_Msk) >> FUSES_OTP4_WORD_0_ADC_LINEARITY_0_Pos);
    LINEARITY |= (((OTP4_FUSES_REGS->FUSES_OTP4_WORD_1 & FUSES_OTP4_WORD_1_ADC_LINEARITY_1_Msk) >> FUSES_OTP4_WORD_1_ADC_LINEARITY_1_Pos) << 5U);

    /* Write the calibration data. */
    ADC_REGS->ADC_CALIB = ADC_CALIB_BIAS_CAL(BIAS) | ADC_CALIB_LINEARITY_CAL(LINEARITY);

    /*--------------------------------------------------------------------------*/

    /* Configuration ::: ADC CTRLB */
    ADC_REGS->ADC_CTRLB = (
            ADC_CTRLB_DIFFMODE(pdCLR) | // Differential Mode
            ADC_CTRLB_LEFTADJ(pdCLR) | // Left-Adjusted Result
            ADC_CTRLB_FREERUN(pdCLR) | // Free Running Mode
            ADC_CTRLB_RESSEL_10BIT | // Conversion Result Resolution
            ADC_CTRLB_PRESCALER_DIV32); // Prescaler Configuration
    /* While ::: Sync Status SYNCBUSY */
    while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET));

    /* Configuration ::: ADC REFCTRL */
    ADC_REGS->ADC_REFCTRL = (
            ADC_REFCTRL_REFSEL_INTVCC1 | // Reference Selection 
            ADC_REFCTRL_REFCOMP(pdSET)); // Reference Buffer Offset Compensation Enable

    /* Configuration ::: ADC INPUTCTRL */
    ADC_REGS->ADC_INPUTCTRL = (
            ADC_INPUTCTRL_GAIN_DIV2 | // Gain Factor Selection
            ADC_INPUTCTRL_INPUTOFFSET(pdCLR) | // Positive Mux Setting Offset
            ADC_INPUTCTRL_INPUTSCAN(pdCLR) | // Number of Input Channels Included in Scan
            ADC_INPUTCTRL_MUXNEG_GND | // Negative Mux Input Selection
            ADC_INPUTCTRL_MUXPOS_PIN2); // Positive Mux Input Selection                                  \
    /* While ::: Sync Status SYNCBUSY */
    while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET));

    /* Configuration ::: ADC AVGCTRL */
    ADC_REGS->ADC_AVGCTRL = (
            ADC_AVGCTRL_ADJRES(0U) | //  Adjusting Result / Division Coefficient
            ADC_AVGCTRL_SAMPLENUM_1); // Number of Samples to be Collected

    /*--------------------------------------------------------------------------*/

    /* Enable ::: ADC */
    ADC_REGS->ADC_CTRLA |= ADC_CTRLA_ENABLE(pdSET); // Enable Module
    /* While ::: Sync Status SYNCBUSY */
    while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET));
}

uint16_t xDriver_SAMD_ADC_READ(uint08_t INPUT) {
    /* Local ::: Variables */
    uint16_t RETURN = 0U;
    uint08_t CURRENT_CANNEL = 0U;

    /*--------------------------------------------------------------------------*/

    /* Read ::: Current Channel*/
    CURRENT_CANNEL = ((ADC_REGS->ADC_INPUTCTRL & ADC_INPUTCTRL_MUXPOS_Msk) >> ADC_INPUTCTRL_MUXPOS_Pos);
    /* While ::: Sync Status SYNCBUSY */
    while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET));

    /*--------------------------------------------------------------------------*/

    /* Check ::: Not Equal Channel */
    if (CURRENT_CANNEL != INPUT) {
        /* Clear ::: Input Read */
        ADC_REGS->ADC_INPUTCTRL &= ~ADC_INPUTCTRL_MUXPOS_Msk;
        /* While ::: Sync */
        while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET)); // Wait Process Complete
        /* Delay ::: System */
        vStorage_DELAY_MS(1U);

        /* Update ::: Input Read */
        ADC_REGS->ADC_INPUTCTRL |= ADC_INPUTCTRL_MUXPOS(INPUT);
        /* While ::: Sync */
        while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET)); // Wait Process Complete
        /* Delay ::: System */
        vStorage_DELAY_MS(1U);
    }

    /*--------------------------------------------------------------------------*/

    /* Clear ::: Interruptions */
    ADC_REGS->ADC_INTFLAG = (ADC_INTFLAG_RESRDY(pdSET) | ADC_INTFLAG_OVERRUN(pdSET) | ADC_INTFLAG_SYNCRDY(pdSET));
    /* Start ::: Conversion */
    ADC_REGS->ADC_SWTRIG |= ADC_SWTRIG_START(pdSET);

    /* While ::: Sync Status SYNCBUSY */
    while (ADC_REGS->ADC_STATUS & ADC_STATUS_SYNCBUSY(pdSET));
    /* While ::: Shot Interruption Flag*/
    while (!(ADC_REGS->ADC_INTFLAG & ADC_INTFLAG_RESRDY(pdSET)));

    /* Read :::  Result Conversion */
    RETURN = ADC_REGS->ADC_RESULT;
    /* Return :::  Result Conversion */
    return (RETURN);
}
