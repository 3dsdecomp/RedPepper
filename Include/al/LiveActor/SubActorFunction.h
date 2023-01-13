#pragma once

#include "al/LiveActor/SubActorKeeper.h"

class alSubActorFunction {
public:
    static void trySyncAlive(al::SubActorKeeper* p);
    static void trySyncDead(al::SubActorKeeper* p);

    static void trySyncClippingStart(al::SubActorKeeper* p);
    static void trySyncClippingEnd(al::SubActorKeeper* p);

    static void tryCalcAnim(al::SubActorKeeper* p);
};
