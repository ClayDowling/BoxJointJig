#ifndef HARDWARE_H
#define HARDWARE_H

#include <cstdint>
#include <avr/io.h>

const uint8_t MOTOR_STEP = PORTD0;
const uint8_t MOTOR_DIRECTION = PORTD1;
const uint8_t LIMIT_1 = PORTD2;
const uint8_t LIMIT_2 = PORTD3;
const uint8_t BTN_ADVANCE = PORTD4;
const uint8_t BTN_RETURN = PORTD5;

void hardware_init();

#endif