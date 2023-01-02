#pragma once

#include "al/MapObj/MapObjActor.h"

class PeachRope : public al::MapObjActor {
public:
    PeachRope(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);
    virtual void kill();
};
