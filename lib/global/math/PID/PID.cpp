#include "global/math/PID/PID.h"

// WARNING: NOT FINISHED!
pid::pid(double KP, double KI, double KD) {
    kP = KP;
    kI = KI;
    kD = KD;
    integral = 0.0f;
    prevError = 0.0f;
    prevTime = 0; // HAL_GetTick();
}

// WARNING: NOT FINISHED!
double pid::compute(double input, double target) {
    double error = target - input;
    unsigned long now = 0; // HAL_GetTick();
    double dt = (now - prevTime) / 1000.0f;
    if (dt >= 0.001f) {
        derivative = (error - prevError) / dt;
    }
    integral += error * dt;
    // integral += constrain(error * dt, SOME MIN VALUE, SOME MAX
    // VALUE); // prevents integral windup
    prevError = error;
    prevTime = now;
    return kP * error + kI * integral + kD * derivative;
}