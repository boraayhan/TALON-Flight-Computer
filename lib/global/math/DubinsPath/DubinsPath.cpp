#include "global/math/DubinsPath/DubinsPath.h"

// WARNING: NOT FINISHED!
DubinsPath::DubinsPath(Vector3 i, Vector3 f, Vector3 v, double tr) {
    this->startPoint = i;
    this->endPoint = f;
    this->initVelocity = v;
    this->turningRadius = tr;
    this->timeDelay = 0.0;
}

// WARNING: NOT FINISHED!
DubinsPath::DubinsPath(Vector3 i, Vector3 f, Vector3 v, double tr, double delay) {
    this->startPoint = i + v * delay; //TODO: Pass along pointer to v and reevaluate startpoint
    this->endPoint = f;
    this->initVelocity = v;
    this->turningRadius = tr;
    this->timeDelay = delay;
    Vector3 pL;
    Vector3 pS;
}