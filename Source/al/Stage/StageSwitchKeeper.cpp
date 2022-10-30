#include "al/Stage/StageSwitchKeeper.h"
#include "types.h"

namespace al {

NON_MATCHING
StageSwitchKeeper::StageSwitchKeeper()
    : mSwitches(nullptr)
    , mSwitchCount(0)
{
    mSwitchCount = 5; // optimized away
    mSwitches = new StageSwitchAccesser[5];
}

StageSwitchAccesser* StageSwitchKeeper::getStageSwitchAccesser(int type)
{
    return &mSwitches[type];
}

} // namespace al
