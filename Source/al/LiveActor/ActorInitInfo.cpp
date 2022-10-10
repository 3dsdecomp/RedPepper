#include "al/LiveActor/ActorInitInfo.h"
#include "al/Placement/PlacementFunction.h"

namespace al {

#ifdef NON_MATCHING // registers used when copying from base info
void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo)
{
    info->mPlacementInfo = placement;
    info->_4 = baseInfo._4;
    info->_8 = baseInfo._8;
    info->_10 = baseInfo._10;
    info->mViewID = alPlacementFunction::getClippingViewId(placement);
}
#endif

} // namespace al
