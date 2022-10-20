#include "al/Stage/StageSwitchKeeper.h"
#include "types.h"

namespace al {

#ifdef NON_MATCHING
StageSwitchKeeper::StageSwitchKeeper()
    : mSwitches(nullptr)
    , mSwitchCount(0)
{
    mSwitchCount = 5; // optimized away
    mSwitches = new StageSwitchAccesser[5];
}
#endif

StageSwitchAccesser* StageSwitchKeeper::getStageSwitchAccesser(int type)
{
    return &mSwitches[type];
}

} // namespace al
