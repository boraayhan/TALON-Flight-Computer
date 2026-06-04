#pragma once
#include "data/sensors/RF24/RF24.h"
#include "global/GlobalHeader.h"
#include "control/FlightControlsManager/FlightControlsManager.h"

class CommunicationManager {
  public:
    CommunicationManager(FlightControlsManager *flightControlsManager);
    void periodic(); // Parses incoming signals
  private:
    RF24 antenna;
    FlightControlsManager *flightControlsManager;
};