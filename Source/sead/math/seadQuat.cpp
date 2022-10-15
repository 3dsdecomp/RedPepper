#include <sead/math/seadQuat.h>

namespace sead {

template <>
const Quat<double> Quat<double>::unit(0, 0, 0, 1);

template <>
const Quatf Quat<float>::unit(0.0f, 0.0f, 0.0f, 1.0f);

} // namespace sead
