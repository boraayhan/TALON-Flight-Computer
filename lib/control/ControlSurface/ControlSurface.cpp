#include "control/ControlSurface/ControlSurface.h"
#include "global/GlobalHeader.h"

ControlSurface::ControlSurface() {}

ControlSurface::ControlSurface(int GPIO_PIN,
                               double angleZeroDegrees,
                               double angleTrimOffsetDegrees,
                               double angleServoMinDegrees,
                               double angleServoMaxDegrees,
                               int DIRECTION_MULTIPLIER) {
    this->GPIO_PIN = GPIO_PIN;
    this->angleZeroDegrees = angleZeroDegrees;
    this->angleTrimOffsetDegrees = angleTrimOffsetDegrees;
    this->angleServoMinDegrees = angleServoMinDegrees;
    this->angleServoMaxDegrees = angleServoMaxDegrees;
    this->DIRECTION_MULTIPLIER = DIRECTION_MULTIPLIER;
}

void ControlSurface::test() {}

void ControlSurface::move(double angle) {}

void ControlSurface::changeTrim(double angle) {}
