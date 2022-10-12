#include "al/Camera/CameraRotatorParam.h"

namespace al {

#ifdef NON_MATCHING
CameraRotatorParam::CameraRotatorParam()
    : mAngleMax(30)
{
}
#endif

void CameraRotatorParam::init(const ByamlIter* ticket)
{
    ByamlIter h;
    ticket->tryGetIterByKey(&h, "Rotator");
    h.tryGetFloatByKey(&mAngleMax, "AngleMax");
}

} // namespace al
