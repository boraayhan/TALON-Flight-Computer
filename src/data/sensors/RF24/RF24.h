#pragma once
#include "data/data_structures/CommunicationPayload/CommunicationPayload.h"
#include "global/GlobalHeader.h"
#include <RF24.h>

uint8_t address[][6] = {"1Node", "2Node"};

class RF24 {
  private:
    ::RF24 radio; // TODO: Fix
  public:
    RF24();
    void init();
    void AntennaPeriodic(); // Read and parse inputs
    CommunicationVariant get();
    void transmit(CommunicationVariant &payload);
};