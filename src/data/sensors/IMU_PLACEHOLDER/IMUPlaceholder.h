#pragma once
#include "global/GlobalHeader.h"

class IMUPlaceholder
{
public:
    IMUPlaceholder();
    void init();
    Vector3 getAcceleration();
    Quaternion getOrientation();
private:

};