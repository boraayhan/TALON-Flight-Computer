#pragma once
#include "control/FlightControlsManager/FlightControlsManager.h"
#include "data/data_structures/CommunicationPayload/CommunicationPayload.h"
#include "global/GlobalHeader.h"
#include <RF24.h>
#include "control/Autopilot/Autopilot.h"


class CommunicationManager {
  public:
    CommunicationManager(FlightControlsManager *flightControlsManager, Autopilot *autopilot);
    void periodic(); // Parses incoming signals
    void init();

  private:
    RF24 radio;
    FlightControlsManager *flightControlsManager;
    Autopilot *autopilot;
};