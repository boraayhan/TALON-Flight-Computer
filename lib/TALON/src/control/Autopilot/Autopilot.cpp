#include "control/Autopilot/Autopilot.h"

Autopilot::Autopilot(const FlightState &flightState) : flightState(flightState) {}
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
        hasNewFlightCommand = true;
        break;
    }
    default:
        hasNewFlightCommand = false;
        break;
    }
}
// AUTOPILOT STATES:
// OFF = 0,
// CIRCLE,
// HOLD,
// RTB,
// TOGA,
// AUTOTRIM, // Unimplemented at alpha release
// AUTOLAND, // Unimplemented at alpha release

void Autopilot::setAutopilotSetting(const AutopilotSetting &s) { autopilotSetting = s; }
bool Autopilot::isEnabled() { return autopilotSetting.state != AutopilotState::OFF; }

const FlightCommand &Autopilot::computeTOGAFlightCommand() {
    return TOGA_FLIGHT_COMMAND; // 0% roll/yaw, 50% pitch, 100% throttle
}

const FlightCommand &Autopilot::getLatestFlightCommand() { return latestFlightCommand; }