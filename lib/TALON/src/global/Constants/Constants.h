#pragma once
#include "global/DataStructs.h"
#include <Arduino.h>

// Flight Modes
const float FLAPERON_RATIO_CONSTANT = 0.3;       // 0 for flaperon mode off, 0.3 recommended
const float AUTOPILOT_DISENGAGE_THRESHOLD = 0.4; // 0 to 1, how "hard" input disengages AP. > 0.7 is dangerous.
constexpr FlightCommand TOGA_FLIGHT_COMMAND{0, 0.5, 0, 1.0}; // FlightCommand with 50% pitch, 100% throttle for TOGA mode

// Authority Limiters on Servos (not control surfaces)
// Represents max displacement from zero-level for a symmetric control surface
const float AILERON_SERVO_POS_MAX_DEG = 55;
const float ELEVATOR_SERVO_POS_MAX_DEG = 50;
const float RUDDER_SERVO_POS_MAX_DEG = 70;

// Radio Pins
const uint8_t RADIO_PIN_CE = 7;
const uint8_t RADIO_PIN_CSN = 8;

// Control Surface Pins
// Spaced out to minimize interference
const uint8_t AILERON_LEFT_PIN = 24;
const uint8_t AILERON_RIGHT_PIN = 33;
const uint8_t ELEVATOR_PIN = 38;
const uint8_t RUDDER_PIN = 39;

// Motor Pins
const uint8_t MOTOR_PIN = 2;

// Misc
const float g = 9.80665;