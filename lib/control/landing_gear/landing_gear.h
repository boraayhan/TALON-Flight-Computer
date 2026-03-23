#pragma once

static enum LANDING_GEAR_STATE {
    RETRACTED = 0,
    DEPLOYED = 1
};

class LandingGear
{
public:
    LandingGear(int GPIO_PIN);
    void retract();
    void deploy();
    void toggleState();
    bool isDeployed();
private:
    bool deployed;
};