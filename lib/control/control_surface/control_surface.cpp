#include "control/control_surface/control_surface.h"
#include "global/global_header.h"

void ControlSurface::init()
{
    servo.attach(PIN_SIGNAL);
    move(0);
}

void ControlSurface::test()
{
    for (float i = 0; i < max; i++)
    {
        move(i);
        delay(5);
    }

    for (float i = max; i > min; i--)
    {
        move(i);
        delay(5);
    }

    for (float i = min; i <= 0; i += 1.0)
    {
        move(i);
        delay(5);
    }
    move(0);
}

void ControlSurface::move(float angle)
{                                                                                                   // Moves to specified angle, accounting for zero-level
    float target = constrain((angle + trimAngle + flap * FLAPERON_RATIO_CONSTANT), min, max) * dir; // TODO: Verify
    // Serial.println(target);
    servo.write(zero + target);
}

void ControlSurface::trim(float angle)
{
    trimAngle += dir * angle;
}

ControlSurface surfaces[num_surface] = {
    {Servo(), 3, 90, 0, AILERON_POS_MIN, AILERON_POS_MAX, -1},   // AILERON_LEFT
    {Servo(), 4, 90, 0, AILERON_POS_MIN, AILERON_POS_MAX, -1},   // AILERON_RIGHT
    {Servo(), 5, 90, 0, ELEVATOR_POS_MIN, ELEVATOR_POS_MAX, 1},  // ELEVATOR_LEFT
    {Servo(), 6, 70, 0, ELEVATOR_POS_MIN, ELEVATOR_POS_MAX, -1}, // ELEVATOR_RIGHT
};

void MoveSurfaces(float jR, float jP)
{                                                                  // Translates a value (-1.00 to 1.00) to aileron and elevator motion
    float pAileron = jR * (AILERON_POS_MAX - AILERON_POS_MIN) / 2; // TODO: Verify whether div by 2 is correct
    float pElevator = jP * (ELEVATOR_POS_MAX - ELEVATOR_POS_MIN) / 2;

    surfaces[AILERON_LEFT].move(pAileron);
    surfaces[AILERON_RIGHT].move(pAileron);
    surfaces[ELEVATOR_LEFT].move(pElevator);
    surfaces[ELEVATOR_RIGHT].move(pElevator);
}

void TestSurfaces()
{
    for (ControlSurface &s : surfaces)
    {
    }
}

void SetBankAngle(float angle)
{
    // Maybe some PID magic here
}