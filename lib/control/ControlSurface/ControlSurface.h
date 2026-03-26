#pragma once

class ControlSurface {
  private:
    // Servo servo;
    int GPIO_PIN;
    float angleZeroDegrees;
    float angleTrimOffsetDegrees;
    float angleServoMinDegrees;
    float angleServoMaxDegrees;     // Maximum angle for servo (not control surface)
    const int DIRECTION_MULTIPLIER; // +1 or -1 to correct for rotational symmetry
  public:
    ControlSurface();             // Constructor and init()
    void test();                  // Drives surface through range of motion
    void move(float angle);       // Sets control surface to angle with respect to zero
    void changeTrim(float angle); // Changes trim by angle
};