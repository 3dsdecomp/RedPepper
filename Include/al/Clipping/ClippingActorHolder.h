#pragma once

#include "al/Clipping/ClippingActorInfoList.h"
#include "al/HitSensor/HitSensor.h"

namespace al {

class ClippingActorHolder {
    int _0;
    int _4;
    ClippingActorInfoList* _8;
    ClippingActorInfoList* _C;
    ClippingActorInfoList* _10;
    ClippingActorInfoList* _14;

public:
    ClippingActorHolder(int);

    void invalidateClipping(LiveActor* actor);
    void validateClipping(LiveActor* actor);
};

} // namespace al
