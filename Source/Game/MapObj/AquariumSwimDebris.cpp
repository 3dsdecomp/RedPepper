#include "Game/MapObj/AquariumSwimDebris.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Stage/StageSwitchKeeper.h"
#include "al/Nerve/NerveFunction.h"

namespace NrvAquariumSwimDebris {

NERVE_DEF(AquariumSwimDebris, nrv1);

} // namespace NrvAquariumSwimDebris

AquariumSwimDebris::AquariumSwimDebris(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void AquariumSwimDebris::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "AquariumSwimDebris", NULL);
    al::initNerve(this, &NrvAquariumSwimDebris::nrv1, 1);
    al::initStageSwitchAppear(this, info);
    al::trySyncStageSwitchAppear(this);
}

void AquariumSwimDebris::exenrv1()
{
    if(al::isFirstStep(this)){
        al::startHitReaction(this, "èoåª");
    }
}
