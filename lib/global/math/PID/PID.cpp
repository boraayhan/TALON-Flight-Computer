#include "global/math/PID/PID.h"

// WARNING: NOT FINISHED!
pid::pid() : kP(0), kI(0), kD(0), error(0), now(0), prevError(0), prevTime(0), integral(0), derivative(0) {}

// WARNING: NOT FINISHED!
pid::pid(float KP, float KI, float KD) {
    this->kP = KP;
    this->kI = KI;
    this->kD = KD;
    this->integral = 0.0f;
    this->prevError = 0.0f;
    this->prevTime = 0; // HAL_GetTick();
}

// WARNING: NOT FINISHED!
float pid::compute(float input, float target) {
    float error = target - input;
    unsigned long now = 0; // HAL_GetTick();
    float dt = (now - this->prevTime) / 1000.0f;
    if (dt >= 0.001f) {
        this->derivative = (error - this->prevError) / dt;
    }
    this->integral += error * dt;
    // integral += constrain(error * dt, SOME MIN VALUE, SOME MAX
    // VALUE); // prevents integral windup
    this->prevError = error;
    this->prevTime = now;
    return this->kP * error + this->kI * this->integral + this->kD * this->derivative;
}