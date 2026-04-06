#pragma once

class Propeller {
  private:
    int GPIO_PIN;

  public:
    Propeller();
    Propeller(int GPIO_PIN);
    void setDutyCycle(double dutyCycle); // Sets duty cycle (throttle) to given dutyCycle 0 to 1.
    void setThrottle(double throttle);   // Wrapper for setDutyCycle()
};