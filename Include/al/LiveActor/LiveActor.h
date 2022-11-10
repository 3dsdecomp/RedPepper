#pragma once

#include "al/Audio/AudioKeeper.h"
#include "al/Collision/Collider.h"
#include "al/Effect/EffectKeeper.h"
#include "al/LiveActor/ActorActionKeeper.h"
#include "al/LiveActor/ActorInitInfo.h"
#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/LiveActor/HitSensorKeeper.h"
#include "al/LiveActor/LiveActorFlag.h"
#include "al/LiveActor/SubActorKeeper.h"
#include "al/Nerve/Nerve.h"
#include "al/Rail/RailKeeper.h"
#include "al/Stage/StageSwitchKeeper.h"
#include "types.h"
#include <sead/math/seadMatrix.h>

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
    ActorActionKeeper* getActorActionKeeper() const { return mActorActionKeeper; }
    Collider* getCollider() const { return mCollider; }
    RailKeeper* getRailKeeper() const { return mRailKeeper; }
    LiveActorFlag& getLiveActorFlag() { return mLiveActorFlag; }

    void initNerveKeeper(NerveKeeper* nk) { mNerveKeeper = nk; }
    void initPoseKeeper(ActorPoseKeeperBase* pPoseKeeper);
    void initRailKeeper(const ActorInitInfo& info);

private:
    const char* mActorName;

protected:
    ActorPoseKeeperBase* mActorPoseKeeper;
    class ActorExecuteInfo* mActorExecuteInfo;
    ActorActionKeeper* mActorActionKeeper;
    Collider* mCollider;
    class CollisionParts* mCollisionParts;
    class ModelKeeper* mModelKeeper;
    NerveKeeper* mNerveKeeper;
    HitSensorKeeper* mHitSensorKeeper;
    EffectKeeper* mEffectKeeper;
    AudioKeeper* mAudioKeeper;
    StageSwitchKeeper* mStageSwitchKeeper;
    RailKeeper* mRailKeeper;
    void* _44;
    class ActorLightKeeper* mActorLightKeeper;
    void* _4C;
    SubActorKeeper* mSubActorKeeper;

private:
    LiveActorFlag mLiveActorFlag;
};

static_assert(sizeof(LiveActor) == 0x60, "");

} // namespace al
