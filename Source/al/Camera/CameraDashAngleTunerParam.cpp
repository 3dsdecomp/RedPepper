#include "al/Camera/CameraDashAngleTunerParam.h"

namespace al {

#ifdef NON_MATCHING
CameraDashAngleTunerParam::CameraDashAngleTunerParam()
    : mAddAngleMax(15)
    , mZoomOutOffsetMax(200)
{
}

// ??? string
void CameraDashAngleTunerParam::init(const ByamlIter* ticket)
{
    ByamlIter h;
    ticket->tryGetIterByKey(&h, "DashAngleTuner");
    h.tryGetFloatByKey(&mAddAngleMax, "AddAngleMax");
    h.tryGetFloatByKey(&mZoomOutOffsetMax, "ZoomOutOffsetMax");
}
#endif

} // namespace al
