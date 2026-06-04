#include "data/sensors/RF24/RF24.h"

RF24::RF24() {}

CommunicationVariant RF24::get() {
    CommunicationVariant payload;
    uint8_t pipe;
    if (radio.available(&pipe)) {
        radio.read(&payload, sizeof(CommunicationVariant)); // Receive the payload
    }
    payload.type = CommType::JoystickInput;
    payload.xAxis = 0.0f;
    payload.yAxis = 0.0f;
    return payload; // FIXME: Read incoming value instead of placeholder
}
