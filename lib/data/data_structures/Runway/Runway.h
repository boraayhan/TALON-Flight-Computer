#include "global/GlobalHeader.h"
#pragma once

class Runway {
  public:
    Runway(const Vector3 &startPositionMeters,
           const Vector3 &endPositionMeters); // Start position, end position

    Runway(const Vector3 &startPositionMeters,
           double distanceMeters,
           const Vector3 &direction); // Start position, distance, direction
    Vector3 getStartPointMeters();
    Vector3 getEndPointMeters();
    Vector3 getDirection();
    double getLengthMeters();

  private:
    Vector3 startPositionMeters;
    Vector3 endPositionMeters;
    Vector3 direction;
    double lengthMeters;
};