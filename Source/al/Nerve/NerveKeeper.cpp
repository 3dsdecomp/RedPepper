#include "al/Nerve/NerveKeeper.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveStateCtrl.h"

namespace al {

#ifdef NON_MATCHING
const Nerve* NerveKeeper::getCurrentNerve()
{
    return mNerve == nullptr ? mEndNerve : mNerve;
}

void NerveKeeper::update()
{
    const Nerve* nerve;
    if (mNerve) {
        if (mStateCtrl) {
            mStateCtrl->tryEndCurrentState();
            mStateCtrl->startState(mNerve);
        }

        nerve = mNerve;
        mNerve = nullptr;
        mEndNerve = nerve;
        mStep = 0;
    } else
        nerve = mEndNerve;
    nerve->execute(this);
    mStep++;
    if (mNerve) {

        if (mStateCtrl) {
            mStateCtrl->tryEndCurrentState();
            mStateCtrl->startState(mNerve);
        }
        const Nerve* old = mNerve;
        mNerve = nullptr;
        mEndNerve = old;
        mStep = 0;
    }
}
#endif

#pragma no_inline
void NerveKeeper::setNerve(const Nerve* nerve)
{
    if (mStep >= 0 && mEndNerve != nullptr)
        mEndNerve->executeOnEnd(this);
    mNerve = nerve;
    mStep = -1;
}

void setNerve(IUseNerve* p, const Nerve* nerve)
{
    p->getNerveKeeper()->setNerve(nerve);
}

} // namespace al
