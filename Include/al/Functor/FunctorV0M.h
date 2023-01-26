#pragma once

#include "al/Functor/FunctorBase.h"

namespace al {

template <typename T, typename F>
class FunctorV0M : public FunctorBase {
    T mParent;
    F mFuncPtr;

public:
    FunctorV0M(T parent, F funcPtr)
        : mFuncPtr(funcPtr)
        , mParent(parent)
    {
    }

    virtual void operator()() const { (mParent->*mFuncPtr)(); }
    virtual FunctorV0M* clone() const { return new FunctorV0M<T, F>(mParent, mFuncPtr); }
};

} // namespace al
