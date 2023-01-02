#include "Game/MapObj/FlowerPot.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"

namespace NrvFlowerPot {

NERVE_DEF(FlowerPot, Appear);

} // namespace NrvFlowerPot

#pragma O3
FlowerPot::FlowerPot(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void FlowerPot::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "FlowerPot");
    al::initNerve(this, &NrvFlowerPot::Appear, 0);
    makeActorAppeared();
}

void FlowerPot::exeAppear()
{
}
