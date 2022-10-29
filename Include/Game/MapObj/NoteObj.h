#pragma once

#include "Game/MapObj/NoteObjGenerator.h"

class NoteObj : public al::MapObjActor {
    sead::Quatf mStartQuat;
    bool _70;
    bool _71;
    int _74;
    sead::Vector3f _78;
    NoteObjGenerator* mGenerator;

public:
    NoteObj(const char* name);
    NoteObj(NoteObjGenerator* generator);

    virtual void init(const al::ActorInitInfo& info);
    virtual void initAfterPlacement();
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);
    virtual void control();
};
