#pragma once

#include "al/Functor/FunctorBase.h"
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
void initStageSwitchKill(IUseStageSwitch* p, const ActorInitInfo& info);
void initStageSwitchA(IUseStageSwitch* p, const ActorInitInfo& info);
void initStageSwitchB(IUseStageSwitch* p, const ActorInitInfo& info);

bool isOnSwitchA(IUseStageSwitch* p);

bool listenStageSwitchOnAppear(IUseStageSwitch* p, const FunctorBase& onFunctor, const FunctorBase& offFunctor);

} // namespace al
