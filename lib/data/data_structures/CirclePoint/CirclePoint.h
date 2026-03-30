#pragma once
#include "global/GlobalHeader.h"

class CirclePoint {
  public:
    CirclePoint(Vector3 position, double radius);
    double getRadius();
    Vector3 getPosition();

  private:
    Vector3 position;
    double radius;
};