#pragma once
#include "data/sensors/ANTENNA_PLACEHOLDER/AntennaPlaceholder.h"
#include "global/GlobalHeader.h"

class CommunicationManager {
  public:
    CommunicationManager();
    void periodic(); // Parses incoming signals
  private:
    AntennaPlaceholder antenna;
};