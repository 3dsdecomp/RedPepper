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

    friend void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo);
};

void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo);

} // namespace al
