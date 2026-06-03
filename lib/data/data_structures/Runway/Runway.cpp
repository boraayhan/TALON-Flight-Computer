#include "data/data_structures/Runway/Runway.h"

Runway::Runway(String name,
               const Vector3 &startPositionMeters,
               const Vector3 &endPositionMeters) {
    this->name = name;
    this->startPositionMeters = startPositionMeters;
    this->endPositionMeters = endPositionMeters;
    this->direction = unit(endPositionMeters - startPositionMeters);
}

Runway::Runway(String name,
               const Vector3 &startPositionMeters,
               float distanceMeters,
               const Vector3 &direction) {
    this->name = name;
    this->startPositionMeters = startPositionMeters;
    this->direction = unit(direction);
    this->endPositionMeters = startPositionMeters + this->direction * distanceMeters;
    this->lengthMeters = distanceMeters;
}

Vector3 Runway::getStartPointMeters() { return this->startPositionMeters; }

Vector3 Runway::getEndPointMeters() { return this->endPositionMeters; }

Vector3 Runway::getDirection() { return this->direction; }

float Runway::getLengthMeters() { return this->lengthMeters; }

String Runway::toJSON() {
    return "{\"name\": \"" + this->name +
           "\", \"startPosition\": {\"x\": " + String(this->startPositionMeters.x, 2) +
           ", \"y\": " + String(this->startPositionMeters.y, 2) +
           ", \"z\": " + String(this->startPositionMeters.z, 2) +
           "}, \"endPosition\": {\"x\": " + String(this->endPositionMeters.x, 2) +
           ", \"y\": " + String(this->endPositionMeters.y, 2) +
           ", \"z\": " + String(this->endPositionMeters.z, 2) + "}}";
}

String Runway::getName() { return this->name; }