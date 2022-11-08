#pragma once

#include "al/AreaObj/AreaInitInfo.h"
#include "al/AreaObj/AreaShape.h"
#include "al/Stage/StageSwitchKeeper.h"

namespace al {

class AreaObj : public IUseStageSwitch {
    const char* mName;
    AreaShape* mAreaShape;
    StageSwitchKeeper* mStageSwitchKeeper;
    u8 _10[0x38];
    bool _48;

public:
    AreaObj(const char* name);

    virtual StageSwitchKeeper* getStageSwitchKeeper() const;
    virtual void initStageSwitchKeeper();
    virtual void init(const AreaInitInfo& info);
    virtual bool isInVolume(const sead::Vector3f& trans) const;
};

} // namespace al
