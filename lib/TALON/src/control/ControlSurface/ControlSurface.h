#pragma once
#include "global/GlobalHeader.h"
#include <Servo.h>

enum ControlSurfaceType {
    AILERON, // Controls roll axis, such that a (+k * DIRECTION_MULTIPLIER) command results in CW roll about velocity vector
    ELEVATOR, // Controls pitch axis
    RUDDER,   // Controls yaw axis
    FLAP
};

class ControlSurface {
  private:
    int GPIO_PIN;
    ControlSurfaceType type; // Aileron, Elevator, or Rudder
    String name;             // Ex: Aileron 2, Right Elevator, etc
    float angleZeroDeg;
    float angleTrimOffsetDeg;
    float angleServoMinDeg; // Minimum angle relative to zeroAngleDeg for servo (not control surface)
    float angleServoMaxDeg; // Maximum angle relative to zeroAngleDeg for servo (not control surface)
    int DIRECTION_MULTIPLIER;   // +1 or -1 to correct for rotational symmetry
    Servo servo;
    float flapAngleDeg; // Applies to flaps and ailerons with flaperon mode.

  public:
    void init();
    ControlSurface(int GPIO_PIN,
                   String name,
                   ControlSurfaceType type,
                   float angleZeroDeg,
                   float angleServoMinDeg,
                   float angleServoMaxDeg,
                   int DIRECTION_MULTIPLIER);

    void test();                  // Drives surface through its range of motion
    void move(float angle);       // Sets control surface to angle with respect to zero
    void changeTrim(float angle); // Changes trim by angle
    int getDirectionMultiplier() const;
    String getName() const;
    ControlSurfaceType getType() const;
    void setFlap(float flapAngle);
};