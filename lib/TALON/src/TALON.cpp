#include "TALON.h"

TALON::TALON() : autopilot(flightState) {}
void TALON::init() {}

void TALON::periodic() {
    communicationManager.periodic();
    autopilot.periodic();

    if (communicationManager.hasNewTrimCommand()) {
        flightControlsManager.applyTrimCommand(communicationManager.getLatestTrimCommand());
    }
    if (communicationManager.hasNewAutopilotSetting()) {
        autopilot.setAutopilotSetting(communicationManager.getLatestAutopilotSetting());
    }
    if (autopilot.isEnabled() && autopilot.hasNewFlightCommand()) {
        flightControlsManager.applyFlightCommand(autopilot.getLatestFlightCommand());
    }
    if (communicationManager.hasNewFlightCommand() && !autopilot.isEnabled()) {
        flightControlsManager.applyFlightCommand(communicationManager.getLatestFlightCommand());
    }
    }
}

TALON &TALON::addControlSurface(ControlSurface &s) { flightControlsManager.addControlSurface(s); }
TALON &TALON::addMotor(Motor &m) { flightControlsManager.addMotor(m); }

const FlightState &TALON::getFlightState() const { return flightState; }
