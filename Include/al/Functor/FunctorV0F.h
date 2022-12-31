#pragma once

#include "al/Functor/FunctorBase.h"

namespace al {

class FunctorV0F : public FunctorBase {
    typedef void (*FuncType)();
    FuncType mFuncPtr;

public:
    FunctorV0F(FuncType func)
        : mFuncPtr(func)
    {
    }

    virtual void operator()() const { mFuncPtr(); }
    virtual FunctorBase* clone() const { return new FunctorV0F(mFuncPtr); }
};

} // namespace al
