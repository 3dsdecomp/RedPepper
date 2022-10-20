#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/Stage/StageSwitchType.h"

namespace al {

class StageSwitchAccesser {
    int mId;
    int mType;

public:
    StageSwitchAccesser();

    int initWithPlacementInfo(StageSwitchType type1, const PlacementInfo& info, StageSwitchType type2);

    bool isTypeKillDeadOn() const;
    int FUN_0024e734() const; // ?
};

} // namespace al
