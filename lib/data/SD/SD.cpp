#include "data/SD/SD.h"

SD::SD() {
    // Init logic
}

Runway* SD::getRunways(uint8_t &count) {
    count = 0;
    // Read from SD card json (file: config/Runways.json), parse into runways
    return nullptr;
}

void SD::writeJSONEntry(String jsonData) {
    //
}