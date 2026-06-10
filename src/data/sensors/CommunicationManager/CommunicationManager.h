#pragma once
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "data/data_structures/CommunicationPayload/CommunicationPayload.h"
#include "global/GlobalHeader.h"
#include <RF24.h>

class CommunicationManager {
  public:
    CommunicationManager(FlightControlsManager *flightControlsManager);
    void periodic(); // Parses incoming signals
    void init();

  private:
    RF24 radio;
    FlightControlsManager *flightControlsManager;
};