#pragma once

#include "al/LiveActor/LiveActor.h"
#include "sead/container/seadPtrArray.h"

namespace al {

class LiveActorGroup {
    const char* const mName;

public:
    sead::PtrArray<LiveActor> mActors;

    LiveActorGroup(const char* name, int bufSize);

    virtual void registerActor(LiveActor* actor);
};

} // namespace al
