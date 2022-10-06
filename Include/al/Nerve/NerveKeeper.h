#pragma once

#include "types.h"

namespace al {

struct Nerve;
class IUseNerve;
class NerveStateCtrl;

class NerveKeeper {
public:
    IUseNerve* mParent;

private:
    const Nerve* mEndNerve;
    const Nerve* mNerve;
    int mStep;
    NerveStateCtrl* mStateCtrl;
    void* unk;

public:
    const Nerve* getCurrentNerve();
    void update();
    void setNerve(const Nerve* nerve);
    inline int getStep() { return mStep; }
};

class IUseNerve {
public:
    virtual NerveKeeper* getNerveKeeper() const = 0;
};

static_assert(sizeof(NerveKeeper) == 0x18, "");

void setNerve(IUseNerve* p, const Nerve* nerve);
bool isNerve(const IUseNerve* p, const Nerve* nerve);

bool isFirstStep(const IUseNerve* p);

} // namespace al
