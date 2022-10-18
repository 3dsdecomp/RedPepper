#include "al/LiveActor/ActorInitInfo.h"
#include "al/Placement/PlacementFunction.h"
#include <limits>

namespace al {

#pragma O3
ActorInitInfo::ActorInitInfo()
    : mPlacementInfo(nullptr)
    , _4(nullptr)
    , _8(nullptr)
    , _C(nullptr)
    , _10(nullptr)
    , mViewId(-1)
{
}

void ActorInitInfo::initViewIdSelf(const PlacementInfo* placement, const ActorInitInfo& base)
{
    mPlacementInfo = placement;
    _4 = base._4;
    _8 = base._8;
    _10 = base._10;
    mViewId = alPlacementFunction::getClippingViewId(*placement);
}

#ifdef NON_MATCHING // registers used when copying from base info
void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo)
{
    info->initViewIdSelf(placement, baseInfo);
}
#endif

} // namespace al
