#pragma once

#include "al/Clipping/ClippingDirector.h"
#include "al/LiveActor/LiveActorGroup.h"

namespace al {

class LiveActorKit {
    int mAllActorsBufferSize;
    void* _4;
    void* _8;
    void* _C;
    void* _10;
    void* _14;
    void* _18;
    void* _1C;
    void* _20;
    ClippingDirector* mClippingDirector;
    void* _28;
    void* _2C;
    void* _30;
    void* _34;
    void* _38;
    LiveActorGroup* mAllActors;
    void* unk2;

public:
    LiveActorKit(int groupBufSize);

    ClippingDirector* getClippingDirector() const { return mClippingDirector; }
    LiveActorGroup* getAllActors() const { return mAllActors; }
};

LiveActorKit* getLiveActorKit();

} // namespace al
