#include "control/ControlSurface/ControlSurface.h"
#include "global/GlobalHeader.h"

ControlSurface::ControlSurface() {}

ControlSurface::ControlSurface(int GPIO_PIN,
                               std::string name,
                               ControlSurfaceType type,
                               double angleZeroDegrees,
                               double angleServoMinDegrees,
                               double angleServoMaxDegrees,
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

void ControlSurface::move(double angle) {}

void ControlSurface::changeTrim(double angle) {}

ControlSurfaceType ControlSurface::getType() const { return type; }