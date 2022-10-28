#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/LiveActor/LiveActorKit.h"

namespace al {

#ifdef NON_MATCHING
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
    , _40(nullptr)
    , _44(nullptr)
    , mActorLightKeeper(nullptr)
    , _4C(nullptr)
    , mSubActorKeeper(nullptr)
    , mLiveActorFlag(LiveActorFlag())
{
    al::getLiveActorKit()->getAllActors()->registerActor(this);
}
#endif

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

void LiveActor::initStageSwitchKeeper()
{
    mStageSwitchKeeper = new StageSwitchKeeper();
}

void LiveActor::control() { }

void LiveActor::initPoseKeeper(ActorPoseKeeperBase* pPoseKeeper)
{
    mActorPoseKeeper = pPoseKeeper;
}

} // namespace al
