/**
 * Defines structs for communication, allowing for scalable commands
 * @author: Bora Ayhan
 */

#pragma once
#include "global/GlobalHeader.h"

enum CommType {
    JoystickInput = 0,
    ThrottleInput,
    FlapInput,


};

struct CommunicationPayload {
    CommType type;
};

struct JoystickInput : CommunicationPayload {
    JoystickInput(double xA, double yA);
    double xAxis; // -1.0 to 1.0, such that +1 is right
    double yAxis; // -1.0 to 1.0, such that +1 is forward
};

struct ThrottleInput : CommunicationPayload {
    ThrottleInput(double throttle);
    double throttle; // 0.0 to 1.0, such that 0.0 is idle and 1.0 is full throttle
};

struct FlapInput : CommunicationPayload {
    FlapInput(double flap);
    double flapAngleDegrees; // Representing flap angle in degrees, where 0 degrees is neutral and positive is deployed
};
