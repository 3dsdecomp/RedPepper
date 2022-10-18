#pragma once

#include "Game/Enemy/WalkerStateChaseParam.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "al/LiveActor/LiveActor.h"
#include "al/Nerve/ActorStateBase.h"

class WalkerStateChase : public al::ActorStateBase {
    al::LiveActor* const mWalker;
    WalkerStateParam* mWalkParam;
    WalkerStateChaseParam* mRunParam;
    bool _1C;
    void* _20;

public:
    WalkerStateChase(al::LiveActor* host, al::LiveActor* walker, WalkerStateParam* walkParam, WalkerStateChaseParam* runParam, bool);

    void exeStart();
};
