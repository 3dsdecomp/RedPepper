#include "al/Rail/RailFunction.h"
#include "al/LiveActor/ActorPoseKeeper.h"

namespace al {

#ifdef NON_MATCHING // 4 instructions scrambled at the end
void setSyncRailToStart(LiveActor* actor)
{
    actor->getRailKeeper()->getRailRider()->moveToRailStart();
    setTrans(actor, actor->getRailKeeper()->getRailRider()->getCurrentPos());
}
#endif

} // namespace al
