#include "control/FlightControlsManager/FlightControlsManager.h"

// Overhaul: Stupid to have MAX_N, make it dynamic, we live in 2026 not 1980 ffs
FlightControlsManager::FlightControlsManager() : controlSurfaceCount(0), motorCount(0) {
    for (int i = 0; i < MAX_CONTROL_SURFACES; i++) {
        controlSurfaces[i] = nullptr;
    }
    for (int i = 0; i < MAX_MOTORS; i++) {
        motors[i] = nullptr;
    }
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
    if (abs(command.roll) > 1 || abs(command.pitch) > 1 || abs(command.yaw) > 1 || abs(command.throttle - 0.5) > 0.5) {
        return;
    }

    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            if (surface->getType() == AILERON) {
                surface->move(command.roll * AILERON_SERVO_POS_MAX_DEG);
            }
            if (surface->getType() == ELEVATOR) {
                surface->move(command.pitch * ELEVATOR_SERVO_POS_MAX_DEG);
            }
            if (surface->getType() == RUDDER) {
                surface->move(command.yaw * RUDDER_SERVO_POS_MAX_DEG);
            }
        }
    }
    throttle = command.throttle;
    updateThrottle();
}

void FlightControlsManager::applyTrimCommand(const TrimCommand &t) {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            switch (surface->getType()) {
            case (AILERON): {
                surface->changeTrim(t.rollDeg);
                break;
            }
            case (ELEVATOR): {
                surface->changeTrim(t.pitchDeg);
                break;
            }
            case (RUDDER): {
                surface->changeTrim(t.yawDeg);
                break;
            }
            }
        }
    }
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

// Overhaul: Make it reference-based, remove nullptr check
void FlightControlsManager::setFlap(float flapAngle) {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            surface->setFlap(flapAngle);
        }
    }
}
