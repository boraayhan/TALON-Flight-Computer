#pragma once
#include "control/Autopilot/DataHeader.h"
#include "global/GlobalHeader.h"
// WARNING: NOT FINISHED!
class SD {
  public:
    SD();                                 // Maybe intake some parameters, idk, that's a problem for later me
    void writeJSONEntry(String jsonData); // Writes given object to SD card using
                                          // its .toJSON() function
    Runway *getRunways(uint8_t &count);
};