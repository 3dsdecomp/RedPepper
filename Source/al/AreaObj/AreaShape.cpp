#include "al/AreaObj/AreaShape.h"

namespace al {

#pragma O3
AreaShape::AreaShape()
    : mBaseMtxPtr(nullptr)
    , mScale(sead::Vector3f(1, 1, 1))
{
}

/* TODO: Move this to header */
void AreaShape::setScale(const sead::Vector3f& scale)
{ 
    mScale = scale; 
}

} // namespace al
