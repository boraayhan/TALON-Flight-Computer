#include "control/FlightControlsManager/FlightControlsManager.h"

FlightControlsManager::FlightControlsManager() {}

void FlightControlsManager::init() {
    rollPID = pid(1.0, 0.0, 0.0);  // FIXME: Tune!
    pitchPID = pid(1.0, 0.0, 0.0); // FIXME: Tune!
}

void FlightControlsManager::twoAxisJoystickToPitchRoll(double xAxis, double yAxis) {}

void FlightControlsManager::setThrottle(double throttle) {}

FlightControlsManager FlightControlsManager::addControlSurface(ControlSurface surface) {
    controlSurfaces.push_back(surface);
    return *this; // Because it looks cool to have a chain of .add().add().add()
}

void FlightControlsManager::deployFlaps(double flapsPositionDegrees) {
    for (ControlSurface &surface : controlSurfaces) {
        if (surface.getType() == FLAP) {
            surface.move(flapsPositionDegrees);
        }
    }
}