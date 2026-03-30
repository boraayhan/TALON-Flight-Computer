#pragma once

class ControlSurface {
  private:
    // Servo servo;
    int GPIO_PIN;
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