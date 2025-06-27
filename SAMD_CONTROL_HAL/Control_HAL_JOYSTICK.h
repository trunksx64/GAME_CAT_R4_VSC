#ifndef CONTROL_INPUT_JOYSTICK_H
#define CONTROL_INPUT_JOYSTICK_H

/* Include ::: Header Storage Class */
#include "Storage_CLASS.h"

/* Definition ::: Typedef Storage Class ------------------------------------- */
typedef struct __BufferJoystick {

  union {
    uint16_t REGISTER;

    struct {
      uint16_t JU : 1U;
      uint16_t JD : 1U;
      uint16_t JL : 1U;
      uint16_t JR : 1U;
      uint16_t BA : 1U;
      uint16_t BB : 1U;
      uint16_t BX : 1U;
      uint16_t BY : 1U;
      uint16_t BL : 7U;
      uint16_t BR : 7U;
      uint16_t BZ : 1U;
    } BITS;
  } BUTTONS;

  union {
    uint32_t REGISTER;

    struct {
      uint16_t AXISY;
      uint16_t AXISX;
    } WORDS;
  } ANALOG;

} xBufferJoystick_t;

/* Definition ::: Configuration Macros :: Tolerance AXIS Joystick ----------- */
#define JOYSTICK_MIDDLE_ZONE (512U)
#define JOYSTICK_DEAD_ZONE   (256U)

/* Definition ::: Configuration Macros :: Address CHANNEL Buttons ----------- */
#define CHANNEL_BUTTON_A     (1U)
#define CHANNEL_BUTTON_B     (2U)
#define CHANNEL_BUTTON_X     (0U)
#define CHANNEL_BUTTON_Y     (4U)
#define CHANNEL_BUTTON_L     (5U)
#define CHANNEL_BUTTON_R     (3U)
#define CHANNEL_BUTTON_Z     (8U)
#define CHANNEL_AXIS_X       (6U)
#define CHANNEL_AXIS_Y       (7U)

/* Prototype ::: Control Functions */
uint01_t xReadValueJoystick(xBufferJoystick_t *BUFFER, uint08_t *CHANNEL_MUX, uint16_t ADC_DATA);

#endif /* CONTROL_INPUT_JOYSTICK_H */
