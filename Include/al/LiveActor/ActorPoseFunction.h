#pragma once

#include "al/LiveActor/LiveActor.h"

class alActorPoseFunction {
public:
    static void calcBaseMtx(sead::Matrix34f* out, const al::LiveActor* actor) { actor->mActorPoseKeeper->calcBaseMtx(out); }
};
