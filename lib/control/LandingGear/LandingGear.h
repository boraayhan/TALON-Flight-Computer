#pragma once

enum LandingGearState {
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
    int GPIO_PIN;
};