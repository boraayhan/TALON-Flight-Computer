#pragma once

#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "data/sensors/CommunicationManager/CommunicationManager.h"
#include "global/GlobalHeader.h"

struct FlightState {
    Vector3 velocity; // Meters per second
    Vector3 position; // Meters, relative to starting position
    FlightCommand latestFlightCommand;
    TrimCommand trim;
};

class TALON {
  public:
    TALON();
    void init();
    void periodic();
    TALON &addControlSurface(ControlSurface &s);
    TALON &addMotor(Motor &m);
    const FlightState &getFlightState() const;
  private:
    FlightControlsManager flightControlsManager;
    Autopilot autopilot;
    CommunicationManager communicationManager;
    FlightState flightState;
};