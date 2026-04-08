#include "control/Propeller/Propeller.h"

Propeller::Propeller()
{
    
}

Propeller::Propeller(int GPIO_PIN)
{
    this->GPIO_PIN = GPIO_PIN;
    
}

void Propeller::init() {
    // STM32 specific init code below
    
}
