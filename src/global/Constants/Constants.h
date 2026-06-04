#pragma once

// Flight Modes
const float FLAPERON_RATIO_CONSTANT = 0.3;       // 0 for flaperon mode off, 0.3 recommended
const float AUTOPILOT_DISENGAGE_THRESHOLD = 0.3; // 0 to 1, how "hard" input is needed to disengage AP. > 0.5 is dangerous.

// Authority Limiters on Servos (not control surfaces)
// Represents max displacement from zero-level for a symmetric control surface
const float AILERON_SERVO_POS_MAX_DEG = 70;
const float ELEVATOR_SERVO_POS_MAX_DEG = 70;
const float RUDDER_SERVO_POS_MAX_DEG = 70;

// Radio Pins
const uint8_t RADIO_PIN_CE = 7;
const uint8_t RADIO_PIN_CSN = 8;

// Control Surface Pins
const uint8_t AILERON_LEFT_PIN = 2;
const uint8_t AILERON_RIGHT_PIN = 3;
const uint8_t ELEVATOR_LEFT_PIN = 4;
const uint8_t ELEVATOR_RIGHT_PIN = 5;
// Motor Pins
const uint8_t MOTOR_LEFT_PIN = 6;
const uint8_t MOTOR_RIGHT_PIN = 7;