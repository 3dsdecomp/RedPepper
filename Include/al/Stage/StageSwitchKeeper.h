#pragma once

#include "al/LiveActor/ActorInitInfo.h"
#include "al/Stage/StageSwitchAccesser.h"

namespace al {

class StageSwitchKeeper {
    StageSwitchAccesser* mSwitches;
    int mSwitchCount;

public:
    StageSwitchKeeper();

    StageSwitchAccesser* getStageSwitchAccesser(int type);
};

class IUseStageSwitch {
public:
    virtual StageSwitchKeeper* getStageSwitchKeeper() const = 0;
    virtual void initStageSwitchKeeper() = 0;
};

void initStageSwitchAppear(IUseStageSwitch* p, const ActorInitInfo& info);

} // namespace al
