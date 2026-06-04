#include "control/Motor/Motor.h"

Motor::Motor()
{
    motor.attach(GPIO_PIN);
    motor.writeMicroseconds(1000);    
}

Motor::Motor(int GPIO_PIN)
{
    this->GPIO_PIN = GPIO_PIN;
    motor.attach(GPIO_PIN);
    motor.writeMicroseconds(1000);
}

void Motor::setDutyCycle(float dutyCycle) {
    int us = constrain(1000 + dutyCycle * 1000, 1000, 2000);
    motor.writeMicroseconds(us);
}

void Motor::setThrottle(float throttle) {
    setDutyCycle(throttle);
}