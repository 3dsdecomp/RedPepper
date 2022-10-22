#include "al/Nerve/NerveFunction.h"

namespace al {

bool isNerve(const IUseNerve* p, const Nerve* nerve)
{
    return p->getNerveKeeper()->getCurrentNerve() == nerve;
}

void setNerve(IUseNerve* p, const Nerve* nerve)
{
    p->getNerveKeeper()->setNerve(nerve);
}

bool isFirstStep(const IUseNerve* p) { return p->getNerveKeeper()->getStep() == 0; }
bool isGreaterEqualStep(const IUseNerve* p, int t) { return p->getNerveKeeper()->getStep() >= t; }

} // namespace al
