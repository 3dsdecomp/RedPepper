#pragma once

#include "Game/Player/Player.h"
#include "Game/Player/PlayerActorInitInfo.h"
#include "Game/Player/PlayerAnimator.h"
#include "al/LiveActor/ActorInitInfo.h"
#include "al/MapObj/MapObjActor.h"
#include <sead/math/seadVector.h>

class PlayerActor : public al::MapObjActor {
    void* _60;
    void* _64;
    void* _68;
    void* _6C;
    void* _70;
    Player* mPlayer;
    void* _78;
    PlayerAnimator* mPlayerAnimator;
    void* _80;
    void* _84;
    void* _88;
    void* _8C;
    void* _90;
    void* _94;
    void* _98;
    void* _9C;
    void* _A0;
    PlayerModelHolder* mModelHolder;
    void* _A8;
    void* _AC;
    void* _B0;
    void* _B4;
    void* _B8;
    void* _BC;
    void* _C0;
    void* _C4;
    void* _C8;
    void* _CC;
    void* _D0;
    void* _D4;
    void* _D8;
    void* _Dc;
    void* _E0;
    void* _E4;
    void* _E8;
    void* _EC;
    void* _F0;
    void* _F4;
    void* _F8;
    void* _FC;
    void* _100;
    void* _104;
    void* _108;
    void* _10C;
    void* _110;
    void* _114;
    void* _118;
    void* _11C;
    void* _120;
    void* _124;
    void* _128;
    void* _12C;
    void* _130;
    void* _134;
    void* _138;
    void* _13C;
    void* _140;
    void* _144;
    void* _148;
    void* _14C;
    void* _150;
    void* _154;
    void* _158;

public:
    PlayerActor(const char* name);

    virtual void movement();
    virtual void attackSensor(al::HitSensor* me, al::HitSensor* other);
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);
    virtual void control();
    virtual void updateCollider();

    virtual void initSpecial(const al::ActorInitInfo& info, const PlayerActorInitInfo& playerInfo);
    virtual void v_64();
    virtual void v_68();
    virtual void v_6c();

    PlayerProperty* getProperty();
};
