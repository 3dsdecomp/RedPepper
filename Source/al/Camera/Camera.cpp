#include "al/Camera/Camera.h"
#include "al/Camera/CameraDashAngleTunerParam.h"
#include "al/Camera/CameraParamVision.h"
#include "al/Camera/CameraRotatorParam.h"

namespace al {

NON_MATCHING // vtable
Camera::Camera(const char* name)
    : mName(name)
    , _8(sead::Vector3f::zero)
    , mPos(sead::Vector3f(0, 500, 500))
    , mTarget(sead::Vector3f::ey)
    , _2C(sead::Vector3f::ey)
    , mInterpoleFrame(30)
    , mVisionParam(nullptr)
    , mDashAngleTunerParam(nullptr)
    , mUnknownParam(nullptr)
    , mRotatorParam(nullptr)
{
    mDashAngleTunerParam = new CameraDashAngleTunerParam;
    mUnknownParam = new CameraUnknownParam;
    mRotatorParam = new CameraRotatorParam;
}

void Camera::load(const al::ByamlIter* ticket)
{
    ticket->tryGetIntByKey(&mInterpoleFrame, "InterpoleFrame");
    if (mInterpoleFrame < 0)
        mInterpoleFrame = 30;
    if (ticket->isExistKey("VisionParam")) {
        mVisionParam = new CameraParamVision;
        mVisionParam->init(ticket);
    }
    mDashAngleTunerParam->init(ticket);
    mRotatorParam->init(ticket);
}

void Camera::v1()
{
}
void Camera::v2() { }
void Camera::v3() { }
void Camera::v4() { }
void Camera::v5() { }
void Camera::calc() { }
void Camera::v7() { }

} // namespace al
