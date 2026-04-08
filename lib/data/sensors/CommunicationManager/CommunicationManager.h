#pragma once
#include "data/sensors/ANTENNA_PLACEHOLDER/AntennaPlaceholder.h"
#include "global/GlobalHeader.h"
#include "control/FlightControlsManager/FlightControlsManager.h"

class CommunicationManager {
  public:
    CommunicationManager(FlightControlsManager *flightControlsManager);
    void periodic(); // Parses incoming signals
  private:
    AntennaPlaceholder antenna;
    FlightControlsManager *flightControlsManager;
};