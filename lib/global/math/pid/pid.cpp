#include "global/math/pid/pid.h"

pid::pid(float KP, float KI, float KD)
{
    kP = KP;
    kI = KI;
    kD = KD;
    integral = 0.0f;
    prevError = 0.0f;
    prevTime = HAL_GetTick();
}

float pid::compute(float input, float target)
{
    float error = target - input;
    unsigned long now = HAL_GetTick();
    float dt = (now - prevTime) / 1000.0f;
    if (dt >= 0.001f)
    {
        derivative = (error - prevError) / dt;
    }
    integral += error * dt;
    // integral += constrain(error * dt, SOME MIN VALUE, SOME MAX VALUE); // prevents integral windup
    prevError = error;
    prevTime = now;
    return kP * error + kI * integral + kD * derivative;
}