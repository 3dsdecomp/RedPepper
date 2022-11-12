#pragma once

namespace al {

template <typename T>
struct CreateFuncPtr {
    typedef T* (*Type)(const char* name);
};

template <typename T>
struct NameToCreator {
    const char* name;
    T creator;
};

} // namespace al
