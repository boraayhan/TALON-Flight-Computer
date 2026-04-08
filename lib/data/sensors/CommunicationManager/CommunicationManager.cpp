#include "data/sensors/CommunicationManager/CommunicationManager.h"

CommunicationManager::CommunicationManager(FlightControlsManager *flightControlsManager)
{
    this->flightControlsManager = flightControlsManager;
}

void CommunicationManager::periodic()
{
    CommunicationVariant payload = this->antenna.get();

    CommType payloadType = std::visit([](const auto &message)
                                      { return message.type; }, payload);
    switch (payloadType)
    {
    case CommType::JoystickInput:
        JoystickInput joystickInput = std::get<JoystickInput>(payload);
        flightControlsManager->twoAxisJoystickToPitchRoll(joystickInput.xAxis, joystickInput.yAxis);
        break;
    case CommType::ThrottleInput:
        flightControlsManager->setThrottle(std::get<ThrottleInput>(payload).throttle);
        break;
    case CommType::FlapInput:
        flightControlsManager->deployFlaps(std::get<FlapInput>(payload).flapAngleDegrees);
        break;
    case CommType::JSONWrite:
        break;
    }
}
