#include "al/Nerve/NerveKeeper.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveStateCtrl.h"

namespace al {

NerveKeeper::NerveKeeper(IUseNerve* host, const Nerve* nrv, int maxNerveStates)
    : mEndNerve(nullptr)
    , mStep(0)
    , mStateCtrl(nullptr)
    , mActionCtrl(nullptr)
{
    mHost = host;
    mNerve = nrv;

    if (maxNerveStates > 0)
        mStateCtrl = new NerveStateCtrl(maxNerveStates);
}

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

void NerveKeeper::setNerve(const Nerve* nerve)
{
    if (mStep >= 0 && mEndNerve != nullptr)
        mEndNerve->executeOnEnd(this);
    mNerve = nerve;
    mStep = -1;
}

} // namespace al
