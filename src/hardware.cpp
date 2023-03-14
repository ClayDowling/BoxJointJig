#include "hardware.h"

void hardware_init() {
  DDRD |= _BV(MOTOR_STEP);
  DDRD |= _BV(MOTOR_DIRECTION);
  DDRD &= ~_BV(LIMIT_1);
  DDRD &= ~_BV(LIMIT_2);
  DDRD &= ~_BV(BTN_ADVANCE);
  DDRD &= ~_BV(BTN_RETURN);
}