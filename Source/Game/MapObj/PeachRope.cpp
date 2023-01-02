#include "Game/MapObj/PeachRope.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"

#pragma O3
PeachRope::PeachRope(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void PeachRope::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "PeachRope");
    makeActorAppeared();
}
