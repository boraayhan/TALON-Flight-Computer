#include "control/LandingGear/LandingGear.h"

LandingGear::LandingGear() {
    this->GPIO_PIN = -1;
    this->deployed = false;

}
LandingGear::LandingGear(int GPIO_PIN)
{
    this->GPIO_PIN = GPIO_PIN;
    this->deployed = false;
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