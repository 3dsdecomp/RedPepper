#include "Game/MapObj/PeachRope.h"
#include "al/LiveActor/ActorActionKeeper.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"

PeachRope::PeachRope(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void PeachRope::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "PeachRope");
    makeActorAppeared();
}

void PeachRope::kill()
{
    al::startHitReactionDeath(this);
    LiveActor::kill();
}
