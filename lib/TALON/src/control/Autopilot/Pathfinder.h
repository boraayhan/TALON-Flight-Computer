#pragma once
#include "global/GlobalHeader.h"
#include "control/Autopilot/DubinsPathGenerator/dubins.h"

enum PathType {
    LEFT,
    RIGHT,
    STRAIGHT
};

struct PathSegment { // L, R, or S segment
    PathType type;
    Vector3 start;
    float lengthMeters;

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
};



struct GuidanceError
{
    float crossTrackError;
    float altitudeError;
    float headingError;
};

class DubinsPathWrapper {
  public:
    GuidanceError getError(const Vector3 &flightPos) {
        float minCrossTrackError = segments[0].getCrossTrackErrorMeters(flightPos);
        float altitudeError, headingError;
        for(int i = 1; i < 3; i++) {
            float dist = segments[i].getCrossTrackErrorMeters(flightPos);
            if(dist < minCrossTrackError) {
                minCrossTrackError = dist;
                altitudeError = segments[i].getAltitudeErrorMeters(flightPos);
                headingError = segments[i].getTangentHeadingDeg(flightPos)  ;
            }
        }
        return GuidanceError{minCrossTrackError, altitudeError, headingError};
    }
    /**
     * Computes target heading at current section of path. If current path is circular, returns its tangent heading. If current path straight, returns its bearing.
     */

  private:
    PathSegment segments[3];
    DubinsPathType pathType;
};