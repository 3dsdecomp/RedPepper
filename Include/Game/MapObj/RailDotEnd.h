#pragma once

#include "al/MapObj/MapObjActor.h"

class RailDotEnd : public al::MapObjActor {
public:
    RailDotEnd(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);

    void exeWait();
};
