#include "DubinsPath.h"

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