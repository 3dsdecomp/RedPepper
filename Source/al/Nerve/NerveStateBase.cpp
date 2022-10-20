#include "al/Nerve/NerveStateBase.h"

namespace al {

#ifdef NON_MATCHING
NerveStateBase::NerveStateBase(const char* name)
    : NerveExecutor(name)
    , mIsDead(true)
{
}
#endif

void NerveStateBase::init()
{
}
void NerveStateBase::appear() { mIsDead = false; }
void NerveStateBase::kill() { mIsDead = true; }
bool NerveStateBase::update()
{
    updateNerve();
    if (!mIsDead) {
        control();
        return false;
    }
    return true;
}
void NerveStateBase::control() { }

} // namespace al
