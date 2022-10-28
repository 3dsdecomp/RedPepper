#pragma once

#include "al/LiveActor/ActorInitInfo.h"

namespace al {

class ISceneObj {
public:
    virtual const char* getSceneObjName() const = 0;
    virtual void initAfterPlacementSceneObj(const ActorInitInfo& info) { }
    virtual void initSceneObj() { }
};

} // namespace al
