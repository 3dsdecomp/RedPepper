#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/System/Byaml/ByamlIter.h"

namespace al {

class ActorInitInfo {
    const PlacementInfo* mPlacementInfo;
    void* _4;
    void* _8;
    void* _C;
    void* _10;
    int mViewId;

public:
    ActorInitInfo();

    void initViewIdSelf(const PlacementInfo* placement, const ActorInitInfo& base);
};

void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo);

} // namespace al
