#include "data/sensors/CommunicationManager/CommunicationManager.h"

CommunicationManager::CommunicationManager(FlightControlsManager *flightControlsManager)
    : radio(RADIO_PIN_CE, RADIO_PIN_CSN), flightControlsManager(flightControlsManager)
{
}

void CommunicationManager::init() {
    Serial.begin(115200);
    delay(500);
    Serial.println("Serial initialized.");
    const uint8_t address[][6] = {"1Node", "2Node"};
    if (!radio.begin())
    {
        Serial.println(F("Error: Radio hardware failure!"));
        while (1){};
    }
    radio.setPALevel(RF24_PA_LOW);
    radio.setPayloadSize(sizeof(Payload));

    radio.openWritingPipe(address[1]);
    radio.openReadingPipe(1, address[0]);

    radio.startListening();
    Serial.println("Radio initialized.");
}

void CommunicationManager::periodic() {
    
    Payload payload;
    uint8_t pipe;
    if (this->radio.available(&pipe))
    {
        radio.read(&payload, sizeof(Payload));
        Serial.print(payload.id);
        switch (payload.id)
        {
            case (int32_t)CommType::JoystickInput:
                flightControlsManager->twoAxisJoystickToPitchRoll(payload.p1, payload.p2);
                break;
            case (int32_t)CommType::ThrottleInput:
                flightControlsManager->setThrottle(payload.p1);
                break;
        }
    }
}