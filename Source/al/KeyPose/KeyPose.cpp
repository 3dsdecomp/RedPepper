#pragma once

#include "al/KeyPose/KeyPose.h"
#include "al/Placement/PlacementFunction.h"

namespace al {

NON_MATCHING
// copy
KeyPose::KeyPose()
    : mQuat(sead::Quatf::unit)
    , mTrans(sead::Vector3f::zero)
    , mPlacementInfo(nullptr)
    , _20(0.0)
{
}

void KeyPose::init(const PlacementInfo& info)
{
    tryGetQuat(&mQuat, info);
    tryGetTrans(&mTrans, info);
    mPlacementInfo = new PlacementInfo(info);
}

} // namespace al
