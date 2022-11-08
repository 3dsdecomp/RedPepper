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

NON_MATCHING const Nerve* NerveKeeper::getCurrentNerve()
{
    return mNerve == nullptr ? mEndNerve : mNerve;
}

NON_MATCHING void NerveKeeper::update()
{
    tryChangeNerve();
    mNerve->execute(this);
    mStep++;
    tryChangeNerve();
}

void NerveKeeper::tryChangeNerve()
{
    if (mNerve == NULL) {
        return;
    }

    if (mStateCtrl) {
        mStateCtrl->tryEndCurrentState();
        mStateCtrl->startState(mNerve);
    }

    const Nerve* pNextState = mNerve;
    mStep = 0;
    mEndNerve = pNextState;
    mNerve = NULL;
}

void NerveKeeper::setNerve(const Nerve* nerve)
{
    if (mStep >= 0 && mEndNerve != nullptr)
        mEndNerve->executeOnEnd(this);
    mNerve = nerve;
    mStep = -1;
}

} // namespace al
