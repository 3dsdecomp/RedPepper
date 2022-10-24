#pragma once

#include "Game/Enemy/EnemyStateBlowDown.h"
#include "Game/Enemy/WalkerStateChase.h"
#include "Game/Enemy/WalkerStateWander.h"
#include "Game/MapObj/MapObjActor.h"

class Togezo : public MapObjActor {
    WalkerStateWander* mWanderState;
    WalkerStateChase* mChaseState;
    EnemyStateBlowDown* mBlowDownState;

public:
    Togezo(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);

    void exeWander();
    void exeTurn();
    void exeSearch();
    void exeChase();
    void exeAttack();
    void exeBlowDown();
};
