#include "DubinsPath.h"

// DEFINITIONS FOR CircularPath
CircularPath::CircularPath() {}
CircularPath::CircularPath(float r, TurnDirection d, const Vector3 &c, float iAng, float fAng) {}
CircularPath::CircularPath(float r, TurnDirection d, const Vector3 &c, bool rep) {}

float CircularPath::getTangentHeadingDeg(const Vector3 &flightPos) {
    float centerToFlightPosDeg = headingDegreesXY(flightPos - center);
    if (dir == LEFT) {
        return normalize360(centerToFlightPosDeg - 90);
    } else {
        return normalize360(centerToFlightPosDeg + 90);
    }
}

float CircularPath::getCrossTrackErrorMeters(const Vector3 &flightPos) {
    return (flightPos - center).magnitude() - radius;
}

// DEFINITIONS FOR LineSegment

float CircularPath::getAltitudeErrorMeters(const Vector3 &flightPos) { return (flightPos.z - center.z); }

// DEFINITIONS FOR DubinsPath
float DubinsPath::getTargetHeadingDeg(const Vector3 &flightPos) {}

Vector3 getError(const Vector3 &flightPos) {} // Return Vector3 with {0, xte, alt}