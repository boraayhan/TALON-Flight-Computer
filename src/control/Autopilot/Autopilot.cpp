#include "control/Autopilot/Autopilot.h"

Autopilot::Autopilot(FlightControlsManager *flightControlsManager) {
  this->flightControlsManager = flightControlsManager;
  this->roll = DISABLED;
  this->pitch = DISABLED;
  this->yaw = DISABLED;
}

void Autopilot::disable() {
  this->roll = DISABLED;
  this->pitch = DISABLED;
  this->yaw = DISABLED;
}

void Autopilot::set(AutopilotAxisState roll, AutopilotAxisState pitch, AutopilotAxisState yaw) {
  this->roll = roll;
  this->pitch = pitch;
  this->yaw = yaw;
}

void Autopilot::periodic() {
  if (this->roll == ENABLED) {
    flightControlsManager->twoAxisJoystickToPitchRoll(ap_target_jx, input_jy);
  }
  if (this->pitch == ENABLED) {
    flightControlsManager->twoAxisJoystickToPitchRoll(input_jx, ap_target_jy);
  }
  if (this->yaw == ENABLED) {
    // TODO: implement
  }
}