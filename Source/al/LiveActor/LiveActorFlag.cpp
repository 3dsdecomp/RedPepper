#include "al/LiveActor/LiveActor.h"

namespace al {

LiveActorFlag::LiveActorFlag()
    : isDead(true)
    , isClipped(false)
    , isInvalidClipping(true)
    , flag4(false)
    , flag5(false)
    , isHideModel(false)
    , isOffCollide(true)
    , flag8(false)
    , flag9(false)
{
}

void offCollide(LiveActor* actor)
{
    actor->getLiveActorFlag().isOffCollide = true;
}

} // namespace al
