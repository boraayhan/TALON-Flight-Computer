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
               double distanceMeters,
               const Vector3 &direction) {
    this->name = name;
    this->startPositionMeters = startPositionMeters;
    this->direction = unit(direction);
    this->endPositionMeters = startPositionMeters + this->direction * distanceMeters;
    this->lengthMeters = distanceMeters;
}

Vector3 Runway::getStartPointMeters() { return startPositionMeters; }

Vector3 Runway::getEndPointMeters() { return endPositionMeters; }

Vector3 Runway::getDirection() { return direction; }

double Runway::getLengthMeters() { return lengthMeters; }

std::string Runway::toJSON() {
    return "{\"name\": \"" + this->name +
           "\", \"startPosition\": {\"x\": " + std::to_string(startPositionMeters.x) +
           ", \"y\": " + std::to_string(startPositionMeters.y) +
           ", \"z\": " + std::to_string(startPositionMeters.z) +
           "}, \"endPosition\": {\"x\": " + std::to_string(endPositionMeters.x) +
           ", \"y\": " + std::to_string(endPositionMeters.y) +
           ", \"z\": " + std::to_string(endPositionMeters.z) + "}}";
}

std::string Runway::getName() { return name; }