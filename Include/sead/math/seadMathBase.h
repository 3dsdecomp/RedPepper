#pragma once

namespace sead {
template <typename T>
struct BaseVec2 {
    T x;
    T y;
};

template <typename T>
struct BaseVec3 {
    T x;
    T y;
    T z;
};

template <typename T>
struct BaseVec4 {
    T x;
    T y;
    T z;
    T w;
};

template <typename T>
struct BaseQuat {
    T x;
    T y;
    T z;
    T w;
};

template <typename T>
struct BaseMtx22 {
    T m[2][2];
};

template <typename T>
struct BaseMtx33 {
    T m[3][3];
};

template <typename T>
struct BaseMtx34 {
    T m[3][4];
};

template <typename T>
struct BaseMtx44 {
    T m[4][4];
};

} // namespace sead
