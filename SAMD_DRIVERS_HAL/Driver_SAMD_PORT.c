/* Include ::: Headers */
#include "Driver_SAMD_PORT.h"

/******************************************************************************/
/* == Development Configuration Functions == */

/******************************************************************************/

void vDriver_SAMD_PORT_CONFIGURE(void) {
    /* BRK ::: DEBUG */
    pdNOP();

    /*------------------------------------------------------------------------*/

    /* Set Source Main Clock ------------------------------------------------ */
    PM_REGS->PM_APBBMASK |= PM_APBBMASK_PORT(pdSET); // PORT APBB Mask Clock Enable

    /*------------------------------------------------------------------------*/

    /*- ADC - INPUTS -------------------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: ADC(AIN[2]/AIN[3]/AIN42])(PB08/PB09/PA04) - */
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRCLR = PORT_PB08; // Direction Port In AIN[2]
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRCLR = PORT_PB09; // Direction Port In AIN[3]
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA04; // Direction Port In AIN[4]

    PORT_REGS->GROUP[GPIO_PORTB].PORT_PINCFG[GPIO_P08] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTB].PORT_PINCFG[GPIO_P09] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P04] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTB].PORT_PMUX[GPIO_MUX08] |= PORT_PMUX_PMUXE(DEV_MUXB); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTB].PORT_PMUX[GPIO_MUX09] |= PORT_PMUX_PMUXO(DEV_MUXB); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX04] |= PORT_PMUX_PMUXE(DEV_MUXB); // Select Peripheral Multiplexing

    /*- JOYSTIC - INPUTS ---------------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: Check Button (Button Z)(PA03) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA03; // Direction Port In  // CHECK ACCEL
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P03] = PORT_PINCFG_INEN(pdSET); // Configure Input Port

    /*- MUX - OUTPUTS ------------------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: LED(BSY) : (PA18/PA19/PA20) --------- */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA18; // Direction Port Out (MUXC)
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA19; // Direction Port Out (MUXB)
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA20; // Direction Port Out (MUXA)

    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA18; // High Output (MUXC)
    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA19; // High Output (MUXB)
    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTCLR = PORT_PA20; // High Output (MUXA)

    /*- LEDS - OUTPUTS ------------------------------------------------------ */

    /* Configuration ::: Ports(Pins) :: LED(BSY) : (PB30/PA31) --- */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA30; // Direction Port Out (Busy)
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA31; // Direction Port Out (Ctrl)

    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA30; // SET Port Out (Busy)
    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA31; // SET Port Out (Ctrl)

    /*- USB ----------------------------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: USB(DM/DP)(PA24/PA25) --------------- */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA24; // Direction Port In // DM
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA25; // Direction Port In // DP

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P24] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P25] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX24] |= PORT_PMUX_PMUXE(DEV_MUXG); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX25] |= PORT_PMUX_PMUXO(DEV_MUXG); // Select Peripheral Multiplexing

    /*- I2C (SERCOM1) - (EEprom/Accelerometer) ------------------------------ */

    /* Configuration ::: Ports(Pins) :: Check Device (CHECK_ACCEL)(PA15) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA15; // Direction Port In // CHECK ACCEL

    /* Configuration ::: Ports(Pins) :: SERCOM1-I2C(SDA/SCL)(PA16/PA17)(PAD[0][1]) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA16; // Direction Port In // SDA
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA17; // Direction Port In // SCL

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P16] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P17] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX16] |= PORT_PMUX_PMUXE(DEV_MUXC); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX17] |= PORT_PMUX_PMUXO(DEV_MUXC); // Select Peripheral Multiplexing

    /*- SPI (SERCOM2) - (SRAM/FLASH/SD) ------------------------------------- */

    /* Configuration ::: Ports(Pins) :: Select Device (SS_RAM/SS_FLASH/SS_SD)(PA08/PA07/PA05) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA08; // Direction Port Out // SS RAM
    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA08; // High Output

    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA07; // Direction Port Out // SS FLASH
    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA07; // High Output

    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA05; // Direction Port Out // SS SD
    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA05; // High Output

    /* Configuration ::: Ports(Pins) :: Check Device (CHECK_SD)(PA06) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA06; // Direction Port In  // CHECK SD

    /* Configuration ::: Ports(Pins) :: SERCOM2-SPI(SCK/MOSI/MISO)(PA11/PA10/PA09)(PAD[3][2][1]) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA11; // Direction Port Out // SCK
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA10; // Direction Port Out // MOSI
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA09; // Direction Port In  // MISO

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P11] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P10] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P09] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX11] |= PORT_PMUX_PMUXO(DEV_MUXD); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX10] |= PORT_PMUX_PMUXE(DEV_MUXD); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX09] |= PORT_PMUX_PMUXO(DEV_MUXD); // Select Peripheral Multiplexing

    /*- SPI (SERCOM3) - (CAN-FD) -------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: Select Device (SS)(PA28) ------------ */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA28; // Direction Port Out // SS CAN
    PORT_REGS->GROUP[GPIO_PORTA].PORT_OUTSET = PORT_PA28; // High Output

    /* Configuration ::: Ports(Pins) :: Check Device (CHECK_SD)(PA27) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA27; // Direction Port In  // INT CAN

    /* Configuration ::: Ports(Pins) :: SERCOM3-SPI(SCK/MISO/MOSI)(PA21/PA22/PA23)(PAD[3][0][1]) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA21; // Direction Port Out // SCK
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA22; // Direction Port Out // MOSI
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRCLR = PORT_PA23; // Direction Port In  // MISO

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P21] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P22] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P23] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX21] |= PORT_PMUX_PMUXO(DEV_MUXD); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX22] |= PORT_PMUX_PMUXE(DEV_MUXC); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX23] |= PORT_PMUX_PMUXO(DEV_MUXC); // Select Peripheral Multiplexing

    /*- SPI (SERCOM4) - (SCREEN) -------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: Select Screen (SS)(PB10) ------------ */
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRSET = PORT_PB10; // Direction Port Out // SS SCREEN
    PORT_REGS->GROUP[GPIO_PORTB].PORT_OUTSET = PORT_PB10; // High Output

    /* Configuration ::: Ports(Pins) :: SERCOM4-SPI(SCK/MISO/MOSI)(PA13/PA11/PB11)(PAD[1][0][3]) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA13; // Direction Port Out // SCK
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA12; // Direction Port Out // MOSI
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRCLR = PORT_PB11; // Direction Port In  // MISO

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P13] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P12] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTB].PORT_PINCFG[GPIO_P11] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX13] |= PORT_PMUX_PMUXO(DEV_MUXD); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX12] |= PORT_PMUX_PMUXE(DEV_MUXD); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX11] |= PORT_PMUX_PMUXO(DEV_MUXD); // Select Peripheral Multiplexing

    /*- USART (SERCOM5) ----------------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: SERCOM5-UART(TX/RX)(PB22/PB23)(PAD[2][3]) - */
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRSET = PORT_PB22; // Direction Port Out // TX
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRCLR = PORT_PB23; // Direction Port In  // RX

    PORT_REGS->GROUP[GPIO_PORTB].PORT_PINCFG[GPIO_P22] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTB].PORT_PINCFG[GPIO_P23] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTB].PORT_PMUX[GPIO_MUX22] |= PORT_PMUX_PMUXE(DEV_MUXD); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTB].PORT_PMUX[GPIO_MUX23] |= PORT_PMUX_PMUXO(DEV_MUXD); // Select Peripheral Multiplexing

    /*- TIMER (TCC3) -------------------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: TCC3(PWM)(PA02)(PAD[0]) - */
    PORT_REGS->GROUP[GPIO_PORTA].PORT_DIRSET = PORT_PA02; // Direction Port Out // PWM
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PINCFG[GPIO_P02] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTA].PORT_PMUX[GPIO_MUX02] |= PORT_PMUX_PMUXE(DEV_MUXF); // Select Peripheral Multiplexing

    /*- TIMER (TC6) -------------------------------------------------------- */

    /* Configuration ::: Ports(Pins) :: TC6(PWM1/PWM2)(PB02/PB03)(PAD[0][1]) - */
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRSET = PORT_PB02; // Direction Port Out // PWM0
    PORT_REGS->GROUP[GPIO_PORTB].PORT_DIRSET = PORT_PB03; // Direction Port Out // PWM1

    PORT_REGS->GROUP[GPIO_PORTB].PORT_PINCFG[GPIO_P02] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device
    PORT_REGS->GROUP[GPIO_PORTB].PORT_PINCFG[GPIO_P03] = PORT_PINCFG_PMUXEN(pdSET); // Configure Multiplexor Device

    PORT_REGS->GROUP[GPIO_PORTB].PORT_PMUX[GPIO_MUX02] |= PORT_PMUX_PMUXE(DEV_MUXE); // Select Peripheral Multiplexing
    PORT_REGS->GROUP[GPIO_PORTB].PORT_PMUX[GPIO_MUX03] |= PORT_PMUX_PMUXO(DEV_MUXE); // Select Peripheral Multiplexing
}
