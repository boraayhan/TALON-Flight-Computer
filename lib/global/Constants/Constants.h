#pragma once

// Flight Modes
const double FLAPERON_RATIO_CONSTANT = 0.3; // 0 for flaperon mode off, 0.3 recommended
const double AUTOPILOT_DISENGAGE_THRESHOLD = 0.3; // 0 to 1, how "hard" input is needed to disengage AP. > 0.5 is dangerous.

// Authority Limiters on Servos (not control surfaces)
const double AILERON_SERVO_POS_MIN_DEG = -70;
const double AILERON_SERVO_POS_MAX_DEG = 70;
const double ELEVATOR_SERVO_POS_MIN_DEG = -70;
const double ELEVATOR_SERVO_POS_MAX_DEG = 70;