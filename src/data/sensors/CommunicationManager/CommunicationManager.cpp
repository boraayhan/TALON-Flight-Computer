// ADIRU1 protocol?

#include "data/sensors/CommunicationManager/CommunicationManager.h"

CommunicationManager::CommunicationManager(FlightControlsManager *flightControlsManager) {
    this->flightControlsManager = flightControlsManager;
}

void CommunicationManager::periodic() {
    CommunicationVariant payload = this->antenna.get();

    switch (payload.type) {
    case CommType::JoystickInput:
        flightControlsManager->twoAxisJoystickToPitchRoll(payload.xAxis, payload.yAxis);
        break;
    case CommType::ThrottleInput:
        flightControlsManager->setThrottle(payload.throttle);
        break;
    case CommType::JSONWrite:
        break;
    case CommType::YawInput:
        flightControlsManager->rudderPedalToYaw(payload.zAxis);
        break;
    }
}
