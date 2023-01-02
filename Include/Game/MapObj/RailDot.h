#pragma once

#include "al/MapObj/MapObjActor.h"

class RailDot : public al::MapObjActor {
public:
    RailDot(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);

    void exeWait();
};
