#include "data/sensors/ANTENNA_PLACEHOLDER/AntennaPlaceholder.h"

AntennaPlaceholder::AntennaPlaceholder() {}

CommunicationVariant AntennaPlaceholder::get() {
    // payload = (rf24.read()), basically parse incoming
    return JoystickInput(0.0, 0.0); // FIXME: Read incoming value instead of placeholder
}

void AntennaPlaceholder::transmit(CommunicationVariant& payload) {
    // rf24.write(&payload, sizeof(payload));
}