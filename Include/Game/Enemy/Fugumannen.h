#pragma once

#include "Game/Enemy/EnemyStateBlowDown.h"
#include "al/MapObj/MapObjActor.h"

class Fugumannen : public al::MapObjActor {
    float mRailMoveSpeed;
    EnemyStateBlowDown* mStateBlowDown;

public:
    Fugumannen(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);
    virtual void attackSensor(al::HitSensor* me, al::HitSensor* other);
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);

    void exeMove();
    void exeMove2();
    void exeBlowDown();
};
