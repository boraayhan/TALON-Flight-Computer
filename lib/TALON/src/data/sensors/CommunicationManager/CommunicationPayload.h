#pragma once
#include "global/GlobalHeader.h"

enum class CommType {
    FlightCommandInput = 0,
    TrimInput = 1,
    AutopilotSettingInput = 2
};

struct Payload {
    int32_t id;
    float p1;
    float p2;
    float p3;
    float p4;
    float p5;
};