#pragma once

#include "sead/math/seadMathPolicies.h"

namespace sead {
template <typename T>
class Vector2CalcCommon {
public:
    typedef typename Policies<T>::Vec2Base Base;

public:
    static void add(Base& o, const Base& a, const Base& b);
    static void sub(Base& o, const Base& a, const Base& b);

    static void set(Base& o, const Base& v);
    static void set(Base& v, T x, T y);
};

template <typename T>
class Vector3CalcCommon {
public:
    typedef typename Policies<T>::Vec3Base Base;
    typedef typename Policies<T>::Mtx33Base Mtx33;
    typedef typename Policies<T>::Mtx34Base Mtx34;

    static void add(Base& o, const Base& a, const Base& b);
    static void sub(Base& o, const Base& a, const Base& b);
    static void mul(Base& o, const Mtx33& m, const Base& a);
    /// Apply a transformation `m` (rotation + translation) to the vector `a`.
    static void mul(Base& o, const Mtx34& m, const Base& a);

    static void cross(Base& o, const Base& a, const Base& b);
    static T dot(const Base& a, const Base& b);
    static T squaredLength(const Base& v);
    static T length(const Base& v);
    static bool equals(const Base& lhs, const Base& rhs, T epsilon);
    static void multScalar(Base& o, const Base& v, T t);
    static void multScalarAdd(Base& o, T t, const Base& a, const Base& b);
    static T normalize(Base& v);
    static void set(Base& o, const Base& v);
    static void set(Base& v, T x, T y, T z);
};

template <typename T>
class Vector4CalcCommon {
public:
    typedef typename Policies<T>::Vec4Base Base;

public:
    static void set(Base& o, const Base& v);
    static void set(Base& v, T x, T y, T z, T w);
};

} // namespace sead

#define SEAD_MATH_VECTOR_CALC_COMMON_H_
#include "sead/math/seadVectorCalcCommon.hpp"
#undef SEAD_MATH_VECTOR_CALC_COMMON_H_
