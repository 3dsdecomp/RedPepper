#include "al/Nerve/NerveStateCtrl.h"

namespace al {

NerveStateCtrl::NerveStateCtrl(int capacity)
    : mCapacity(capacity)
    , mStateCount(0)
    , mStates(nullptr)
    , mCurrentState(nullptr)
{
    mStates = new State[mCapacity];
    for (int i = 0; i < mCapacity; i++) {
        State* state = &mStates[i];
        state->mState = nullptr;
        state->mHostStateNerve = nullptr;
        state->mName = nullptr;
    }
}

NerveStateCtrl::State* NerveStateCtrl::findStateInfo(const Nerve* nerve)
{
    for (int i = 0; i < mStateCount; i++) {
        State* state = &mStates[i];

        if (state->mHostStateNerve == nerve)
            return state;
    }

    return nullptr;
}

void NerveStateCtrl::startState(const Nerve* nerve)
{
    mCurrentState = findStateInfo(nerve);

    if (mCurrentState)
        mCurrentState->mState->appear();
}

bool NerveStateCtrl::updateCurrentState()
{
    if (mCurrentState)
        return mCurrentState->mState->update();
    return false;
}

void NerveStateCtrl::tryEndCurrentState()
{
    if (!isCurrentStateEnd()) {
        mCurrentState->mState->kill();
        mCurrentState = nullptr;
    }
}

bool NerveStateCtrl::isCurrentStateEnd() const
{
    if (mCurrentState)
        return mCurrentState->mState->isDead();
    return true;
}

} // namespace al
