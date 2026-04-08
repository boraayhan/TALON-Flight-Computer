#pragma once
#include "global/GlobalHeader.h"
#include "data/data_structures/CommunicationPayload/CommunicationPayload.h"

class AntennaPlaceholder {
public: AntennaPlaceholder();
  void AntennaPeriodic(); // Read and parse inputs
  CommunicationVariant get();
  void transmit(CommunicationVariant& payload);
};