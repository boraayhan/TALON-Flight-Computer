#pragma once

#include "control/Autopilot/Autopilot.h"
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "communication/CommunicationManager.h"
#include "global/GlobalHeader.h"

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