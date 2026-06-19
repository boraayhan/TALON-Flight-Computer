#include "data/sensors/CommunicationManager/CommunicationManager.h"

CommunicationManager::CommunicationManager() : radio(RADIO_PIN_CE, RADIO_PIN_CSN) {}

void CommunicationManager::init() {
    Serial.begin(115200);
    delay(500);
    Serial.println("Serial initialized.");
    const uint8_t address[][6] = {"1Node", "2Node"};
    if (!radio.begin()) {
        Serial.println(F("Error: Radio hardware failure!"));
        while (1) {
            delay(10000);
        };
    }
    radio.setPALevel(RF24_PA_LOW);
    radio.setPayloadSize(sizeof(Payload));
    radio.openWritingPipe(address[1]);
    radio.openReadingPipe(1, address[0]);
    radio.startListening();
    Serial.println(F("Radio initialized."));
}

void CommunicationManager::periodic() {
    Payload payload;
    uint8_t pipe;
    while (this->radio.available(&pipe)) {
        radio.read(&payload, sizeof(Payload));
        // Serial.print(payload.id);
        switch (payload.id) {
        case (int32_t)CommType::FlightCommandInput: {
            FlightCommand pilotCmd = {payload.p1, payload.p2, payload.p3, payload.p4};
            latestFlightCommand = pilotCmd;
            newFlightCommandAvailable = true;
            break;
        }
        case (int32_t)CommType::TrimInput: {
            TrimCommand trimCmd = {payload.p1, payload.p2, payload.p3};
            latestTrimCommand = trimCmd;
            newTrimAvailable = true;
            break;
        }
        case (int32_t)CommType::AutopilotSettingInput: {
            AutopilotSetting autopilotSetting = {};
            latestAutopilotSetting = autopilotSetting;
            newAutopilotSettingAvailable = true;
            break;
        }
        }
    }
}

FlightCommand CommunicationManager::getLatestFlightCommand() {
    newFlightCommandAvailable = false;
    return latestFlightCommand;
}

TrimCommand CommunicationManager::getLatestTrimCommand() {
    newTrimAvailable = false;
    return latestTrimCommand;
}

AutopilotSetting CommunicationManager::getLatestAutopilotSetting() {
    newAutopilotSettingAvailable = false;
    return latestAutopilotSetting;
}
