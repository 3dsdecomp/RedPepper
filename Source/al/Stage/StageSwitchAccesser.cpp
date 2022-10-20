#include "al/Stage/StageSwitchAccesser.h"

namespace al {

#pragma O3
StageSwitchAccesser::StageSwitchAccesser()
    : mId(-1)
    , mType(0)
{
}

int StageSwitchAccesser::initWithPlacementInfo(StageSwitchType type1, const PlacementInfo& info, StageSwitchType type2)
{
    const char* type1Name = getStageSwitchName(type1);
    if (mType > (int)type2)
        type2 = (StageSwitchType)mType;
    mId = -1;
    mType = type2;
    info.tryGetIntByKey(&mId, type1Name);
    return FUN_0024e734();
}

bool StageSwitchAccesser::isTypeKillDeadOn() const { return mType == StageSwitchType_Kill || mType == StageSwitchType_DeadOn; }
int StageSwitchAccesser::FUN_0024e734() const { return (mId >> 0x1f) + 1; } // ?

} // namespace al
