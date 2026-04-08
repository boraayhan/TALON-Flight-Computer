#include "data/data_structures/Runway/Runway.h"

Runway::Runway(std::string name,
               const Vector3 &startPositionMeters,
               const Vector3 &endPositionMeters) {
    this->name = name;
    this->startPositionMeters = startPositionMeters;
    this->endPositionMeters = endPositionMeters;
    this->direction = unit(endPositionMeters - startPositionMeters);
}

Runway::Runway(std::string name,
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

std::string Runway::toJSON() {
    return "{\"name\": \"" + this->name +
           "\", \"startPosition\": {\"x\": " + std::to_string(this->startPositionMeters.x) +
           ", \"y\": " + std::to_string(this->startPositionMeters.y) +
           ", \"z\": " + std::to_string(this->startPositionMeters.z) +
           "}, \"endPosition\": {\"x\": " + std::to_string(this->endPositionMeters.x) +
           ", \"y\": " + std::to_string(this->endPositionMeters.y) +
           ", \"z\": " + std::to_string(this->endPositionMeters.z) + "}}";
}

std::string Runway::getName() { return this->name; }