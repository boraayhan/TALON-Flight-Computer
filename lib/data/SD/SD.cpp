#include "data/SD/SD.h"

SD::SD() {
    // Init logic
}

std::vector<Runway> SD::getRunways() {
    std::vector<Runway> runways;
    // Read from SD card json (file: config/Runways.json), parse into runways
    return runways;
}

void SD::writeJSONEntry(std::string jsonData) {
    //
}