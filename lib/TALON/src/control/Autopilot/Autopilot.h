#pragma once
#include "control/Autopilot/DataHeader.h"
#include "global/GlobalHeader.h"

class Autopilot {
  public:
    Autopilot(const FlightState &flightState);
    void periodic();
    void setAutopilotSetting(const AutopilotSetting &s);
    bool isEnabled();
    bool hasNewFlightCommand();
    const FlightCommand &getLatestFlightCommand();

  private:
    const FlightState &flightState;

    AutopilotSetting autopilotSetting;
    FlightCommand latestFlightCommand;

    const FlightCommand &computeTOGAFlightCommand();
    bool hasNewFlightCommand;
};

// AUTOPILOT STATES:
// OFF = 0,
// CIRCLE,
// HOLD,
// RTB,
// TOGA,
// AUTOTRIM, // Unimplemented at alpha release
// AUTOLAND, // Unimplemented at alpha release