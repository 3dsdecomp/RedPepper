#include "al/LiveActor/LiveActor.h"
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
    , _38(nullptr)
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

void LiveActor::attackSensor(HitSensor* me, HitSensor* other) { }
bool LiveActor::receiveMsg(u32 msg, HitSensor* other, HitSensor* me) { return false; }

void LiveActor::draw() { }

EffectKeeper* LiveActor::getEffectKeeper() const { return mEffectKeeper; }
void* LiveActor::getUnknown() const { return _38; }

void LiveActor::initStageSwitchKeeper()
{
    mStageSwitchKeeper = new StageSwitchKeeper();
}

void LiveActor::control() { }

} // namespace al
