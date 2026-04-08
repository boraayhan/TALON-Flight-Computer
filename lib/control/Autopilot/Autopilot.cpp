#include "control/Autopilot/Autopilot.h"

Autopilot::Autopilot(FlightControlsManager *flightControlsManager)
{
    this->flightControlsManager = flightControlsManager;
    this->roll = DISABLED;
    this->pitch = DISABLED;
    this->yaw = DISABLED;
}

void Autopilot::disable()
{
    this->roll = DISABLED;
    this->pitch = DISABLED;
    this->yaw = DISABLED;
}

void Autopilot::enable(AutopilotAxis roll, AutopilotAxis pitch, AutopilotAxis yaw)
{
    this->roll = roll;
    this->pitch = pitch;
    this->yaw = yaw;
}

void Autopilot::periodic()
{
    if (this->roll == ENABLED)
    {
    }
    if (this->pitch == ENABLED)
    {
    }
    if (this->yaw == ENABLED)
    {
    }
}