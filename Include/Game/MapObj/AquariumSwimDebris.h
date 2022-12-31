#pragma once

#include "al/MapObj/MapObjActor.h"

class AquariumSwimDebris : public al::MapObjActor {
public:
    AquariumSwimDebris(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);

    void exeAppear();
};
