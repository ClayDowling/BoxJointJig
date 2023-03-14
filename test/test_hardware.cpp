#include <catch2/catch_test_macros.hpp>

#include "hardware.h"

uint8_t DDRD;
uint8_t PORTD;

void clear_registers() {
  DDRD = 0;
  PORTD = 0;
}

uint8_t bit_is_set(uint8_t port, uint8_t bit) { return port & _BV(bit); }
uint8_t bit_is_clear(uint8_t port, uint8_t bit) { return !(port & _BV(bit)); }

SCENARIO("Hardware initialized") {
  clear_registers();

  GIVEN("initialized hardware") {
    hardware_init();

    THEN("step pin is set for output") {
      REQUIRE(bit_is_set(DDRD, MOTOR_STEP));
    }
    THEN("step direction is set for output") {
      REQUIRE(bit_is_set(DDRD, MOTOR_DIRECTION));
    }
  }

  GIVEN("dirty registers before hardware init") {
    DDRD |= _BV(LIMIT_1);
    DDRD |= _BV(LIMIT_2);
    DDRD |= _BV(BTN_ADVANCE);
    DDRD |= _BV(BTN_RETURN);
    hardware_init();

    THEN("limit 1 is set for input") { REQUIRE(bit_is_clear(DDRD, LIMIT_1)); }
    THEN("limit 2 is set for input") { REQUIRE(bit_is_clear(DDRD, LIMIT_2)); }
    THEN("advance button is set for input") {
      REQUIRE(bit_is_clear(DDRD, BTN_ADVANCE));
    }
    THEN("return button is set for input") {
      REQUIRE(bit_is_clear(DDRD, BTN_RETURN));
    }
  }
}