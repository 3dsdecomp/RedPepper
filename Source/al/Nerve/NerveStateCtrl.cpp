#include "al/Nerve/NerveStateCtrl.h"

namespace al {

NON_MATCHING
#pragma O2
NerveStateCtrl::NerveStateCtrl(int capacity)
    : mCapacity(capacity)
    , mStateCount(0)
    , mStates(nullptr)
    , mCurrentState(nullptr)
{
    mStates = new State[capacity];
    for (int i = 0; i < mCapacity; i++) {
        State* state = &mStates[i];
        state->mState = nullptr;
        state->mHostStateNerve = nullptr;
        state->mName = nullptr;
    }
}

bool NerveStateCtrl::updateCurrentState()
{
    if (mCurrentState)
        return mCurrentState->mState->update();
    return false;
}

void NerveStateCtrl::startState(const Nerve* nerve)
{ // horrible
    State* curState;
    int i = 0;

    if (mStateCount > 0)
        while (i < mStateCount) {
            curState = &mStates[i];
            if (curState->mHostStateNerve == nerve)
                goto found;
            i++;
        }
    curState = nullptr;
found:
    mCurrentState = curState;
    if (curState == nullptr)
        return;

    curState->mState->appear();
}

void NerveStateCtrl::tryEndCurrentState()
{
    if (mCurrentState != nullptr && !mCurrentState->mState->isDead()) {
        mCurrentState->mState->kill();
        mCurrentState = nullptr;
    }
}

} // namespace al
