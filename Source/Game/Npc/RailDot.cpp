#include "Game/MapObj/RailDot.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"

namespace NrvRailDot {

NERVE_DEF(RailDot, Wait);

} // namespace NrvRailDot

#pragma O3
RailDot::RailDot(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void RailDot::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "RailDot");
    al::initNerve(this, &NrvRailDot::Wait);
    makeActorAppeared();
}

void RailDot::exeWait()
{
}
