#include "control/Autopilot/Pathfinder.h"

// DEFINITIONS FOR PathSegment

// float PathSegment::getTangentHeadingDeg(const Vector3 &flightPos) {
//     float centerToFlightPosDeg = headingDegreesXY(flightPos - center);
//     if (dir == LEFT) {
//         return normalize360(centerToFlightPosDeg - 90);
//     } else {
//         return normalize360(centerToFlightPosDeg + 90);
//     }
// }

// float PathSegment::getCrossTrackErrorMeters(const Vector3 &flightPos) {
//     return (flightPos - center).magnitude() - radius;
// }

// // DEFINITIONS FOR LineSegment

// float PathSegment::getAltitudeErrorMeters(const Vector3 &flightPos) { return (flightPos.z - center.z); }

// // DEFINITIONS FOR DubinsPath
// float DubinsPathWrapper::getTargetHeadingDeg(const Vector3 &flightPos) {}

// GuidanceError DubinsPathWrapper::getError(const Vector3 &flightPos) {} // Return GuidanceError with {0, xte, alt}