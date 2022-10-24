#pragma once

#include "Game/Enemy/EnemyStateBlowDownParam.h"
#include "al/Nerve/ActorStateBase.h"
#include <sead/math/seadVector.h>

class EnemyStateBlowDown : public al::ActorStateBase {
    EnemyStateBlowDownParam* mBlowDownParam;
    sead::Vector3f _14;
    const char* _20;
    void* _24;

public:
    EnemyStateBlowDown(al::LiveActor* host, EnemyStateBlowDownParam* blowDownParam, const char*, int);
};
