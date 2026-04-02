#pragma once

#include "control/ControlSurface/ControlSurface.h"
#include "global/GlobalHeader.h"

class FlightControlsManager {
  public:
    FlightControlsManager();
    void twoAxisJoystickToPitchRoll(double xAxis, double yAxis);
    void setThrottle(double throttle);
    FlightControlsManager addControlSurface(
        ControlSurface surface); // Returns original object to allow daisy chaining .add
    void deployFlaps(double flapsPositionDegrees);
    void deployAirbrakes(double airbrakesPositionDegrees);

  private:
    std::vector<ControlSurface> controlSurfaces;
};