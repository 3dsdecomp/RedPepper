#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/ActorInitInfo.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/LiveActor/LiveActorKit.h"
#include "al/Rail/RailKeeper.h"

namespace al {

#pragma O3
LiveActor::LiveActor(const char* name)
    : mActorName(name)
    , mActorPoseKeeper(nullptr)
    , mActorExecuteInfo(nullptr)
    , mActorActionKeeper(nullptr)
    , mCollider(nullptr)
    , mCollisionParts(nullptr)
    , mModelKeeper(nullptr)
    , mNerveKeeper(nullptr)
    , mHitSensorKeeper(nullptr)
    , mEffectKeeper(nullptr)
    , mAudioKeeper(nullptr)
    , mStageSwitchKeeper(nullptr)
    , mRailKeeper(nullptr)
    , mShadowKeeper(nullptr)
    , mActorLightKeeper(nullptr)
    , _4C(nullptr)
    , mSubActorKeeper(nullptr)
{
    getLiveActorKit()->getAllActors()->registerActor(this);
}

NerveKeeper* LiveActor::getNerveKeeper() const
{
    return mNerveKeeper;
}

void LiveActor::init(const ActorInitInfo& info) { }
void LiveActor::initAfterPlacement() { }

void LiveActor::appear() { makeActorAppeared(); }
void LiveActor::kill() { makeActorDead(); }

void LiveActor::calcAnim()
{
    if (!mLiveActorFlag.isDead && (!mLiveActorFlag.isClipped || mLiveActorFlag.flag4)) {
        if (mActorPoseKeeper)
            alLiveActorFunction::calcAnimDirect(this);
        if (getAudioKeeper())
            getAudioKeeper()->update();
    }
}

void LiveActor::attackSensor(HitSensor* me, HitSensor* other) { }
bool LiveActor::receiveMsg(u32 msg, HitSensor* other, HitSensor* me) { return false; }

void LiveActor::draw() { }

EffectKeeper* LiveActor::getEffectKeeper() const { return mEffectKeeper; }
AudioKeeper* LiveActor::getAudioKeeper() const { return mAudioKeeper; }
StageSwitchKeeper* LiveActor::getStageSwitchKeeper() const { return mStageSwitchKeeper; }

void LiveActor::initStageSwitchKeeper() { mStageSwitchKeeper = new StageSwitchKeeper(); }

void LiveActor::control() { }

void LiveActor::initNerveKeeper(NerveKeeper* nk) { mNerveKeeper = nk; }
void LiveActor::initPoseKeeper(ActorPoseKeeperBase* pPoseKeeper) { mActorPoseKeeper = pPoseKeeper; }
void LiveActor::initRailKeeper(const ActorInitInfo& info) { mRailKeeper = al::tryCreateRailKeeper(al::getPlacementInfo(info)); }

} // namespace al
