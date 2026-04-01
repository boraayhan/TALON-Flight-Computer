#include "data/data_structures/CirclePoint/CirclePoint.h"

CirclePoint::CirclePoint(Vector3 position, double radius)
{
    this->position = position;
    this->radius = radius;
}

double CirclePoint::getRadius() { return radius; }

Vector3 CirclePoint::getPosition() { return position; }