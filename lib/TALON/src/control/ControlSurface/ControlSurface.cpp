#include "control/ControlSurface/ControlSurface.h"

ControlSurface::ControlSurface(int GPIO_PIN,
                               ControlSurfaceType type,
                               float angleZeroDeg,
                               float angleServoMinDeg,
                               float angleServoMaxDeg,
                               int DIRECTION_MULTIPLIER) {
    this->GPIO_PIN = GPIO_PIN;
    this->angleZeroDeg = angleZeroDeg;
    this->angleTrimOffsetDeg = 0;
    this->angleServoMinDeg = angleServoMinDeg;
    this->angleServoMaxDeg = angleServoMaxDeg;
    this->DIRECTION_MULTIPLIER = DIRECTION_MULTIPLIER;
    this->type = type;
}

// FIXME: Potential annoying edge case for certain min/max combos, maybe, idk
void ControlSurface::test() {
    for (int ang = 0; ang <= this->angleServoMaxDeg; ang += 5) {
        this->move(ang);
        delay(15);
    }
    for (int ang = this->angleServoMaxDeg; ang >= this->angleServoMinDeg; ang -= 5) {
        this->move(ang);
        delay(15);
    }
    for (int ang = this->angleServoMinDeg; ang <= 0; ang += 5) {
        this->move(ang);
        delay(15);
    }
    this->move(0);
}

void ControlSurface::move(float angle) {
    this->servo.write(constrain(
        this->angleZeroDeg + this->DIRECTION_MULTIPLIER * angle + this->angleTrimOffsetDeg,
        this->angleZeroDeg + this->angleServoMinDeg,
        this->angleZeroDeg + this->angleServoMaxDeg));
}

int ControlSurface::getDirectionMultiplier() const { return this->DIRECTION_MULTIPLIER; }

void ControlSurface::changeTrim(float angle) { angleTrimOffsetDeg += angle; }

ControlSurfaceType ControlSurface::getType() const { return this->type; }

void ControlSurface::init() {
    this->servo.attach(this->GPIO_PIN);
    this->servo.write(this->angleZeroDeg);
}


void ControlSurface::setFlap(float flapAngle) {
    if (this->type == AILERON || this->type == FLAP) {
        this->flapAngleDeg = flapAngle;
    }
}