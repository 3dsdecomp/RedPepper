#include "al/Nerve/NerveExecutor.h"

namespace al {

#ifdef NON_MATCHING
NerveExecutor::NerveExecutor(const char* name)
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
    if (mNerveKeeper != nullptr)
        mNerveKeeper->update();
}
#endif

} // namespace al
