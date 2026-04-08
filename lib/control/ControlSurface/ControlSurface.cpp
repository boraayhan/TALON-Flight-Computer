#include "control/ControlSurface/ControlSurface.h"
#include "global/GlobalHeader.h"

ControlSurface::ControlSurface() {}

ControlSurface::ControlSurface(int GPIO_PIN,
                               std::string name,
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
}

void ControlSurface::test() {}

void ControlSurface::move(float angle) {}

int ControlSurface::getDirectionMultiplier() const {
    return this->DIRECTION_MULTIPLIER;
}

void ControlSurface::changeTrim(float angle) {}

ControlSurfaceType ControlSurface::getType() const { return this->type; }