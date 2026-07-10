#pragma once
#include "control/Autopilot/DataHeader.h"
#include "control/Autopilot/Pathfinder.h"
#include "global/GlobalHeader.h"

class Autopilot {
  public:
    Autopilot(const FlightState &flightState);
    void periodic();
    void setAutopilotSetting(const AutopilotSetting &s);
    bool isEnabled();
    bool hasNewFlightCommand();
    const FlightCommand &getLatestFlightCommand() const;

  private:
    const FlightState &flightState;
    DubinsPathWrapper targetPath;

    AutopilotSetting autopilotSetting;
    FlightCommand latestFlightCommand;

    const FlightCommand &computeTOGAFlightCommand();
    bool hasNewFlightCommand_;

    /**
     * @returns: Vector3 of form {0, horizontal acceleration, vertical acceleration}, per "Local" convention in /README.md
     */
    const Vector3 computeLocalTargetAccelerations();
    const FlightCommand localTargetAccelerationsToFlightCommand(float xAccel, float yAccel);

    pid horizontalAccelerationController;
    pid verticalAccelerationController;

    pid horizontalDeflectionController;
    pid verticalDeflectionController;
};

// AUTOPILOT STATES:
// OFF = 0,
// CIRCLE,
// HOLD,
// RTB,
// TOGA,
// AUTOTRIM, // Unimplemented at alpha release
// AUTOLAND, // Unimplemented at alpha release