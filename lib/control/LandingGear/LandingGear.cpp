#include "control/LandingGear/LandingGear.h"

LandingGear::LandingGear(int GPIO_PIN)
{
    this->GPIO_PIN = GPIO_PIN;
    this->deployed = false; // Start with landing gear retracted
}

void LandingGear::retract() {}

void LandingGear::deploy() {}

void LandingGear::toggleState()
{
    if (this->isDeployed())
    {
        this->retract();
    }
    if (!this->isDeployed())
    {
        this->deploy();
    }
}