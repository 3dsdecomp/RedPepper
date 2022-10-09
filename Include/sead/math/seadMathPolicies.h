#pragma once

#include "sead/math/seadMathBase.h"

namespace sead {
template <typename T>
class Policies {
public:
    typedef BaseVec2<T> Vec2Base;
    typedef BaseVec3<T> Vec3Base;
    typedef BaseVec4<T> Vec4Base;
    typedef BaseQuat<T> QuatBase;
    typedef BaseMtx22<T> Mtx22Base;
    typedef BaseMtx33<T> Mtx33Base;
    typedef BaseMtx34<T> Mtx34Base;
    typedef BaseMtx44<T> Mtx44Base;
};

} // namespace sead
