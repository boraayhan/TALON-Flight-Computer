#pragma once

#include "control/ControlSurface/ControlSurface.h"
#include "control/LandingGear/LandingGear.h"
#include "global/GlobalHeader.h"
#include "global/math/PID/PID.h"

class FlightControlsManager
{
public:
  FlightControlsManager();
  void init();
  void twoAxisJoystickToPitchRoll(float xAxis, float yAxis); // x: roll/aileron, y: pitch/elevator
  void rudderPedalToYaw(float zAxis);
  void setThrottle(float throttle);
  FlightControlsManager addControlSurface(
      ControlSurface surface);                            // Returns original object to allow daisy chaining .add()'s
  FlightControlsManager addLandingGear(LandingGear gear); // Returns original object to allow daisy chaining .add()'s
  void deployFlaps(float flapsPositionDegrees);
  // void deployAirbrakes(float airbrakesPositionDegrees); <--- Implement later
  void setLandingGear(LandingGearState landing);

private:
  std::vector<ControlSurface> controlSurfaces;
  std::vector<LandingGear> landingGears;
  pid rollPID;
  pid pitchPID;
  pid yawPID;
};