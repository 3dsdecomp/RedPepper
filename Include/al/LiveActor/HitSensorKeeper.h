#pragma once

#include "al/HitSensor/HitSensor.h"
#include <sead/container/seadPtrArray.h>

namespace al {

class HitSensorKeeper {
    sead::PtrArray<HitSensor> mSensors;

public:
    void attackSensor();
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();

    void update();

    HitSensor* getSensor(const char* name) const;
};

} // namespace al
