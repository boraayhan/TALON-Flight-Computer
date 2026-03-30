#pragma once

#include "control/ControlSurface/ControlSurface.h"
#include "global/GlobalHeader.h"

class FlightControlsManager {
  public:
    void twoAxisJoystickToPitchRoll(double xAxis, double yAxis);
    void setThrottle(double throttle);
  private:
};

enum ControlSurfaces {
    AILERON_LEFT = 0,
    AILERON_RIGHT,
    ELEVATOR_LEFT,
    ELEVATOR_RIGHT,
    num_surface
};

ControlSurface surfaces[num_surface] = {};