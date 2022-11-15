#pragma once

#include "al/MapObj/MapObjActor.h"

class FireBall : public al::MapObjActor {
public:
    FireBall(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);
    virtual void attackSensor(al::HitSensor* me, al::HitSensor* other);
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);

    void exeShot();
};
