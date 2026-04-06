#pragma once

#include "control/ControlSurface/ControlSurface.h"
#include "control/LandingGear/LandingGear.h"
#include "global/GlobalHeader.h"
#include "global/math/PID/PID.h"

class FlightControlsManager {
  public:
    FlightControlsManager();
    void init();
    void twoAxisJoystickToPitchRoll(double xAxis, double yAxis);
    void setThrottle(double throttle);
    FlightControlsManager addControlSurface(
        ControlSurface surface); // Returns original object to allow daisy chaining .add()'s
    FlightControlsManager
    addLandingGear(LandingGear gear); // Returns original object to allow daisy chaining .add()'s
    void deployFlaps(double flapsPositionDegrees);
    // void deployAirbrakes(double airbrakesPositionDegrees); <--- Implement later
    void deployLandingGear(LandingGearState landing);

  private:
    std::vector<ControlSurface> controlSurfaces;
    std::vector<LandingGear> landingGears;
    pid rollPID;
    pid pitchPID;
};