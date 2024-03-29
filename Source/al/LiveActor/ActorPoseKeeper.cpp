#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

ActorPoseKeeperBase::ActorPoseKeeperBase()
    : mTrans(sead::Vector3f(0, 0, 0))
{
}

const sead::Vector3f split(al::ActorPoseKeeperBase::sDefaultGravity)(0, -1, 0);

const sead::Vector3f& ActorPoseKeeperBase::getRotate() const { return sead::Vector3f::zero; }
const sead::Vector3f& ActorPoseKeeperBase::getScale() const { return sead::Vector3f::ones; }
const sead::Vector3f& ActorPoseKeeperBase::getVelocity() const { return sead::Vector3f::zero; }
const sead::Vector3f& ActorPoseKeeperBase::getFront() const { return sead::Vector3f::ez; }
const sead::Quatf& ActorPoseKeeperBase::getQuat() const { return sead::Quatf::unit; }
const sead::Vector3f& ActorPoseKeeperBase::getGravity() const { return sDefaultGravity; }

sead::Vector3f* ActorPoseKeeperBase::getRotatePtr() { return nullptr; }
sead::Vector3f* ActorPoseKeeperBase::getScalePtr() { return nullptr; }
sead::Vector3f* ActorPoseKeeperBase::getVelocityPtr() { return nullptr; }
sead::Vector3f* ActorPoseKeeperBase::getFrontPtr() { return nullptr; }
sead::Quatf* ActorPoseKeeperBase::getQuatPtr() { return nullptr; }
sead::Vector3f* ActorPoseKeeperBase::getGravityPtr() { return nullptr; }

#pragma no_inline
ActorPoseKeeperTFSV::ActorPoseKeeperTFSV()
    : ActorPoseKeeperBase()
    , mFront(sead::Vector3f::ez)
    , mScale(sead::Vector3f(1, 1, 1))
    , mVelocity(sead::Vector3f(0, 0, 0))
{
}

const sead::Vector3f& ActorPoseKeeperTFSV::getScale() const { return mScale; }
const sead::Vector3f& ActorPoseKeeperTFSV::getVelocity() const { return mVelocity; }
const sead::Vector3f& ActorPoseKeeperTFSV::getFront() const { return mFront; }
sead::Vector3f* ActorPoseKeeperTFSV::getScalePtr() { return &mScale; }
sead::Vector3f* ActorPoseKeeperTFSV::getVelocityPtr() { return &mVelocity; }
sead::Vector3f* ActorPoseKeeperTFSV::getFrontPtr() { return &mFront; }

#pragma no_inline
ActorPoseKeeperTFGSV::ActorPoseKeeperTFGSV()
    : ActorPoseKeeperTFSV()
    , mGravity(sead::Vector3f(0, -1, 0))
{
}

const sead::Vector3f& ActorPoseKeeperTFGSV::getGravity() const { return mGravity; }
sead::Vector3f* ActorPoseKeeperTFGSV::getGravityPtr() { return &mGravity; }

#pragma no_inline
ActorPoseKeeperTQSV::ActorPoseKeeperTQSV()
    : ActorPoseKeeperBase()
    , mQuat(sead::Quatf::unit)
    , mScale(sead::Vector3f(1, 1, 1))
    , mVelocity(sead::Vector3f(0, 0, 0))
{
}

const sead::Vector3f& ActorPoseKeeperTQSV::getScale() const { return mScale; }
const sead::Vector3f& ActorPoseKeeperTQSV::getVelocity() const { return mVelocity; }
const sead::Quatf& ActorPoseKeeperTQSV::getQuat() const { return mQuat; }
sead::Vector3f* ActorPoseKeeperTQSV::getScalePtr() { return &mScale; }
sead::Vector3f* ActorPoseKeeperTQSV::getVelocityPtr() { return &mVelocity; }
sead::Quatf* ActorPoseKeeperTQSV::getQuatPtr() { return &mQuat; }

#pragma no_inline
ActorPoseKeeperTRSV::ActorPoseKeeperTRSV()
    : ActorPoseKeeperBase()
    , mRotate(sead::Vector3f(0, 0, 0))
    , mScale(sead::Vector3f(1, 1, 1))
    , mVelocity(sead::Vector3f(0, 0, 0))
{
}

void initActorPoseTFSV(LiveActor* actor) { actor->initPoseKeeper(new ActorPoseKeeperTFSV()); }
void initActorPoseTFGSV(LiveActor* actor) { actor->initPoseKeeper(new ActorPoseKeeperTFGSV()); }
void initActorPoseTQSV(LiveActor* actor) { actor->initPoseKeeper(new ActorPoseKeeperTQSV()); }
void initActorPoseTRSV(LiveActor* actor) { actor->initPoseKeeper(new ActorPoseKeeperTRSV()); }

const sead::Vector3f& ActorPoseKeeperTRSV::getRotate() const { return mRotate; }
const sead::Vector3f& ActorPoseKeeperTRSV::getScale() const { return mScale; }
const sead::Vector3f& ActorPoseKeeperTRSV::getVelocity() const { return mVelocity; }
sead::Vector3f* ActorPoseKeeperTRSV::getRotatePtr() { return &mRotate; }
sead::Vector3f* ActorPoseKeeperTRSV::getScalePtr() { return &mScale; }
sead::Vector3f* ActorPoseKeeperTRSV::getVelocityPtr() { return &mVelocity; }

