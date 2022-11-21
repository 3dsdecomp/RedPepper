#pragma once

#include <sead/container/seadPtrArray.h>

class alSubActorFunction;

namespace al {

class LiveActor;
class ActorInitInfo;

class SubActorKeeper {
    struct Entry {
        LiveActor* actor;
        void* _4;
        u32 _8;
    };

    LiveActor* const mParent;
    sead::PtrArray<Entry> mSubActors;

    SubActorKeeper(al::LiveActor* actor, const al::ActorInitInfo& info, const char*, int);

public:
    static SubActorKeeper* tryCreate(al::LiveActor* actor, const al::ActorInitInfo& info, const char*, int);

    friend class ::alSubActorFunction;
};

} // namespace al
