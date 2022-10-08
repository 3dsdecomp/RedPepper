#pragma Otime

#include "al/Nerve/NerveExecutor.h"

namespace al {

#ifdef NON_MATCHING // vtable pointer isnt put after the function
NerveExecutor::NerveExecutor()
    : mNerveKeeper(nullptr)
{
}
#endif

NerveKeeper* NerveExecutor::getNerveKeeper() const
{
    return mNerveKeeper;
}

#ifdef NON_MATCHING
void NerveExecutor::updateNerve()
{
    if (mNerveKeeper)
        mNerveKeeper->update();
}
#endif

} // namespace al
