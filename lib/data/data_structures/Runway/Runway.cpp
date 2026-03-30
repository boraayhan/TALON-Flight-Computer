#include "data/data_structures/Runway/Runway.h"

Runway::Runway(const Vector3 &startPositionMeters, const Vector3 &endPositionMeters) {
    this->startPositionMeters = startPositionMeters;
    this->endPositionMeters = endPositionMeters;
    this->direction = unit(endPositionMeters - startPositionMeters);
}

Runway::Runway(const Vector3 &startPositionMeters,
               double distanceMeters,
               const Vector3 &direction) {
    this->startPositionMeters = startPositionMeters;
    this->direction = unit(direction);
    this->endPositionMeters = startPositionMeters + this->direction * distanceMeters;
    this->lengthMeters = distanceMeters;
}

Vector3 Runway::getStartPointMeters() { return startPositionMeters; }

Vector3 Runway::getEndPointMeters() { return endPositionMeters; }

Vector3 Runway::getDirection() { return direction; }

double Runway::getLengthMeters() { return lengthMeters; }