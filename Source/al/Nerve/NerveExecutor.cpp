#pragma Otime

#include "al/Nerve/NerveExecutor.h"

namespace al {

#pragma O3
NerveExecutor::NerveExecutor(const char* name)
    : mNerveKeeper(nullptr)
{
}

NerveKeeper* NerveExecutor::getNerveKeeper() const
{
    return mNerveKeeper;
}

void NerveExecutor::initNerve(const Nerve* nrv, int step)
{
    mNerveKeeper = new NerveKeeper(this, nrv, step);
}

void NerveExecutor::updateNerve()
{
    if (mNerveKeeper)
        mNerveKeeper->update();
}

} // namespace al
