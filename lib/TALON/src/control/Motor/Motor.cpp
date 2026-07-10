#include "control/Motor/Motor.h"

Motor::Motor() {}

Motor::Motor(int GPIO_PIN) { this->GPIO_PIN = GPIO_PIN; }

void Motor::setDutyCycle(float dutyCycle) {
  int us = constrain(1000 + dutyCycle * 1000, 1000, 2000);
  this->motor.writeMicroseconds(us);
}

void Motor::setThrottle(float throttle) { setDutyCycle(throttle); }

void Motor::init() {
  Serial.println("Motor init called for pin: " + String(this->GPIO_PIN));
  bool attached = this->motor.attach(this->GPIO_PIN);
  Serial.println("Servo attach result: " + String(attached));
  this->motor.writeMicroseconds(1000);
  Serial.println("Motor init complete");
}