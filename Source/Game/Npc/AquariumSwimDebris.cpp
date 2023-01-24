#include "Game/MapObj/AquariumSwimDebris.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Stage/StageSwitchKeeper.h"

namespace NrvAquariumSwimDebris {

NERVE_DEF(AquariumSwimDebris, Appear);

} // namespace NrvAquariumSwimDebris

AquariumSwimDebris::AquariumSwimDebris(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void AquariumSwimDebris::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "AquariumSwimDebris", nullptr);
    al::initNerve(this, &NrvAquariumSwimDebris::Appear, 1);
    al::initStageSwitchAppear(this, info);
    al::trySyncStageSwitchAppear(this);
}

void AquariumSwimDebris::exeAppear()
{
    if (al::isFirstStep(this)) {
        al::startHitReaction(this, "èoåª");
    }
}
