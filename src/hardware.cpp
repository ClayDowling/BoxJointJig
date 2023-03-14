#include "hardware.h"

void pinwriter(uint8_t* reg, uint8_t bit) { *reg |= _BV(bit); }
void pinclearer(uint8_t* reg, uint8_t bit) { *reg &= ~_BV(bit); }

Hardware::Hardware() { Hardware(pinwriter, pinclearer); }

Hardware::Hardware(void (*setter)(uint8_t*, uint8_t),
                   void (*clearer)(uint8_t*, uint8_t)) {
  pinwrite = setter;
  pinclear = clearer;

  DDRD |= _BV(MOTOR_STEP);
  DDRD |= _BV(MOTOR_DIRECTION);
  DDRD &= ~_BV(LIMIT_1);
  DDRD &= ~_BV(LIMIT_2);
  DDRD &= ~_BV(BTN_ADVANCE);
  DDRD &= ~_BV(BTN_RETURN);
}

void Hardware::step_right() {}

void Hardware::step_left() {}