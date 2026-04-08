#include "data/sensors/ANTENNA_PLACEHOLDER/AntennaPlaceholder.h"

AntennaPlaceholder::AntennaPlaceholder() {}

CommunicationVariant AntennaPlaceholder::get() {
    // payload = (rf24.read()), basically parse incoming
    return JoystickInput(0.0, 0.0);
}

void AntennaPlaceholder::transmit(CommunicationVariant& payload) {
    // rf24.write(&payload, sizeof(payload));
}