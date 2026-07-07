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
    float length() { return (end - start).magnitude(); }
    float slope() {
        float dist2 = (end - start).lengthXY();
        if (dist2 == 0) {
            return 0; // "Uh, actually, it should be +/- infinity!" shut up
        }
        return (end.z - start.z) / dist2;
    }
};

enum TurnDirection {
    LEFT,
    RIGHT
};

class CircularPath {
  public:
    CircularPath();
    CircularPath(float r, TurnDirection d, const Vector3 &c, float iAng, float fAng);
    CircularPath(float r, TurnDirection d, const Vector3 &c, bool rep);

    /**
     * Computes the tangent heading of the circle at 
     * @returns float (0 <= x < 360) representing tangent heading
     */
    float getTangentHeadingDeg(const Vector3 &flightPos);

    /**
     * Computes cross-track error to path at given position. Ignores arc angles, assumes that the circular path is a closed loop.
     */
    float getCrossTrackErrorMeters(const Vector3 &flightPos);

    /**
     * Computes error in altitude given flight position
     */
    float getAltitudeErrorMeters(const Vector3 &flightPos);

  private:
    float radius;
    Vector3 center;

    // Arc Angles. Ex: A Right CircularPath with initial and final arc angles of 90 and 270 would resemble a "U" on a map.
    float initialArcAngleDeg; // Degrees, 0 =< x < 360. 0deg: North, 180deg: South.
    float finalArcAngleDeg;   // Degrees, 0 =< x < 360. 0deg: North, 180deg: South
    TurnDirection dir;
    bool repeat;
};

enum SegmentNumber {
    C1 = 0,
    S = 1,
    C2 = 2
};

class DubinsPath {
  public:
    /**
    * 
    */
    Vector3 getError(const Vector3 &flightPos);
    /**
     * Computes target heading at current section of path. If current path is circular, returns its tangent heading. If current path straight, returns its bearing.
     */
    float getTargetHeadingDeg(const Vector3 &flightPos);

  private:
    CircularPath c1;
    LineSegment s;
    CircularPath c2;

    SegmentNumber currentSegment;
    float currentSegmentProgress; // 0 <= x <= 1
};