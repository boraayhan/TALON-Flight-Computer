#pragma once
#include "global/GlobalHeader.h"

struct CommunicationPayload {
private:
  int id;
  std::string data;

private:
  CommunicationPayload(int id, std::string data) {}
};
class AntennaPlaceholder {
public: AntennaPlaceholder();
  void AntennaPeriodic(); // Read and parse inputs
  void transmit(int request_id, std::string data);
};