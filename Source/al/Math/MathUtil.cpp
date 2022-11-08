#include "al/Math/MathUtil.h"

namespace al {

bool isNearZero(float value, float range)
{
    return (value < 0 ? -value : value) < range;
}

} // namespace al
