#pragma once
#include "data/data_structures/DataStructuresHeader.h"
#include "global/GlobalHeader.h"
// WARNING: NOT FINISHED!
class SD
{
public:
  SD();                                 // Maybe intake some parameters, idk, that's a problem for later me
  void writeJSONEntry(std::string jsonData); // Writes given object to SD card using its .toJSON() function
  std::vector<Runway> getRunways();
};