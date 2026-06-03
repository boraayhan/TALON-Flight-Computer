#include "control/FlightControlsManager/FlightControlsManager.h"

FlightControlsManager::FlightControlsManager() {}

void FlightControlsManager::init() {
    this->rollPID = pid(1.0, 0.0, 0.0);  // FIXME: Tune!
    this->pitchPID = pid(1.0, 0.0, 0.0); // FIXME: Tune!
    this->yawPID = pid(1.0, 0.0, 0.0);   // FIXME: Tune!
}

void FlightControlsManager::twoAxisJoystickToPitchRoll(float xAxis, float yAxis) {
    if (xAxis > 1 || yAxis > 1) {
        // Insert debug statement here
        return;
    }
    for (ControlSurface &surface : this->controlSurfaces) {
        if (surface.getType() == AILERON) {
            surface.move(xAxis * AILERON_SERVO_POS_MAX_DEG);
        }
        if (surface.getType() == ELEVATOR) {
            surface.move(yAxis * ELEVATOR_SERVO_POS_MAX_DEG);
        }
    }
}

void FlightControlsManager::rudderPedalToYaw(float zAxis) {

    if (zAxis > 1) {
        // Insert debug statement here
        return;
    }
    for (ControlSurface &surface : this->controlSurfaces) {
        // FIXME: Verify!!! This is some evil code
        if (surface.getType() == RUDDER) {
            surface.move(zAxis * RUDDER_SERVO_POS_MAX_DEG);
        }
    }
}
void FlightControlsManager::setThrottle(float throttle) {}

FlightControlsManager FlightControlsManager::addControlSurface(ControlSurface surface) {
    this->controlSurfaces.push_back(surface);
    return *this; // Because it looks cool to have a chain of .add().add().add()
}

void FlightControlsManager::deployFlaps(float flapsPositionDegrees) {
    for (ControlSurface &surface : this->controlSurfaces) {
        if (surface.getType() == FLAP) {
            surface.move(flapsPositionDegrees);
        }
    }
}