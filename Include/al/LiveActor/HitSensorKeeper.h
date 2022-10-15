#pragma once

#include "al/LiveActor/HitSensor.h"
#include <sead/container/seadPtrArray.h>

namespace al {

class HitSensorKeeper {
    sead::PtrArray<HitSensor> mSensors;

public:
    void attackSensor();
    void validateBySystem();
    void invalidateBySystem();

    void update();
};

} // namespace al
