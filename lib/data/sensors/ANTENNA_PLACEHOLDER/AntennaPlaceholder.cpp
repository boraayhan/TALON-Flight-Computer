#include "data/sensors/ANTENNA_PLACEHOLDER/AntennaPlaceholder.h"

AntennaPlaceholder::AntennaPlaceholder() {}

CommunicationVariant AntennaPlaceholder::get() {
    CommunicationVariant payload;
    payload.type = CommType::JoystickInput;
    payload.xAxis = 0.0f;
    payload.yAxis = 0.0f;
    return payload; // FIXME: Read incoming value instead of placeholder
}

void AntennaPlaceholder::transmit(CommunicationVariant& payload) {
    // rf24.write(&payload, sizeof(payload));
}