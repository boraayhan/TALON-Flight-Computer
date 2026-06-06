#pragma once
#include "global/GlobalHeader.h"

enum class CommType {
  JoystickInput = 0,
  ThrottleInput = 3,
};

struct Payload {
  int32_t id;
  float p1;
  float p2;
};