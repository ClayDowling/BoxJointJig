#include "hardware.h"

void hardware_init() {
  DDRD |= _BV(MOTOR_STEP);
  DDRD |= _BV(MOTOR_DIRECTION);
  DDRD &= ~_BV(LIMIT_1);
}