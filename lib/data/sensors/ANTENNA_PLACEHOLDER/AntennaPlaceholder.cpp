#include "data/sensors/ANTENNA_PLACEHOLDER/AntennaPlaceholder.h"

AntennaPlaceholder::AntennaPlaceholder() {}

CommunicationPayload AntennaPlaceholder::get() {
    CommunicationPayload payload;
    // payload = (rf24.read()), basically parse incoming 
    return payload;
}

void AntennaPlaceholder::transmit(CommunicationPayload& payload) {
    // rf24.write(&payload, sizeof(payload));
}