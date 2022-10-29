#pragma once

#include "al/MapObj/MapObjActor.h"

class NoteObj : public al::MapObjActor {
    sead::Quatf mStartQuat;
    bool _70;
    bool _71;
    int _74;
    sead::Vector3f _78;
    void* _84;

public:
    NoteObj(const char* name);

    virtual void init(const al::ActorInitInfo& info);
    virtual void initAfterPlacement();
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);
    virtual void control();
};
