#include "control/FlightControlsManager/FlightControlsManager.h"

FlightControlsManager::FlightControlsManager() : controlSurfaceCount(0), landingGearCount(0) {
    for (int i = 0; i < MAX_CONTROL_SURFACES; i++) {
        controlSurfaces[i] = nullptr;
    }
}

void FlightControlsManager::init() {
    this->rollPID = pid(1.0, 0.0, 0.0);  // FIXME: Tune!
    this->pitchPID = pid(1.0, 0.0, 0.0); // FIXME: Tune!
    this->yawPID = pid(1.0, 0.0, 0.0);   // FIXME: Tune!
}

void FlightControlsManager::twoAxisJoystickToPitchRoll(float xAxis, float yAxis) {
    if (xAxis > 1 || yAxis > 1) {
        return;
    }
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface* surface = controlSurfaces[i];
        if (surface != nullptr) {
            if (surface->getType() == AILERON) {
                surface->move(xAxis * AILERON_SERVO_POS_MAX_DEG);
            }
            if (surface->getType() == ELEVATOR) {
                surface->move(yAxis * ELEVATOR_SERVO_POS_MAX_DEG);
            }
        }
    }
}

void FlightControlsManager::rudderPedalToYaw(float zAxis) {
    if (zAxis > 1) {
        return;
    }
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface* surface = controlSurfaces[i];
        if (surface != nullptr && surface->getType() == RUDDER) {
            surface->move(zAxis * RUDDER_SERVO_POS_MAX_DEG);
        }
    }
}
void FlightControlsManager::setThrottle(float throttle) {}

FlightControlsManager& FlightControlsManager::addControlSurface(ControlSurface& surface)
{
    if (this->controlSurfaceCount < MAX_CONTROL_SURFACES) {
        this->controlSurfaces[this->controlSurfaceCount++] = &surface;
    }
    return *this;
}

FlightControlsManager& FlightControlsManager::addLandingGear(LandingGear& gear) {
    if (this->landingGearCount < MAX_LANDING_GEARS) {
        this->landingGears[this->landingGearCount++] = gear;
    }
    return *this;
}

void FlightControlsManager::deployFlaps(float flapsPositionDegrees) {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface* surface = controlSurfaces[i];
        if (surface != nullptr && surface->getType() == FLAP) {
            surface->move(flapsPositionDegrees);
        }
    }
}

void FlightControlsManager::testControlSurfaces() {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface* surface = controlSurfaces[i];
        if (surface != nullptr) {
            surface->test();
        }
    }
}