#include "al/Camera/CameraDashAngleTunerParam.h"

namespace al {

CameraDashAngleTunerParam::CameraDashAngleTunerParam()
    : mAddAngleMax(15)
    , mZoomOutOffsetMax(200)
{
}

void CameraDashAngleTunerParam::init(const ByamlIter* ticket)
{
    ByamlIter h;
    ticket->tryGetIterByKey(&h, "DashAngleTuner");
    h.tryGetFloatByKey(&mAddAngleMax, "AddAngleMax");
    h.tryGetFloatByKey(&mZoomOutOffsetMax, "ZoomOutOffsetMax");
}

} // namespace al
