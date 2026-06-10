#include "control/FlightControlsManager/FlightControlsManager.h"

FlightControlsManager::FlightControlsManager() : controlSurfaceCount(0), motorCount(0) {
    for (int i = 0; i < MAX_CONTROL_SURFACES; i++) {
        controlSurfaces[i] = nullptr;
    }
    for (int i = 0; i < MAX_MOTORS; i++) {
        motors[i] = nullptr;
    }
    lastThrottleUpdateTime = 0;
}

void FlightControlsManager::twoAxisJoystickToPitchRoll(float xAxis, float yAxis) {
    if (xAxis > 1 || yAxis > 1) {
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
    if (zAxis > 1) {
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
    this->throttle = throttle;
    updateThrottle();
}

FlightControlsManager &FlightControlsManager::addControlSurface(ControlSurface &surface) {
    if (this->controlSurfaceCount < MAX_CONTROL_SURFACES) {
        this->controlSurfaces[this->controlSurfaceCount++] = &surface;
    }
    return *this;
}

FlightControlsManager &FlightControlsManager::addMotor(Motor &motor) {
    if (this->motorCount < MAX_MOTORS) {
        this->motors[this->motorCount++] = &motor;
    }
    return *this;
}

void FlightControlsManager::testControlSurfaces() {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr) {
            surface->test();
        }
    }
}

void FlightControlsManager::updateThrottle() {
    for (uint8_t i = 0; i < motorCount; i++) {
        Motor *motor = motors[i];
        if (motor != nullptr) {
            motor->setThrottle(this->throttle);
        }
    }
}

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

void FlightControlsManager::resetThrottleTimer() { lastThrottleUpdateTime = millis(); }

unsigned long FlightControlsManager::getLastThrottleUpdateTime() const {
    return lastThrottleUpdateTime;
}

void FlightControlsManager::periodic() {
    if ((millis() - lastThrottleUpdateTime > THROTTLE_TIMEOUT_MS) && !TOGA_MODE) {
        setThrottle(0.0f);
        this->twoAxisJoystickToPitchRoll(0, -0.3);
    }
    this->updateThrottle();
    if(TOGA_MODE) {
      this->twoAxisJoystickToPitchRoll(0, 1);
    }
}

void FlightControlsManager::enableTOGA(double togaThrottle) {
    delay(5000);
    twoAxisJoystickToPitchRoll(-1, -1);
    delay(2000);
    twoAxisJoystickToPitchRoll(1, 1);
    delay(2000);
    twoAxisJoystickToPitchRoll(0, 1);
    delay(2000);
    TOGA_MODE = true;
    twoAxisJoystickToPitchRoll(0, 1);
    setThrottle(togaThrottle);
    resetThrottleTimer(); // just in case
}

void FlightControlsManager::changeFlap(float flapAngle) {
    for (uint8_t i = 0; i < controlSurfaceCount; i++) {
        ControlSurface *surface = controlSurfaces[i];
        if (surface != nullptr && surface->getType() == AILERON) {
            surface->changeFlap(flapAngle);
        }
    }
}

void FlightControlsManager::disableTOGA() {
    TOGA_MODE = false;
}