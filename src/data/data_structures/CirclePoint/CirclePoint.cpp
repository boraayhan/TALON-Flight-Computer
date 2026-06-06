#include "data/data_structures/CirclePoint/CirclePoint.h"

CirclePoint::CirclePoint(Vector3 position, float radius) {
  this->position = position;
  this->radius = radius;
}

float CirclePoint::getRadius() const { return this->radius; }

Vector3 CirclePoint::getPosition() const { return this->position; }

String CirclePoint::toJSON() const {
  return "{\"position\": {\"x\": " + String(this->position.x, 2) + ", \"y\": " + String(this->position.y, 2) +
         ", \"z\": " + String(this->position.z, 2) + "}, \"radius\": " + String(this->radius, 2) + "}";
}