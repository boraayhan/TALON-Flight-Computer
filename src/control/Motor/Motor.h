#pragma once
#include <Arduino.h>
#include <Servo.h>

class Motor {
private:
  int GPIO_PIN;
  Servo motor;

public:
  Motor();
  Motor(int GPIO_PIN);
  void init();
  void setDutyCycle(
      float dutyCycle); // Sets duty cycle (throttle) to given dutyCycle 0 to 1.
  void setThrottle(float throttle); // Wrapper for setDutyCycle()
};