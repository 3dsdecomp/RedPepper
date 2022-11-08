#include "al/AreaObj/AreaShape.h"

namespace al {

#pragma O3
AreaShape::AreaShape()
    : mBaseMtxPtr(nullptr)
    , mScale(sead::Vector3f(1, 1, 1))
{
}

} // namespace al
