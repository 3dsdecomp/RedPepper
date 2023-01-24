#include "al/Camera/CameraParamVision.h"

namespace al {

CameraParamVision::CameraParamVision()
{
    mNearClipDistance = -1.0;
    mFarClipDistance = -1.0;
    mFovyDegree = 45.0;
    mStereovisionDistance = 200.0;
    mStereovisionDepth = 1.0;
}

bool CameraParamVision::init(const ByamlIter* ticket)
{
    ByamlIter h;
    if (ticket->tryGetIterByKey(&h, "VisionParam")) {
        h.tryGetFloatByKey(&mFovyDegree, "FovyDegree");
        h.tryGetFloatByKey(&mStereovisionDistance, "StereovisionDistance");
        h.tryGetFloatByKey(&mStereovisionDepth, "StereovisionDepth");
        h.tryGetFloatByKey(&mNearClipDistance, "NearClipDistacne");
        h.tryGetFloatByKey(&mFarClipDistance, "FarClipDistance");
        return true;
    }
    return false;
}

} // namespace al
