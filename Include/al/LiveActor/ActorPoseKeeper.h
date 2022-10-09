#pragma once

#include <sead/math/seadMatrix.h>
#include <sead/math/seadQuat.h>
#include <sead/math/seadVector.h>

namespace al {

class ActorPoseKeeperBase {
    sead::Vector3f mTrans;

public:
    ActorPoseKeeperBase();

    inline const sead::Vector3f& getTrans() const { return mTrans; }
    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Vector3f& getFront() const;
    virtual const sead::Quatf& getQuat() const;
    virtual const sead::Vector3f& getGravity() const;

    inline sead::Vector3f* getTransPtr() { return &mTrans; }
    virtual sead::Vector3f* getRotatePtr();
    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Vector3f* getFrontPtr();
    virtual sead::Quatf* getQuatPtr();
    virtual sead::Vector3f* getGravityPtr();

    virtual void updatePoseRotate(const sead::Vector3f& rot) = 0;
    virtual void updatePoseQuat(const sead::Quatf& quat) = 0;
    virtual void updatePoseMtx(const sead::Matrix34f* mtx) = 0;
    virtual void v1() = 0;
    virtual void calcBaseMtx(sead::Matrix34f* out) = 0;

    static const sead::Vector3f sDefaultGravity;
};

class ActorPoseKeeperTFSV : public ActorPoseKeeperBase {
    sead::Vector3f mFront;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;

public:
    ActorPoseKeeperTFSV();

    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Vector3f& getFront() const;

    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Vector3f* getFrontPtr();

    // virtual void calcBaseMtx(sead::Matrix34f* out);
};

class ActorPoseKeeperTFGSV : public ActorPoseKeeperTFSV {
    sead::Vector3f mGravity;

public:
    ActorPoseKeeperTFGSV();

    virtual const sead::Vector3f& getGravity() const;

    virtual sead::Vector3f* getGravityPtr();

    // virtual void calcBaseMtx(sead::Matrix34f* out);
};

class ActorPoseKeeperTQSV : public ActorPoseKeeperBase {
    sead::Quatf mQuat;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;

public:
    ActorPoseKeeperTQSV();

    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;
    virtual const sead::Quatf& getQuat() const;

    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();
    virtual sead::Quatf* getQuatPtr();

    // virtual void calcBaseMtx(sead::Matrix34f* out);
};

class ActorPoseKeeperTRSV : public ActorPoseKeeperBase {
    sead::Vector3f mRotate;
    sead::Vector3f mScale;
    sead::Vector3f mVelocity;

public:
    ActorPoseKeeperTRSV();

    virtual const sead::Vector3f& getRotate() const;
    virtual const sead::Vector3f& getScale() const;
    virtual const sead::Vector3f& getVelocity() const;

    virtual sead::Vector3f* getRotatePtr();
    virtual sead::Vector3f* getScalePtr();
    virtual sead::Vector3f* getVelocityPtr();

    // virtual void calcBaseMtx(sead::Matrix34f* out);
};

} // namespace al
