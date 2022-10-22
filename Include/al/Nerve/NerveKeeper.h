#pragma once

#include "types.h"

namespace al {

struct Nerve;
class IUseNerve;
class NerveStateCtrl;

class NerveKeeper {
    IUseNerve* mHost;
    const Nerve* mEndNerve;
    const Nerve* mNerve;
    int mStep;
    NerveStateCtrl* mStateCtrl;
    void* _14;

public:
    NerveKeeper(IUseNerve* host, const Nerve* nrv, int maxNerveStates = 0);

    const Nerve* getCurrentNerve();

    void update();
    void setNerve(const Nerve* nerve);
    inline IUseNerve* getHost() { return mHost; }
    inline int getStep() { return mStep; }
};

class IUseNerve {
public:
    virtual NerveKeeper* getNerveKeeper() const = 0;
};

static_assert(sizeof(NerveKeeper) == 0x18, "");

} // namespace al
