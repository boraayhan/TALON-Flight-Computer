#pragma once
#include "global/GlobalHeader.h"

enum DubinsPathType {
    LSL = 0,
    LSR,
    LRL,
    RSL,
    RSR,
    RLR
};

struct LineSegment {
    Vector3 start;
    Vector3 end;
    float length() { return (start - end).magnitude(); }
};

enum TurnDirection {
    LEFT,
    RIGHT
};

class CircularPath {
    public:
    CircularPath(float r, const Vector3 &c, float iAng, float fAng);
    CircularPath(float r, const Vector3 &c);
    float radius;
    Vector3 center;
    // Arc Angles. Ex: A Right CircularPath with initial and final arc angles of 90 and 270 would resemble a "U" on a map.
    bool repeat;
    float initialArcAngleDeg; // Degrees, 0 =< x < 360. 0deg: North, 180deg: South.
    float finalArcAngleDeg;   // Degrees, 0 =< x < 360. 0deg: North, 180deg: South
    TurnDirection dir;

    /**
     * Computes the tangent heading of the circle at 
     * @returns float (0 <= x < 360) representing tangent heading, or -1 if tangent heading does not exist at given position. 
     */
    float getTangentHeadingDeg(const Vector3 &flightPos);

    /**
     * Computes cross-track error to path at given position. Ignores arc angles, assumes that the circular path is a closed loop.
     */
    float getCrossTrackErrorMeters(const Vector3 &flightPos);
};

struct DubinsPath {
    CircularPath c1;
    LineSegment s;
    CircularPath c2;
};