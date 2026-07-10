#pragma once

#include "control/ControlSurface/ControlSurface.h"
#include "control/Motor/Motor.h"
#include "global/GlobalHeader.h"
#include "global/math/PID/PID.h"

class FlightControlsManager {
  public:
    FlightControlsManager();
    void init();
    void applyFlightCommand(const FlightCommand &command);
    void addControlSurface(ControlSurface &surface);
    void addMotor(Motor &motor);
    void testControlSurfaces();

    void applyTrimCommand(const TrimCommand &t);

  private:
    float throttle;
    unsigned long lastThrottleUpdateTime;

    void updateThrottle();
    void setFlap(float flapAngle);
    void twoAxisJoystickToPitchRoll(float xAxis, float yAxis); // x: roll/aileron, y: pitch/elevator
    void rudderPedalToYaw(float zAxis);
    void setThrottle(float throttle);
    uint8_t controlSurfaceCount;
    uint8_t motorCount;

    static const uint8_t MAX_CONTROL_SURFACES = 4;
    static const uint8_t MAX_MOTORS = 2;
    ControlSurface *controlSurfaces[MAX_CONTROL_SURFACES];
    Motor *motors[MAX_MOTORS];
};