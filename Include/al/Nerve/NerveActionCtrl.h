#pragma once

#include "al/LiveActor/LiveActor.h"

namespace alNerveFunction {

class NerveActionCollector { };

} // namespace alNerveFunction

namespace al {

class NerveActionCtrl { };

void initNerveAction(LiveActor* actor, const char* name, alNerveFunction::NerveActionCollector*, int step);

} // namespace al
