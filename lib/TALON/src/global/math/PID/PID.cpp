#include "global/math/PID/PID.h"

// WARNING: NOT FINISHED!
pid::pid(pidSetting s) {
    kP = s.kP;
    kI = s.kI;
    kD = s.kD;
    integral = 0.0f;
    prevError = 0.0f;
    prevTime = 0; // HAL_GetTick();
}

// WARNING: NOT FINISHED!
float pid::compute(float input, float target) {
    float error = target - input;
    unsigned long now = 0;
    float dt = (now - this->prevTime) / 1000.0f;
    if (dt >= 0.001f) {
        this->derivative = (error - this->prevError) / dt;
    }
    this->integral += error * dt;
    // integral += constrain(error * dt, SOME MIN VALUE, SOME MAX VALUE); // prevents integral windup
    this->prevError = error;
    this->prevTime = now;
    return this->kP * error + this->kI * this->integral + this->kD * this->derivative;
}