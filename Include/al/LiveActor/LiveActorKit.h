#pragma once

#include "al/LiveActor/LiveActorGroup.h"

namespace al {

class LiveActorKit {
    int mAllActorsBufferSize;
    void* unk[14];
    LiveActorGroup* mAllActors;
    void* unk2;

public:
    LiveActorKit(int groupBufSize);

    LiveActorGroup* getAllActors() { return mAllActors; }
};

LiveActorKit* getLiveActorKit();

} // namespace al
