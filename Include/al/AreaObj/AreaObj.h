#pragma once

#include "al/AreaObj/AreaInitInfo.h"
#include "al/AreaObj/AreaShape.h"
#include "al/Stage/StageSwitchKeeper.h"
#include <sead/math/seadMatrix.h>

namespace al {

class AreaObj : public IUseStageSwitch {
    const char* mName;
    AreaShape* mAreaShape;
    StageSwitchKeeper* mStageSwitchKeeper;
    sead::Matrix34f _10;
    void* _40;
    int _44;
    bool _48;

public:
    AreaObj(const char* name);

    virtual StageSwitchKeeper* getStageSwitchKeeper() const;
    virtual void initStageSwitchKeeper();
    virtual void init(const AreaInitInfo& info);
    virtual bool isInVolume(const sead::Vector3f& trans) const;
};

} // namespace al
