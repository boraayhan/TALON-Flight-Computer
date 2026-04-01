#include <string>
#pragma once

enum ControlSurfaceType {
    AILERON,  // Controls roll axis
    ELEVATOR, // Controls pitch axis
    RUDDER,   // Controls yaw axis
    FLAP,     // Increases lift
    AIRBRAKE, // Creates drag
};

class ControlSurface {
  private:
    // Servo servo;
    int GPIO_PIN;
    ControlSurfaceType type; // Aileron, Elevator, or Rudder
    std::string name;        // Ex: Aileron 2, Right Elevator, etc
    double angleZeroDegrees;
    double angleTrimOffsetDegrees;
    double angleServoMinDegrees;
    double angleServoMaxDegrees; // Maximum angle for servo (not control surface)
    int DIRECTION_MULTIPLIER;    // +1 or -1 to correct for rotational symmetry
  public:
    ControlSurface(); // Constructor and init()
    ControlSurface(int GPIO_PIN,
                   double angleZeroDegrees,
                   double angleTrimOffsetDegrees,
                   double angleServoMinDegrees,
                   double angleServoMaxDegrees,
                   int DIRECTION_MULTIPLIER); // Constructor and init()
    void test();                              // Drives surface through range of motion
    void move(double angle);                  // Sets control surface to angle with respect to zero
    void changeTrim(double angle);            // Changes trim by angle
};