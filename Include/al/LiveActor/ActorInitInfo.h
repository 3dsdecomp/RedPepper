#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/System/Byaml/ByamlIter.h"

namespace al {

class ActorInitInfo {
public:
    const PlacementInfo* mPlacementInfo;
    void* _4;
    void* _8;
    void* _C;
    void* _10;
    int mViewId;

    ActorInitInfo();

    void initViewIdSelf(const PlacementInfo* placement, const ActorInitInfo& base);

    friend const PlacementInfo& getPlacementInfo(const ActorInitInfo& info);
};

inline const PlacementInfo& getPlacementInfo(const ActorInitInfo& info) { return *info.mPlacementInfo; }

void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo);

} // namespace al
