#include "global/math/DubinsPath/DubinsPath.h"

// WARNING: NOT FINISHED!
DubinsPath::DubinsPath(Vector3 i, Vector3 f, Vector3 v, double tr) {
    startPoint = i;
    endPoint = f;
    initVelocity = v;
    turningRadius = tr;
    timeDelay = 0.0;
}

// WARNING: NOT FINISHED!
DubinsPath::DubinsPath(Vector3 i, Vector3 f, Vector3 v, double tr, double delay) {
    startPoint = i + v * delay; //TODO: Pass along pointer to v and reevaluate startpoint
    endPoint = f;
    initVelocity = v;
    turningRadius = tr;
    timeDelay = delay;
    Vector3 pL;
    Vector3 pS;
}