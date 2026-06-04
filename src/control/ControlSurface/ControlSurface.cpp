#include "control/ControlSurface/ControlSurface.h"
#include "global/GlobalHeader.h"

ControlSurface::ControlSurface() {
    this->GPIO_PIN = -1;
    this->type = AILERON;
    this->name = "";
    this->angleZeroDegrees = 0.0f;
    this->angleTrimOffsetDegrees = 0.0f;
    this->angleServoMinDegrees = 0.0f;
    this->angleServoMaxDegrees = 0.0f;
    this->DIRECTION_MULTIPLIER = 1;
}

ControlSurface::ControlSurface(int GPIO_PIN,
                               String name,
                               ControlSurfaceType type,
                               float angleZeroDegrees,
                               float angleServoMinDegrees,
                               float angleServoMaxDegrees,
                               int DIRECTION_MULTIPLIER) {
    this->GPIO_PIN = GPIO_PIN;
    this->angleZeroDegrees = angleZeroDegrees;
    this->angleTrimOffsetDegrees = 0;
    this->angleServoMinDegrees = angleServoMinDegrees;
    this->angleServoMaxDegrees = angleServoMaxDegrees;
    this->DIRECTION_MULTIPLIER = DIRECTION_MULTIPLIER;
    this->type = type;
    this->name = name;
    this->servo.attach(GPIO_PIN);
}

void ControlSurface::test() {
    for(int ang = 0; ang <= this->angleServoMaxDegrees; ang += 5) {
        this->move(ang);
        delay(15);
    }
    for(int ang = this->angleServoMaxDegrees; ang >= this->angleServoMinDegrees; ang -= 5) {
        this->move(ang);
        delay(15);
    }
        for(int ang = this->angleServoMinDegrees; ang <= 0; ang += 5) {
            this->move(ang);
            delay(15);
        }
        this->move(0);
}

void ControlSurface::move(float angle) {
    this->servo.write(this->angleZeroDegrees + this->DIRECTION_MULTIPLIER * angle);
}

int ControlSurface::getDirectionMultiplier() const { return this->DIRECTION_MULTIPLIER; }

void ControlSurface::changeTrim(float angle) {}

ControlSurfaceType ControlSurface::getType() const { return this->type; }