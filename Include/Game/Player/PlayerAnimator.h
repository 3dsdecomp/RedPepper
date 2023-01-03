#pragma once

#include "Game/Player/PlayerAnimFrameCtrl.h"
#include "Game/Player/PlayerModelHolder.h"
#include "al/LiveActor/LiveActor.h"
#include <sead/prim/seadSafeString.h>

class IUsePlayerAnimator {
public:
    virtual void v_0() = 0;
    virtual void v_4() = 0;
    virtual void v_8() = 0;
    virtual void v_C() = 0;
    virtual void v_10() = 0;
    virtual bool isAnimEnd() const = 0;
    virtual bool isAnim(const sead::SafeString& name) = 0;
    virtual float getAnimFrame() const = 0;
    virtual void v_20() = 0;
    virtual void v_24() = 0;
    virtual void v_28() = 0;
    virtual void v_2C() = 0;
    virtual void v_30() = 0;
    virtual void v_34() = 0;
    virtual void v_38() = 0;
    virtual void v_3C() = 0;
    virtual void v_40() = 0;
    virtual void v_44() = 0;
    virtual void v_48() = 0;
    virtual void v_4C() = 0;
};

class PlayerAnimator : public IUsePlayerAnimator {
    al::LiveActor* mHost;
    PlayerModelHolder* mModelHolder;
    bool _C;
    bool _D;
    PlayerAnimFrameCtrl* mAnimFrameCtrl;
    bool _14;
    bool _15;

public:
    PlayerAnimator(al::LiveActor* host, PlayerModelHolder* modelHolder);

    // virtual void v_0();
    // virtual void v_4();
    // virtual void v_8();
    // virtual void v_C();
    // virtual void v_10();
    // virtual bool isAnimEnd() const;
    // virtual bool isAnim(const sead::SafeString& name);
    virtual float getAnimFrame() const;
    // virtual void v_20();
    // virtual void v_24();
    // virtual void v_28();
    // virtual void v_2C();
    // virtual void v_30();
    // virtual void v_34();
    // virtual void v_38();
    // virtual void v_3C();
    // virtual void v_40();
    // virtual void v_44();
    // virtual void v_48();
    // virtual void v_4C();
};
