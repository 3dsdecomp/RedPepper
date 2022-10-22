#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

bool isNerve(const IUseNerve* p, const Nerve* nerve);
void setNerve(IUseNerve* p, const al::Nerve* nerve);

bool isFirstStep(const IUseNerve* p);
bool isGreaterEqualStep(const IUseNerve* p, int t);

} // namespace al
