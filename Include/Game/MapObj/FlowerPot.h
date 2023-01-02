#pragma once

#include "al/MapObj/MapObjActor.h"

class FlowerPot : public al::MapObjActor {
public:
    FlowerPot(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);

    void exeWait();
};