void setTrans(LiveActor* actor, const sead::Vector3f& trans) { *actor->getActorPoseKeeper()->getTransPtr() = trans; }
void setRotate(LiveActor* actor, const sead::Vector3f& rotate) { *actor->getActorPoseKeeper()->getRotatePtr() = rotate; }
void setScale(LiveActor* actor, const sead::Vector3f& scale) { *actor->getActorPoseKeeper()->getScalePtr() = scale; }
void setVelocity(LiveActor* actor, const sead::Vector3f& velocity) { *actor->getActorPoseKeeper()->getVelocityPtr() = velocity; }
void setVelocityZero(LiveActor* actor)
{
    float zero = 0;
    sead::Vector3f* velocity = actor->getActorPoseKeeper()->getVelocityPtr();
    velocity->x = zero;
    velocity->y = zero;
    velocity->z = zero;
}
void setFront(LiveActor* actor, const sead::Vector3f& front) { *actor->getActorPoseKeeper()->getFrontPtr() = front; }
void setQuat(LiveActor* actor, const sead::Quatf& quat) { *actor->getActorPoseKeeper()->getQuatPtr() = quat; }
void setGravity(LiveActor* actor, const sead::Vector3f& gravity) { *actor->getActorPoseKeeper()->getGravityPtr() = gravity; }

const sead::Vector3f& getTrans(const LiveActor* actor) { return actor->getActorPoseKeeper()->getTrans(); }
const sead::Vector3f& getRotate(const LiveActor* actor) { return actor->getActorPoseKeeper()->getRotate(); }
const sead::Vector3f& getScale(const LiveActor* actor) { return actor->getActorPoseKeeper()->getScale(); }
const sead::Vector3f& getVelocity(const LiveActor* actor) { return actor->getActorPoseKeeper()->getVelocity(); }
const sead::Vector3f& getFront(const LiveActor* actor) { return actor->getActorPoseKeeper()->getFront(); }
const sead::Quatf& getQuat(const LiveActor* actor) { return actor->getActorPoseKeeper()->getQuat(); }
const sead::Vector3f& getGravity(const LiveActor* actor) { return actor->getActorPoseKeeper()->getGravity(); }

sead::Vector3f* getTransPtr(LiveActor* actor) { return actor->getActorPoseKeeper()->getTransPtr(); }
sead::Vector3f* getRotatePtr(LiveActor* actor) { return actor->getActorPoseKeeper()->getRotatePtr(); }
sead::Vector3f* getScalePtr(LiveActor* actor) { return actor->getActorPoseKeeper()->getScalePtr(); }
sead::Vector3f* getVelocityPtr(LiveActor* actor) { return actor->getActorPoseKeeper()->getVelocityPtr(); }
sead::Vector3f* getFrontPtr(LiveActor* actor) { return actor->getActorPoseKeeper()->getFrontPtr(); }
sead::Quatf* getQuatPtr(LiveActor* actor) { return actor->getActorPoseKeeper()->getQuatPtr(); }
sead::Vector3f* getGravityPtr(LiveActor* actor) { return actor->getActorPoseKeeper()->getGravityPtr(); }

void updatePoseRotate(LiveActor* actor, const sead::Vector3f& rotate) { actor->getActorPoseKeeper()->updatePoseRotate(rotate); }
void updatePoseQuat(LiveActor* actor, const sead::Quatf& quat) { actor->getActorPoseKeeper()->updatePoseQuat(quat); }
void updatePoseMtx(LiveActor* actor, const sead::Matrix34f* mtx) { actor->getActorPoseKeeper()->updatePoseMtx(mtx); }

void copyPose(LiveActor* to, const LiveActor* from) { to->getActorPoseKeeper()->copyPose(from->getActorPoseKeeper()); }

void calcSideDir(sead::Vector3f* out, const LiveActor* actor)
{
    sead::Matrix34f baseMtx;
    actor->getActorPoseKeeper()->calcBaseMtx(&baseMtx);
    out->x = baseMtx.m[0][0];
    out->y = baseMtx.m[1][0];
    out->z = baseMtx.m[2][0];
}

void calcUpDir(sead::Vector3f* out, const LiveActor* actor)
{
    sead::Matrix34f baseMtx;
    actor->getActorPoseKeeper()->calcBaseMtx(&baseMtx);
    out->x = baseMtx.m[0][1];
    out->y = baseMtx.m[1][1];
    out->z = baseMtx.m[2][1];
}

void calcFrontDir(sead::Vector3f* out, const LiveActor* actor)
{
    sead::Matrix34f baseMtx;
    actor->getActorPoseKeeper()->calcBaseMtx(&baseMtx);
    out->x = baseMtx.m[0][2];
    out->y = baseMtx.m[1][2];
    out->z = baseMtx.m[2][2];
}

} // namespace al
