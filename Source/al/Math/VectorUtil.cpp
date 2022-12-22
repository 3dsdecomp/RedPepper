#include "al/Math/VectorUtil.h"

namespace al {

void lerpVec(sead::Vector3f* out, const sead::Vector3f& from, const sead::Vector3f& to, float amount)
{
    out->x = from.x + (to.x - from.x) * amount;
    out->y = from.y + (to.y - from.y) * amount;
    out->z = from.z + (to.z - from.z) * amount;
}

} // namespace al
