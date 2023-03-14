#ifndef HARDWARE_H
#define HARDWARE_H

#include <avr/io.h>

#include <cstdint>

const uint8_t MOTOR_STEP = PORTD0;
const uint8_t MOTOR_DIRECTION = PORTD1;
const uint8_t LIMIT_1 = PORTD2;
const uint8_t LIMIT_2 = PORTD3;
const uint8_t BTN_ADVANCE = PORTD4;
const uint8_t BTN_RETURN = PORTD5;

class Hardware {
 public:
  Hardware();
  Hardware(void (*setter)(uint8_t*, uint8_t),
           void (*clearer)(uint8_t*, uint8_t));

  void step_left();
  void step_right();

  // Switches are assumed to be debounced in hardware.
  //
  // Register bits are  high when switches are closed
  bool limit1();  /// True if limit switch 1 is closed
  bool limit2();  /// True if limit switch 2 is closed

  bool button_advance();  /// True if advance button is pressed
  bool button_return();   /// True if return button is pressed

 private:
  void (*pinwrite)(uint8_t* reg, uint8_t bit);
  void (*pinclear)(uint8_t* reg, uint8_t bit);
};

#endif