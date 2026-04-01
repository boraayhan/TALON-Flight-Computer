#include "global/GlobalHeader.h"
#include "data/data_structures/Runway/Runway.h"
#include <iostream>

int main() {
    Runway grassField("Grass Field", Vector3(1,2,3), Vector3(4,5,6));
    Runway parkingLot("Parking Lot", Vector3{0,1,2}, Vector3{3,4,5});

    std::vector<Runway> runways = {grassField, parkingLot};
    for (Runway runway : runways) {
        std::cout << runway.toJSON() << std::endl;
    }
    return 0;
}