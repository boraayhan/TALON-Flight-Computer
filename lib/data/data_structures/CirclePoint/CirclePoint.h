#pragma once
#include "global/GlobalHeader.h"

class CirclePoint {
  public:
    CirclePoint(Vector3 position, float radius);
    float getRadius() const;
    Vector3 getPosition() const;
    std::string toJSON() const;

  private:
    Vector3 position;
    float radius;
};