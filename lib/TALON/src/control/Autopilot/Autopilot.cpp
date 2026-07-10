#include "control/Autopilot/Autopilot.h"

Autopilot::Autopilot(const FlightState &flightState)
    : flightState(flightState), targetPath(), horizontalAccelerationController(AP_HORIZONTAL_ACCELERATION),
      verticalAccelerationController(AP_VERTICAL_ACCELERATION),
      horizontalDeflectionController(AP_HORIZONTAL_DEFLECTION), verticalDeflectionController(AP_VERTICAL_DEFLECTION) {}

void Autopilot::periodic() {
    switch (autopilotSetting.state) {
    case AutopilotState::OFF: {
        break;
    }
    case AutopilotState::CIRCLE: {

        break;
    }
    case AutopilotState::HOLD: {
        break;
    }
    case AutopilotState::RTB: {
        break;
    }
    case AutopilotState::TOGA: {
        latestFlightCommand = computeTOGAFlightCommand();
        hasNewFlightCommand_ = true;
        break;
    }
    default:
        hasNewFlightCommand_ = false;
        break;
    }
}

void Autopilot::setAutopilotSetting(const AutopilotSetting &s) { autopilotSetting = s; }
bool Autopilot::isEnabled() { return autopilotSetting.state != AutopilotState::OFF; }

const FlightCommand &Autopilot::computeTOGAFlightCommand() {
    return TOGA_FLIGHT_COMMAND; // 0% roll/yaw, 50% pitch, 100% throttle
}

const FlightCommand &Autopilot::getLatestFlightCommand() const { return latestFlightCommand; }

// TODO: Replace me with L1 navigation ("A New Nonlinear Guidance Logic for Trajectory Tracking" (MIT, 2004) by Park et al.) for improved performance
const Vector3 Autopilot::computeLocalTargetAccelerations() {
    GuidanceError error = GuidanceError{0,0,0}; // targetPath.getError(flightState.position);
    return Vector3{0,
                   horizontalAccelerationController.compute(error.altitudeError, 0),
                   verticalAccelerationController.compute(error.crossTrackError, 0)};
}

const FlightCommand Autopilot::localTargetAccelerationsToFlightCommand(float targetAccelX, float targetAccelY) {
    float rollCmd = horizontalDeflectionController.compute(flightState.acceleration.x, targetAccelX);
    float pitchCmd = verticalDeflectionController.compute(flightState.acceleration.x, targetAccelY);
    return FlightCommand{
        rollCmd, pitchCmd, flightState.latestFlightCommand.yaw, flightState.latestFlightCommand.throttle};
}

bool Autopilot::hasNewFlightCommand() { return hasNewFlightCommand_; }