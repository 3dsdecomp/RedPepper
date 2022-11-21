#pragma once

#include "al/HitSensor/HitSensor.h"
#include <sead/container/seadPtrArray.h>

namespace al {

class SensorHitGroup {
    sead::PtrArray<HitSensor> mSensors;

public:
    SensorHitGroup(int, const char* name /* unused */);
};

} // namespace al
