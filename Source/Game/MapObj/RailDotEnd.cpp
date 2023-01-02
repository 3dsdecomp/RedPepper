#include "Game/MapObj/RailDotEnd.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"

namespace NrvRailDotEnd {

NERVE_DEF(RailDotEnd, Appear);

} // namespace NrvRailDotEnd

#pragma O3
RailDotEnd::RailDotEnd(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void RailDotEnd::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "RailDotEnd");
    al::initNerve(this, &NrvRailDotEnd::Appear, 0);
    makeActorAppeared();
}

void RailDotEnd::exeAppear()
{
}
