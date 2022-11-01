#include "al/Nerve/NerveFunction.h"
#include "al/Nerve/NerveActionCtrl.h"
#include "al/Nerve/NerveStateCtrl.h"

namespace al {

bool isStep(IUseNerve* p, int step) { return p->getNerveKeeper()->getStep() == step; }
bool isNerve(const IUseNerve* p, const Nerve* nerve)
{
    return p->getNerveKeeper()->getCurrentNerve() == nerve;
}

#pragma no_inline
void setNerve(IUseNerve* p, const Nerve* nerve)
{
    p->getNerveKeeper()->setNerve(nerve);
}

bool isFirstStep(const IUseNerve* p) { return p->getNerveKeeper()->getStep() == 0; }
bool isGreaterEqualStep(const IUseNerve* p, int t) { return p->getNerveKeeper()->getStep() >= t; }

bool updateNerveState(IUseNerve* p)
{
    return p->getNerveKeeper()->getStateCtrl()->updateCurrentState();
}

// registers
NON_MATCHING bool updateNerveStateAndNextNerve(IUseNerve* p, const Nerve* nerve)
{
    NerveStateCtrl* stateCtrl = p->getNerveKeeper()->getStateCtrl();
    if (stateCtrl->updateCurrentState()) {
        setNerve(p, nerve);
        return true;
    }
    return false;
}

} // namespace al

namespace alNerveFunction {

void setNerveAction(al::IUseNerve* p, const char* name)
{
    al::NerveKeeper* nk = p->getNerveKeeper();
    nk->setNerve(nk->getActionCtrl()->findNerve(name));
}

} // namespace alNerveFunction
