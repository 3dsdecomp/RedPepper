#pragma once

#include "al/Nerve/NerveStateBase.h"

namespace al {

class NerveStateCtrl {
    struct State {
        NerveStateBase* mState;
        const Nerve* mHostStateNerve;
        const char* mName;
    };

    int mCapacity;
    int mStateCount;
    State* mStates;
    State* mCurrentState;

public:
    NerveStateCtrl(int capacity);

    bool updateCurrentState();
    void startState(const Nerve* nerve);
    void tryEndCurrentState();
};

} // namespace al
