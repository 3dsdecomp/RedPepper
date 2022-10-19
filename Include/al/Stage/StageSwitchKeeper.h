#pragma once

namespace al {

class StageSwitchKeeper {
    void* mSwitches; // array of something, 5x8 bytes
    int mSwitchCount;

public:
    StageSwitchKeeper();
};

class IUseStageSwitch {
public:
    virtual StageSwitchKeeper* getStageSwitchKeeper() const = 0;
    virtual void initStageSwitchKeeper() = 0;
};

} // namespace al
