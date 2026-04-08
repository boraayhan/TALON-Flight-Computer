#pragma once
#include "control/FlightControlsManager/FlightControlsManager.h"

enum AutopilotAxis
{
  DISABLED = 0,
  ENABLED = 1
};

class Autopilot
{
public:
  Autopilot(FlightControlsManager *flightControlsManager);
  void disable();
  void enable(AutopilotAxis roll, AutopilotAxis pitch, AutopilotAxis yaw);
  void periodic();
private:
  FlightControlsManager *flightControlsManager;
  AutopilotAxis roll;
  AutopilotAxis pitch;
  AutopilotAxis yaw;
  // TODO: Figure out control priority method, ie whethr to use  roll pitch yaw or targets + dubins path
};
