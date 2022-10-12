#include "al/Camera/CameraParamVision.h"

namespace al {

#ifdef NON_MATCHING
CameraParamVision::CameraParamVision()
    : mNearClipDistance(-1)
    , mFarClipDistance(-1)
    , mFovyDegree(45)
    , mStereovisionDistance(200)
    , mStereovisionDepth(1.0)
{
}
#endif

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
