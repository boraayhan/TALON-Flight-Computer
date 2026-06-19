#include "control/FlightControlsManager/FlightControlsManager.h"

// Overhaul: Stupid to have MAX_N, make it dynamic, we live in 2026 not 1980 ffs
FlightControlsManager::FlightControlsManager() : controlSurfaceCount(0), motorCount(0) {
    for (int i = 0; i < MAX_CONTROL_SURFACES; i++) {
        controlSurfaces[i] = nullptr;
    }
    for (int i = 0; i < MAX_MOTORS; i++) {
        motors[i] = nullptr;
    }
    lastThrottleUpdateTime = 0;
}

// Overhaul: Remove nullptr checks
void FlightControlsManager::init() {
    Serial.println("Total motors to init: " + String(motorCount));
    for (uint8_t i = 0; i < motorCount; i++) {
        Motor *motor = motors[i];
        Serial.println("Attempting to init motor " + String(i));
        if (motor != nullptr) {
            motor->init();
        }
    }
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            surface->init();
        }
    }
    Serial.println("Control Manager initialized.");
}

void FlightControlsManager::applyFlightCommand(const FlightCommand &command) {
    twoAxisJoystickToPitchRoll(command.roll, command.pitch);
    rudderPedalToYaw(command.yaw);
    setThrottle(command.throttle);
}

// Overhaul: Privatize
void FlightControlsManager::twoAxisJoystickToPitchRoll(float xAxis, float yAxis) {
    if (abs(xAxis) > 1 || abs(yAxis) > 1) {
        return;
    }
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
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
    if (abs(zAxis) > 1) {
        return;
    }
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr && surface->getType() == RUDDER) {
            surface->move(zAxis * RUDDER_SERVO_POS_MAX_DEG);
        }
    }
}
void FlightControlsManager::setThrottle(float throttle) {
    if (throttle > 1 || throttle < 0) {
        return;
    }
    this->throttle = throttle;
    updateThrottle();
}

void FlightControlsManager::addControlSurface(ControlSurface &surface) {
    if (this->controlSurfaceCount < MAX_CONTROL_SURFACES) {
        this->controlSurfaces[this->controlSurfaceCount++] = &surface;
    }
}

void FlightControlsManager::addMotor(Motor &motor) {
    if (this->motorCount < MAX_MOTORS) {
        this->motors[this->motorCount++] = &motor;
    }
}

// Overhaul: Remove checks for nullptr, make it reference instead
void FlightControlsManager::testControlSurfaces() {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            surface->test();
        }
    }
}

// Overhaul: Remove checks for nullptr, make it reference instead
void FlightControlsManager::updateThrottle() {
    for (uint8_t i = 0; i < motorCount; i++) {
        Motor *motor = motors[i];
        if (motor != nullptr) {
            motor->setThrottle(this->throttle);
        }
    }
}

// Overhaul: Make it intake TrimCommand
void FlightControlsManager::changeTrim(float rollChangeDeg, float pitchChangeDeg) {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            if (surface->getType() == AILERON) {
                surface->changeTrim(rollChangeDeg);
            }
            if (surface->getType() == ELEVATOR) {
                surface->changeTrim(pitchChangeDeg);
            }
        }
    }
}
// Overhaul: Remove from FCM
void FlightControlsManager::resetThrottleTimer() { lastThrottleUpdateTime = millis(); }

unsigned long FlightControlsManager::getLastThrottleUpdateTime() const {
    return lastThrottleUpdateTime;
}

// Overhaul: Should be done by TALON
// void FlightControlsManager::periodic() {
//     if ((millis() - lastThrottleUpdateTime > THROTTLE_TIMEOUT_MS) && !TOGA_MODE) {
//         setThrottle(0.0f);
//         this->twoAxisJoystickToPitchRoll(0, -0.3);
//     }
//     this->updateThrottle();
//     if (TOGA_MODE) {
//         this->twoAxisJoystickToPitchRoll(0, 1);
//     }
// }

// Overhaul: Make it reference-based, remove nullptr check
void FlightControlsManager::setFlap(float flapAngle) {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            surface->setFlap(flapAngle);
        }
    }
}
