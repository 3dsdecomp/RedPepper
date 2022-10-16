#pragma once

#include "Game/MapObj/MapObjActor.h"

class Togezo : public MapObjActor {
    void* _60;
    void* _64;
    void* _68;

public:
    Togezo(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);

    void exeWander();
};
