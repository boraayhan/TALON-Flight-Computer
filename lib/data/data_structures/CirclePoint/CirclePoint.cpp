#include "data/data_structures/CirclePoint/CirclePoint.h"

CirclePoint::CirclePoint(Vector3 position, double radius) {
    this->position = position;
    this->radius = radius;
}

double CirclePoint::getRadius() { return this->radius; }

Vector3 CirclePoint::getPosition() { return this->position; }

std::string CirclePoint::toJSON() {
    return "{\"position\": {\"x\": " + std::to_string(this->position.x) +
           ", \"y\": " + std::to_string(this->position.y) +
           ", \"z\": " + std::to_string(this->position.z) +
           "}, \"radius\": " + std::to_string(this->radius) + "}";
}