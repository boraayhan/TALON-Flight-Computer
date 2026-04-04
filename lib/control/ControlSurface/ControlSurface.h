#include <string>
#pragma once

enum ControlSurfaceType {
    AILERON, // Controls roll axis, such that a (+k * DIRECTION_MULTIPLIER) command results in CW roll about velocity vector
    ELEVATOR, // Controls pitch axis
    RUDDER,   // Controls yaw axis
    FLAP, // Increases lift, such that a (+k * DIRECTION_MULTIPLIER) command results in great
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
    ControlSurface(
        int GPIO_PIN,            // Pin assigned to control surface
        std::string name,        // Nickname for debugging, ie "Aileron Left"
        ControlSurfaceType type, // Type of surface (see ControlSurfaceTyp)
        double angleZeroDegrees, // Zero angle for moment == 0
        double angleServoMinDegrees, // Minimum angle for the servo (not surface itself)
        double angleServoMaxDegrees, // Maximum angle for the servo (not surface itself)
        int DIRECTION_MULTIPLIER);   // +1 or -1 to correct for rotational symmetry. See "lib/control/FlightControlsManager" for conventions

    void test();                   // Drives surface through its range of motion
    void move(double angle);       // Sets control surface to angle with respect to zero
    void changeTrim(double angle); // Changes trim by angle
    ControlSurfaceType getType() const;
};