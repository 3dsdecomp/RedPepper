#pragma once

#include "al/Functor/FunctorBase.h"
#include <sead/prim/seadSafeString.h>

namespace sead {
class DelegateThread;
} // namespace sead

namespace al {

class AsyncFunctorThread {
    class sead::DelegateThread* mSeadThread;
    const FunctorBase* mFunctor;
    bool mIsDone;

public:
    AsyncFunctorThread(const sead::SafeString& name, const FunctorBase& functor, int);

    virtual ~AsyncFunctorThread();

    void start();
    bool isDone() const { return mIsDone; }
};

} // namespace al
