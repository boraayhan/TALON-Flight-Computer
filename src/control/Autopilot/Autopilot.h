#pragma once
#include "control/FlightControlsManager/FlightControlsManager.h"

enum AutopilotAxisState {
    DISABLED = 0,
    ENABLED = 1
};

class Autopilot {
  public:
    Autopilot(FlightControlsManager *flightControlsManager);
    void disable();
    void set(AutopilotAxisState roll, AutopilotAxisState pitch, AutopilotAxisState yaw);
    void periodic();

    // Autopilot
    float ap_target_jx;
    float ap_target_jy;
    float ap_target_jz;

    float input_jx;
    float input_jy;
    float input_jz;

  private:
    FlightControlsManager *flightControlsManager;
    AutopilotAxisState roll;
    AutopilotAxisState pitch;
    AutopilotAxisState yaw;

    // TODO: Figure out control priority method, i.e. whethr to use roll pitch yaw or targets + dubins path
};
