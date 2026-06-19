#pragma once
#include "control/Autopilot/DataHeader.h"

enum AutopilotState {
    OFF = 0,
    CIRCLE,
    HOLD,
    AUTOLAND, // RTB for now
    AUTOTRIM,
    TOGA
};

struct AutopilotSetting {
    AutopilotState state;
};

class Autopilot {
  public:
    Autopilot();
    void disable();
    void periodic();

    // Autopilot
    // TODO: Figure out control priority method, i.e. whethr to use roll pitch yaw or targets + dubins path
};
