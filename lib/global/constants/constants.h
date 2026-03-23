#pragma once

const float FLAPERON_RATIO_CONSTANT = 0.3; // 0 for flaperon mode off, 0.3 recommended
const float AILERON_POS_MIN = -70;
const float AILERON_POS_MAX = 70;
const float ELEVATOR_POS_MIN = -70;
const float ELEVATOR_POS_MAX = 70;
const float AUTOPILOT_DISENGAGE_THRESHOLD = 0.3; // 0 to 1, how "hard" input is needed to disengage AP. > 0.5 is dangerous.