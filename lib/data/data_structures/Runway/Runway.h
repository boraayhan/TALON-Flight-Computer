#include "global/GlobalHeader.h"
#pragma once

class Runway
{
public:
  Runway(std::string name, const Vector3 &startPositionMeters,
         const Vector3 &endPositionMeters); // Start position, end position

  Runway(std::string name, const Vector3 &startPositionMeters,
         float distanceMeters,
         const Vector3 &direction); // Start position, distance, direction
  Vector3 getStartPointMeters();
  Vector3 getEndPointMeters();
  Vector3 getDirection();
  float getLengthMeters();

  std::string toJSON();

  std::string getName();

private:
  Vector3 startPositionMeters;
  Vector3 endPositionMeters;
  Vector3 direction;
  float lengthMeters;
  std::string name;
};