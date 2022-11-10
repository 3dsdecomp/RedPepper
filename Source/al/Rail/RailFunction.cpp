#include "al/Rail/RailFunction.h"
#include "al/LiveActor/ActorPoseKeeper.h"

namespace al {

NON_MATCHING
// 4 instructions scrambled at the end
void setSyncRailToStart(LiveActor* actor)
{
    actor->getRailKeeper()->getRailRider()->moveToRailStart();
    setTrans(actor, actor->getRailKeeper()->getRailRider()->getCurrentPos());
}

bool isExistRail(const LiveActor* actor)
{
    if (actor->getRailKeeper())
        return actor->getRailKeeper()->isExistRail();
    return false;
}

} // namespace al
