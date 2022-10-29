#pragma once

#include "al/LiveActor/ActionAnimCtrl.h"

namespace al {

class ActorActionKeeper {
    void* _0;
    void* _4;
    ActionAnimCtrl* mActionAnimCtrl;

public:
    void tryStartActionNoAnim(const char* name);
};

} // namespace al
