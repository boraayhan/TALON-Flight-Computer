#include <Arduino.h>
#include <Servo.h>
#pragma once

enum ControlSurfaceType {
    AILERON, // Controls roll axis, such that a (+k * DIRECTION_MULTIPLIER) command results in CW roll about velocity vector
    ELEVATOR, // Controls pitch axis
    RUDDER,   // Controls yaw axis
};

class ControlSurface {
  private:
    // Servo servo;
    int GPIO_PIN;
    ControlSurfaceType type; // Aileron, Elevator, or Rudder
    String name;             // Ex: Aileron 2, Right Elevator, etc
    float angleZeroDegrees;
    float angleTrimOffsetDegrees;
    float angleServoMinDegrees;
    float angleServoMaxDegrees; // Maximum angle for servo (not control surface)
    int DIRECTION_MULTIPLIER;   // +1 or -1 to correct for rotational symmetry
    Servo servo;

  public:
    void init();
    ControlSurface();
    ControlSurface(int GPIO_PIN,
                   String name,
                   ControlSurfaceType type,
                   float angleZeroDegrees,
                   float angleServoMinDegrees,
                   float angleServoMaxDegrees,
                   int DIRECTION_MULTIPLIER);

    void test();                  // Drives surface through its range of motion
    void move(float angle);       // Sets control surface to angle with respect to zero
    void changeTrim(float angle); // Changes trim by angle
    int getDirectionMultiplier() const;
    String getName() const;
    ControlSurfaceType getType() const;
};