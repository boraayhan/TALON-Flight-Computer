#pragma once
#include "math/Vector/Vector.h"

// Data Structs
struct FlightCommand {
    float roll;     // -1 to 1
    float pitch;    // -1 to 1
    float yaw;      // -1 to 1
    float throttle; // 0 to 1
};

struct TrimCommand { // Trim setting relative to initial zeroPos of surfaces, NOT a change in trim.
    float rollDeg;
    float pitchDeg;
    float yawDeg;
};

enum AutopilotState {
    OFF = 0,
    CIRCLE,
    HOLD,
    RTB,
    TOGA,
    AUTOTRIM, // Unimplemented at alpha release
    AUTOLAND, // Unimplemented at alpha release
};

struct AutopilotSetting {
    AutopilotState state;
};

struct FlightState {
    Vector3 velocity; // Meters per second
    Vector3 position; // Meters, relative to starting position
    FlightCommand latestFlightCommand;
    TrimCommand trim;
};