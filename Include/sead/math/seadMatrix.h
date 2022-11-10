#pragma once

#include "sead/basis/seadTypes.h"
#include "sead/math/seadMathPolicies.h"
#include "sead/math/seadQuat.h"
#include "sead/math/seadVector.h"

namespace sead {
template <typename T>
class Matrix22;

template <typename T>
class Matrix33;

template <typename T>
class Matrix34;

template <typename T>
class Matrix44;

template <typename T>
class Matrix22 : public Policies<T>::Mtx22Base {
private:
    typedef Matrix22<T> Self;

public:
    Matrix22() { }

    Matrix22(const Self& n) {};

    Matrix22(T a00, T a01, T a10, T a11);

    T operator()(s32 i, s32 j) const;
    T& operator()(s32 i, s32 j);
    Self& operator=(const Self& n);

    void makeIdentity();
    void makeZero();

    void setInverse(const Self& n);
    void setInverseTranspose(const Self& n);
    void setMul(const Self& a, const Self& b);
    void setTranspose(const Self& n);
    void transpose();

    static const Matrix22 zero;
    static const Matrix22 ident;
};

template <typename T>
class Matrix33 : public Policies<T>::Mtx33Base {
private:
    typedef Matrix33<T> Self;
    typedef Matrix34<T> Mtx34;

    typedef Vector3<T> Vec3;

public:
    Matrix33() { }

    Matrix33(const Self& n) {};

    Matrix33(T a00, T a01, T a02, T a10, T a11, T a12, T a20, T a21, T a22);

    Matrix33(const Mtx34& mtx34);

    T operator()(s32 i, s32 j) const;
    T& operator()(s32 i, s32 j);
    Self& operator=(const Self& n);

    void makeIdentity();
    void makeZero();

    void setInverse(const Self& n);
    void setInverseTranspose(const Self& n);
    void setMul(const Self& a, const Self& b);
    void setMul(const Mtx34& a, const Self& b);
    void setMul(const Self& a, const Mtx34& b);
    void setTranspose(const Self& n);
    void transpose();

    void fromQuat(const Quat<T>& q);
    void makeR(const Vec3& r);
    void makeRIdx(u32 xr, u32 yr, u32 zr);
    void makeRzxyIdx(u32 xr, u32 yr, u32 zr);
    void makeS(const Vec3& s);
    void makeS(T x, T y, T z);
    void makeSR(const Vec3& s, const Vec3& r);
    void makeSRIdx(const Vec3& s, const Vector3<u32>& r);
    void makeSRzxyIdx(const Vec3& s, const Vector3<u32>& r);
    void toQuat(Quat<T>& q) const;

    static const Matrix33 zero;
    static const Matrix33 ident;
};

template <typename T>
class Matrix34 : public Policies<T>::Mtx34Base {
private:
    typedef Matrix34<T> Self;
    typedef Matrix33<T> Mtx33;
    typedef Matrix44<T> Mtx44;

    typedef Vector3<T> Vec3;
    typedef Vector4<T> Vec4;

public:
    Matrix34() { }

    Matrix34(const Self& n);

    Matrix34(T _00, T _01, T _02, T _03, T _10, T _11, T _12, T _13, T _20, T _21, T _22, T _23);

    Matrix34(const Mtx33& mtx33, const Vec3& t = Vec3::zero);
    Matrix34(const Mtx44& mtx44);

    T operator()(s32 i, s32 j) const;
    T& operator()(s32 i, s32 j);
    Self& operator=(const Self& n);

    void makeIdentity();
    void makeZero();

    void setInverse(const Self& n);
    void setInverse33(const Self& n);
    void setInverseTranspose(const Self& n);
    void setMul(const Self& a, const Self& b);
    void setMul(const Mtx33& a, const Self& b);
    void setTranspose(const Self& n);
    void transpose();

    void fromQuat(const Quat<T>& q);
    void makeQT(const Quat<T>& q, const Vec3& t);
    void makeR(const Vec3& r);
    void makeRIdx(u32 xr, u32 yr, u32 zr);
    void makeRT(const Vec3& r, const Vec3& t);
    void makeRTIdx(const Vector3<u32>& r, const Vec3& t);
    void makeRzxyIdx(u32 xr, u32 yr, u32 zr);
    void makeRzxyTIdx(const Vector3<u32>& r, const Vec3& t);
    void makeS(const Vec3& s);
    void makeS(T x, T y, T z);
    void makeSR(const Vec3& s, const Vec3& r);
    void makeSRIdx(const Vec3& s, const Vector3<u32>& r);
    void makeSRT(const Vec3& s, const Vec3& r, const Vec3& t);
    void makeSRTIdx(const Vec3& s, const Vector3<u32>& r, const Vec3& t);
    void makeSRzxyIdx(const Vec3& s, const Vector3<u32>& r);
    void makeSRzxyTIdx(const Vec3& s, const Vector3<u32>& r, const Vec3& t);
    void makeST(const Vec3& s, const Vec3& t);
    void makeT(const Vec3& t);
    void makeT(T x, T y, T z);
    void toQuat(Quat<T>& q) const;

