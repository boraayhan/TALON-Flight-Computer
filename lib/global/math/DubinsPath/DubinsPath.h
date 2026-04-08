#pragma once

#include "global/GlobalHeader.h"

enum DubinsPathType {
    LSL = 0,
    LSR,
    LRL,
    RSL,
    RSR,
    RLR
};

// WARNING: NOT FINISHED!
class DubinsPath {
    float turningRadius;
    DubinsPathType type;
    Vector3 startPoint; // Start of Dubins path, accounts for delay
    Vector3 endPoint;
    Vector3 initVelocity;
    float timeDelay;

    DubinsPath(Vector3 i, Vector3 f, Vector3 v, float tr);
    DubinsPath(Vector3 i, Vector3 f, Vector3 v, float tr, float delay);
};