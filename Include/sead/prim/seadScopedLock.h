#pragma once

#include <utility>

namespace sead {
template <typename T>
class ScopedLock {
public:
    explicit ScopedLock(T* lock)
        : mLocked(lock)
    {
        mLocked->lock();
    }

    ScopedLock(const ScopedLock& other);
    ScopedLock& operator=(const ScopedLock& other);

    virtual ~ScopedLock()
    {
    }

protected:
    T* mLocked;
};

template <typename T>
class ConditionalScopedLock {
public:
protected:
};

} // namespace sead
