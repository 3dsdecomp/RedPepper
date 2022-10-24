#pragma once

#include "Game/Enemy/WalkerStateParam.h"
#include "Game/Enemy/WalkerStateWanderParam.h"
#include "al/Nerve/ActorStateBase.h"

class WalkerStateWander : public al::ActorStateBase {
    sead::Vector3f* mFrontPtr;
    void* _14;
    const WalkerStateParam* mWalkerParam;
    const WalkerStateWanderParam* mWanderParam;

public:
    WalkerStateWander(al::LiveActor* host, sead::Vector3f* frontPtr, const WalkerStateParam* walkerParam, const WalkerStateWanderParam* wanderParam);
};