    void getBase(Vec3& o, s32 axis) const;
    void getRow(Vec4& o, s32 row) const;
    void getTranslation(Vec3& o) const;
    void getRotation(Vec3& o) const;

    void scaleAllElements(T s);
    void scaleBases(T sx, T sy, T sz);
    void setBase(s32 axis, const Vec3& v);
    void setRow(s32 row, const Vec4& v);
    void setTranslation(const Vec3& t);
    void setTranslation(T x, T y, T z);

    static const Matrix34 zero;
    static const Matrix34 ident;
};

template <typename T>
class Matrix44 : public Policies<T>::Mtx44Base {
private:
    typedef Matrix44<T> Self;
    typedef Matrix33<T> Mtx33;
    typedef Matrix34<T> Mtx34;

    typedef Vector3<T> Vec3;
    typedef Vector4<T> Vec4;

public:
    Matrix44() { }

    Matrix44(const Self& n) {};

    Matrix44(T _00, T _01, T _02, T _03, T _10, T _11, T _12, T _13, T _20, T _21, T _22, T _23,
        T _30, T _31, T _32, T _33);

    Matrix44(const Mtx33& mtx33, const Vec3& t = Vec3::zero, const Vec4& vw = Vec4::ew);
    Matrix44(const Mtx34& mtx34, const Vec4& vw = Vec4::ew);

    T operator()(s32 i, s32 j) const;
    T& operator()(s32 i, s32 j);
    Self& operator=(const Self& n);

    void makeIdentity();
    void makeZero();

    void setInverse(const Self& n);
    void setInverseTranspose(const Self& n);
    void setMul(const Self& a, const Self& b);
    void setMul(const Mtx34& a, const Self& b);
    void setMul(const Self& a, const Mtx34& b);
    void setTranspose(const Self& n);
    void transpose();

    void fromQuat(const Quat<T>& q);
    void makeR(const Vec3& r);
    void makeRIdx(u32 xr, u32 yr, u32 zr);
    void makeRzxyIdx(u32 xr, u32 yr, u32 zr);
    void toQuat(Quat<T>& q) const;

    void getCol(Vec4& o, s32 axis) const;
    void getRow(Vec4& o, s32 row) const;

    void scaleAllElements(T s);
    void scaleBases(T sx, T sy, T sz, T sw);
    void setCol(s32 axis, const Vec4& v);
    void setRow(s32 row, const Vec4& v);

    static const Matrix44 zero;
    static const Matrix44 ident;
};

typedef Matrix22<f32> Matrix22f;
typedef Matrix33<f32> Matrix33f;
typedef Matrix34<f32> Matrix34f;
typedef Matrix44<f32> Matrix44f;

typedef Matrix34<f32> Matrixf;

template <>
const Matrix22f Matrix22f::zero;

template <>
const Matrix22f Matrix22f::ident;

template <>
const Matrix33f Matrix33f::zero;

template <>
const Matrix33f Matrix33f::ident;

template <>
const Matrix34f Matrix34f::zero;

template <>
const Matrix34f Matrix34f::ident;

template <>
const Matrix44f Matrix44f::zero;

template <>
const Matrix44f Matrix44f::ident;

template <>
const Matrix22<f64> Matrix22<f64>::zero;

template <>
const Matrix22<f64> Matrix22<f64>::ident;

template <>
const Matrix33<f64> Matrix33<f64>::zero;

template <>
const Matrix33<f64> Matrix33<f64>::ident;

template <>
const Matrix34<f64> Matrix34<f64>::zero;

template <>
const Matrix34<f64> Matrix34<f64>::ident;

template <>
const Matrix44<f64> Matrix44<f64>::zero;

template <>
const Matrix44<f64> Matrix44<f64>::ident;

} // namespace sead

#define SEAD_MATH_MATRIX_H_
#include "sead/math/seadMatrix.hpp"
#undef SEAD_MATH_MATRIX_H_
