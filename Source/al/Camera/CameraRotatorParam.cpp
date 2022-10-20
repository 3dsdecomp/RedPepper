#include "al/Camera/CameraRotatorParam.h"

namespace al {

CameraRotatorParam::CameraRotatorParam()
    : mAngleMax(30)
{
}

void CameraRotatorParam::init(const ByamlIter* ticket)
{
    ByamlIter h;
    ticket->tryGetIterByKey(&h, "Rotator");
    h.tryGetFloatByKey(&mAngleMax, "AngleMax");
}

} // namespace al
