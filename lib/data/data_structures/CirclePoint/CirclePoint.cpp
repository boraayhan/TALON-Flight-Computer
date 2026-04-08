#include "data/data_structures/CirclePoint/CirclePoint.h"

CirclePoint::CirclePoint(Vector3 position, float radius)
{
    this->position = position;
    this->radius = radius;
}

float CirclePoint::getRadius() const { return this->radius; }

Vector3 CirclePoint::getPosition() const { return this->position; }

std::string CirclePoint::toJSON() const
{
    return "{\"position\": {\"x\": " + std::to_string(this->position.x) +
           ", \"y\": " + std::to_string(this->position.y) +
           ", \"z\": " + std::to_string(this->position.z) +
           "}, \"radius\": " + std::to_string(this->radius) + "}";
}