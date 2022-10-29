#pragma once

#include <sead/container/seadPtrArray.h>

namespace al {

class LiveActor;
class ActorInitInfo;

class SubActorKeeper {
    LiveActor* const mParent;
    sead::PtrArray<LiveActor> mSubActors;

public:
    SubActorKeeper(al::LiveActor* actor, const al::ActorInitInfo& info, const char*, int);

    static SubActorKeeper* tryCreate(al::LiveActor* actor, const al::ActorInitInfo& info, const char*, int);
};

} // namespace al
