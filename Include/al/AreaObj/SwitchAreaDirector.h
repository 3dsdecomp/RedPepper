#pragma once

#include "al/AreaObj/SwitchKeepOnAreaGroup.h"
#include "al/AreaObj/SwitchOnAreaGroup.h"
#include "al/LiveActor/LiveActor.h"
#include "al/Scene/ISceneObj.h"

namespace al {

class SwitchAreaDirector : public LiveActor, public ISceneObj {
    SwitchOnAreaGroup* mSwitchOnAreaGroup;
    SwitchKeepOnAreaGroup* mSwitchKeepOnAreaGroup;

public:
    SwitchAreaDirector();

    virtual void movement();
    virtual void unk1();
};

} // namespace al
