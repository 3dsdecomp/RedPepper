#pragma once

#include "al/MapObj/MapObjActor.h"

class TransparentWall : public al::MapObjActor {
public:
    TransparentWall(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);
    virtual void makeActorDead();
};
