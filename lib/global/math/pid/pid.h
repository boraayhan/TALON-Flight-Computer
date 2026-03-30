#pragma once

// WARNING: NOT FINISHED!
class pid
{
public:
    double compute(double input, double target);
    pid(double KP, double KI, double KD);

private:
    double kP;
    double kI;
    double kD;
    double error;
    unsigned long now;
    double prevError;
    double prevTime;
    double integral;
    double derivative;
};