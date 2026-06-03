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
  FlightControlsManager addControlSurface(ControlSurface surface);
  FlightControlsManager addLandingGear(LandingGear gear);
  void deployFlaps(float flapsPositionDegrees);
  // void deployAirbrakes(float airbrakesPositionDegrees); <--- Implement later
  void setLandingGear(LandingGearState landing);

private:
  static const uint8_t MAX_CONTROL_SURFACES = 8;
  static const uint8_t MAX_LANDING_GEARS = 4;

  ControlSurface controlSurfaces[MAX_CONTROL_SURFACES];
  LandingGear landingGears[MAX_LANDING_GEARS];
  uint8_t controlSurfaceCount;
  uint8_t landingGearCount;
  pid rollPID;
  pid pitchPID;
  pid yawPID;
};