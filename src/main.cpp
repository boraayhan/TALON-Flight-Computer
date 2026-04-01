#include "lib/control/Autopilot/Autopilot.h"
#include "lib/control/FlightControlsManager/FlightControlsManager.h"
#include "global/GlobalHeader.h"

FlightControlsManager flightControlsManager;

int main() {
    flightControlsManager.addControlSurface();
    while (true) {
        periodic();
    }
}

int periodic() {}