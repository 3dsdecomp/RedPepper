#include "Game/MapObj/RailDotEnd.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"

namespace NrvRailDotEnd {

NERVE_DEF(RailDotEnd, Wait);

} // namespace NrvRailDotEnd

RailDotEnd::RailDotEnd(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void RailDotEnd::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "RailDotEnd");
    al::initNerve(this, &NrvRailDotEnd::Wait);
    makeActorAppeared();
}

void RailDotEnd::exeWait()
{
}
