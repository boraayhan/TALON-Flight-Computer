#include "control/FlightControlsManager/FlightControlsManager.h"

FlightControlsManager::FlightControlsManager() {}

void FlightControlsManager::twoAxisJoystickToPitchRoll(double xAxis, double yAxis) {}

void FlightControlsManager::setThrottle(double throttle) {}

FlightControlsManager FlightControlsManager::addControlSurface(ControlSurface surface) {
    controlSurfaces.push_back(surface);
    return *this;
}

void FlightControlsManager::deployFlaps(double flapsPositionDegrees) {
    for(ControlSurface surface : controlSurfaces) {
        if (surface.getType() == FLAP) {
            surface.move(flapsPositionDegrees);
        }
    }
}

void FlightControlsManager::deployAirbrakes(double airbrakesPositionDegrees) {
    for(ControlSurface surface : controlSurfaces) {
        if (surface.getType() == AIRBRAKE) {
            surface.move(airbrakesPositionDegrees);
        }
    }
}