#include "control/FlightControlsManager/FlightControlsManager.h"

FlightControlsManager::FlightControlsManager() {}

void FlightControlsManager::init()
{
    this->rollPID = pid(1.0, 0.0, 0.0);  // FIXME: Tune!
    this->pitchPID = pid(1.0, 0.0, 0.0); // FIXME: Tune!
    this->yawPID = pid(1.0, 0.0, 0.0);   // FIXME: Tune!
}

void FlightControlsManager::twoAxisJoystickToPitchRoll(float xAxis, float yAxis)
{
    if (xAxis > 1 || yAxis > 1)
    {
        // Insert debug statement here
        return;
    }
    for (ControlSurface &surface : this->controlSurfaces)
    {
        // FIXME: Verify!!! This is some evil code
        if (surface.getType() == AILERON)
        {
            if (xAxis < 0)
            {
                surface.move(xAxis * AILERON_SERVO_POS_MIN_DEG * MAX_AUTHORITY_CONSTANT);
            }
            if (xAxis > 0)
            {
                surface.move(xAxis * AILERON_SERVO_POS_MAX_DEG * MAX_AUTHORITY_CONSTANT);
            }
        }
        if (surface.getType() == ELEVATOR)
        {
            if (yAxis < 0)
            {
                surface.move(yAxis * ELEVATOR_SERVO_POS_MIN_DEG * MAX_AUTHORITY_CONSTANT);
            }
            if (yAxis > 0)
            {
                surface.move(yAxis * ELEVATOR_SERVO_POS_MAX_DEG * MAX_AUTHORITY_CONSTANT);
            }
        }
    }
}

void FlightControlsManager::rudderPedalToYaw(float zAxis)
{

    if (zAxis > 1)
    {
        // Insert debug statement here
        return;
    }
    for (ControlSurface &surface : this->controlSurfaces)
    {
        // FIXME: Verify!!! This is some evil code
        if (surface.getType() == RUDDER)
        {
            if (zAxis < 0)
            {
                surface.move(zAxis * RUDDER_SERVO_POS_MIN_DEG * MAX_AUTHORITY_CONSTANT);
            }
            if (zAxis > 0)
            {
                surface.move(zAxis * RUDDER_SERVO_POS_MAX_DEG * MAX_AUTHORITY_CONSTANT);
            }
        }
    }
}
void FlightControlsManager::setThrottle(float throttle) {}

FlightControlsManager FlightControlsManager::addControlSurface(ControlSurface surface)
{
    this->controlSurfaces.push_back(surface);
    return *this; // Because it looks cool to have a chain of .add().add().add()
}

void FlightControlsManager::deployFlaps(float flapsPositionDegrees)
{
    for (ControlSurface &surface : this->controlSurfaces)
    {
        if (surface.getType() == FLAP)
        {
            surface.move(flapsPositionDegrees);
        }
    }
}