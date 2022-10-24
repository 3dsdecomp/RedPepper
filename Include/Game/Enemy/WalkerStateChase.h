#pragma once

#include "Game/Enemy/WalkerStateChaseParam.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "al/LiveActor/LiveActor.h"
#include "al/Nerve/ActorStateBase.h"

class WalkerStateChase : public al::ActorStateBase {
    sead::Vector3f* mFrontPtr;
    const WalkerStateParam* mWalkParam;
    const WalkerStateChaseParam* mRunParam;
    bool _1C;
    void* _20;

public:
    WalkerStateChase(al::LiveActor* host, sead::Vector3f* frontPtr, const WalkerStateParam* walkParam, const WalkerStateChaseParam* runParam, bool);

    void exeStart();
};
