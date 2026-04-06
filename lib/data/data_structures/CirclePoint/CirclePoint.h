#pragma once
#include "global/GlobalHeader.h"

class CirclePoint {
  public:
    CirclePoint(Vector3 position, double radius);
    double getRadius();
    Vector3 getPosition();
    std::string toJSON();

  private:
    Vector3 position;
    double radius;
};