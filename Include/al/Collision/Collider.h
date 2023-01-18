#pragma once

#include "types.h"

namespace al {

class Collider {
    u8 _0[0xc0];
    float mGroundDistance;

public:
    float getGroundDistance() { return mGroundDistance; }

    void onInvalidate();
};

} // namespace al
