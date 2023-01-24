#include "al/AreaObj/AreaShapeCube.h"

namespace al {

AreaShapeCube::AreaShapeCube(bool isCubeBase)
    : mIsCubeBase(isCubeBase)
{
}

NON_MATCHING
// comparison is different
bool AreaShapeCube::isInVolume(const sead::Vector3f& trans) const
{
    sead::Vector3f localPos = sead::Vector3f::zero;
    calcLocalPos(&localPos, trans);
    sead::Vector2f bottomTopYBounds = mIsCubeBase ? sead::Vector2f(0, 1000) : sead::Vector2f(-500, 500);

    return localPos.y > bottomTopYBounds.x && localPos.y < bottomTopYBounds.y
        && localPos.x > -500 && localPos.y < 500
        && localPos.z > -500 && localPos.z < 500;
}

} // namespace al
