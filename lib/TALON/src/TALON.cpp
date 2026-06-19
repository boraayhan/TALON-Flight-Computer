#include "TALON.h"

TALON::TALON() {}

void TALON::init() {}

void TALON::periodic() {
    // Poll latest from CommManager
    // Feed autopilot flightstate
    if (communicationManager.newFlightCommandAvailable) {
        flightControlsManager.applyFlightCommand(communicationManager.getLatestFlightCommand());
    }
    if (communicationManager.newTrimAvailable) {
        flightControlsManager.applyFlightCommand(communicationManager.getLatestFlightCommand());
    }
}

const FlightState &TALON::getFlightState() const { return flightState; }

TALON &TALON::addControlSurface(ControlSurface &s) { flightControlsManager.addControlSurface(s); }

TALON &TALON::addMotor(Motor &m) { flightControlsManager.addMotor(m); }