#pragma once

#include "control/ControlSurface/ControlSurface.h"
#include "control/Motor/Motor.h"
#include "global/GlobalHeader.h"
#include "global/math/PID/PID.h"

struct FlightCommand {
    float roll;     // -1 to 1
    float pitch;    // -1 to 1
    float yaw;      // -1 to 1
    float throttle; // 0 to 1
};

struct TrimCommand { // Trim setting relative to initial zeroPos of surfaces, NOT a change in trim.
    float rollDeg;
    float pitchDeg;
    float yawDeg;
};

class FlightControlsManager {
  public:
    FlightControlsManager();
    void init();
    void applyFlightCommand(const FlightCommand &command);
    void addControlSurface(ControlSurface &surface);
    void addMotor(Motor &motor);
    void testControlSurfaces();

    void applyTrimCommand(TrimCommand command);
    void changeTrim(float rollChangeDeg, float pitcfloathChangeDeg);
    unsigned long getLastThrottleUpdateTime() const;

  private:
    float throttle;
    boolean TOGA_MODE = false;
    unsigned long lastThrottleUpdateTime;

    void updateThrottle();
    void setFlap(float flapAngle);
    void twoAxisJoystickToPitchRoll(float xAxis, float yAxis); // x: roll/aileron, y: pitch/elevator
    void rudderPedalToYaw(float zAxis);
    void setThrottle(float throttle);
    uint8_t controlSurfaceCount;
    uint8_t motorCount;
    void resetThrottleTimer();

    static const uint8_t MAX_CONTROL_SURFACES = 4;
    static const uint8_t MAX_MOTORS = 2;
    ControlSurface *controlSurfaces[MAX_CONTROL_SURFACES];
    Motor *motors[MAX_MOTORS];
};