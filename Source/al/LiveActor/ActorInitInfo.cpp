#include "al/LiveActor/ActorInitInfo.h"
#include "al/Placement/PlacementFunction.h"
#include <limits>

namespace al {

ActorInitInfo::ActorInitInfo()
    : mPlacementInfo(nullptr)
    , _4(nullptr)
    , _8(nullptr)
    , _C(nullptr)
//, _10(nullptr)
//, mViewId(-1)
{
    *(s64*)&_10 = -0x0000000100000000;
    // gets split into 2 strs, instead of storing nullptr and -1 with stm
}

#ifdef NON_MATCHING // registers used when copying from base info
void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo)
{
    info->mPlacementInfo = placement;
    info->_4 = baseInfo._4;
    info->_8 = baseInfo._8;
    info->_10 = baseInfo._10;
    info->mViewId = alPlacementFunction::getClippingViewId(placement);
}
#endif

} // namespace al
