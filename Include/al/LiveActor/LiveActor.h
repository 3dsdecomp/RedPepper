#pragma once

#include "al/Audio/AudioKeeper.h"
#include "al/Collision/Collider.h"
#include "al/Collision/CollisionParts.h"
#include "al/Effect/EffectKeeper.h"
#include "al/LiveActor/ActorActionKeeper.h"
#include "al/LiveActor/ActorExecuteInfo.h"
#include "al/LiveActor/ActorInitInfo.h"
#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/LiveActor/HitSensorKeeper.h"
#include "al/LiveActor/LiveActorFlag.h"
#include "al/LiveActor/SubActorKeeper.h"
#include "al/Model/ModelKeeper.h"
#include "al/Nerve/Nerve.h"
#include "al/Rail/RailKeeper.h"
#include "al/Shadow/ShadowKeeper.h"
#include "al/Stage/StageSwitchKeeper.h"
#include "types.h"
#include <sead/math/seadMatrix.h>

class alActorPoseFunction;
class alLiveActorFunction;

namespace al {

class LiveActor : public IUseNerve, public IUseEffectKeeper, public IUseAudioKeeper, public IUseStageSwitch {
public:
    LiveActor(const char* name);

    virtual NerveKeeper* getNerveKeeper() const;

    virtual void init(const ActorInitInfo& info);
    virtual void initAfterPlacement();
    virtual void appear();
    virtual void makeActorAppeared();
    virtual void kill();
    virtual void makeActorDead();
    virtual void movement();
    virtual void calcAnim();
    virtual void draw();
    virtual void startClipped();
    virtual void endClipped();
    virtual void attackSensor(HitSensor* me, HitSensor* other);
    virtual bool receiveMsg(u32 msg, HitSensor* other, HitSensor* me);
    virtual const sead::Matrix34f* getBaseMtx() const;
    virtual EffectKeeper* getEffectKeeper() const;
    virtual AudioKeeper* getAudioKeeper() const;
    virtual StageSwitchKeeper* getStageSwitchKeeper() const;
    virtual void initStageSwitchKeeper();
    virtual void control();
    virtual void calcAndSetBaseMtx();
    virtual void updateCollider();
    virtual void v22();
    virtual void v23();

    const char* getName() const { return mActorName; }
    ActorPoseKeeperBase* getActorPoseKeeper() const { return mActorPoseKeeper; }
    ActorExecuteInfo* getActorExecuteInfo() const { return mActorExecuteInfo; }
    ActorActionKeeper* getActorActionKeeper() const { return mActorActionKeeper; }
    Collider* getCollider() const { return mCollider; }
    ModelKeeper* getModelKeeper() const { return mModelKeeper; }
    HitSensorKeeper* getHitSensorKeeper() const { return mHitSensorKeeper; }
    RailKeeper* getRailKeeper() const { return mRailKeeper; }
    ShadowKeeper* getShadowKeeper() const { return mShadowKeeper; }
    LiveActorFlag& getLiveActorFlag() { return mLiveActorFlag; }
    const LiveActorFlag& getLiveActorFlag() const { return mLiveActorFlag; }

    void initPoseKeeper(ActorPoseKeeperBase* pPoseKeeper);
    void initCollider(float radius, float yOffset, u32);
    void initNerveKeeper(NerveKeeper* nk);
    void initRailKeeper(const ActorInitInfo& info);

private:
    const char* mActorName;

protected:
    ActorPoseKeeperBase* mActorPoseKeeper;
    ActorExecuteInfo* mActorExecuteInfo;
    ActorActionKeeper* mActorActionKeeper;
    Collider* mCollider;
    CollisionParts* mCollisionParts;
    ModelKeeper* mModelKeeper;
    NerveKeeper* mNerveKeeper;
    HitSensorKeeper* mHitSensorKeeper;
    EffectKeeper* mEffectKeeper;
    AudioKeeper* mAudioKeeper;
    StageSwitchKeeper* mStageSwitchKeeper;
    RailKeeper* mRailKeeper;
    ShadowKeeper* mShadowKeeper;
    class ActorLightKeeper* mActorLightKeeper;
    void* _4C;
    SubActorKeeper* mSubActorKeeper;

private:
    LiveActorFlag mLiveActorFlag;

    friend class ::alActorPoseFunction;
    friend class ::alLiveActorFunction;
};

static_assert(sizeof(LiveActor) == 0x60, "");

} // namespace al
