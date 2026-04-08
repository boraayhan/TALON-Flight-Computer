#pragma once

// Flight Modes
const float FLAPERON_RATIO_CONSTANT = 0.3;       // 0 for flaperon mode off, 0.3 recommended
const float AUTOPILOT_DISENGAGE_THRESHOLD = 0.3; // 0 to 1, how "hard" input is needed to disengage AP. > 0.5 is dangerous.

// Authority Limiters on Servos (not control surfaces)
const float AILERON_SERVO_POS_MIN_DEG = -70;
const float AILERON_SERVO_POS_MAX_DEG = 70;
const float ELEVATOR_SERVO_POS_MIN_DEG = -70;
const float ELEVATOR_SERVO_POS_MAX_DEG = 70;
const float RUDDER_SERVO_POS_MIN_DEG = -70;
const float RUDDER_SERVO_POS_MAX_DEG = 70;
const float MAX_AUTHORITY_CONSTANT = 0.8; // Represents how far the control surface will go into its max position during joystick (e.g, 0.8 means it will only go up to 80% of its max position)