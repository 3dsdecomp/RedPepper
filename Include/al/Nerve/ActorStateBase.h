#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/Nerve/NerveStateBase.h"

namespace al {

class ActorStateBase : public al::NerveStateBase {
    LiveActor* mHost;

public:
    ActorStateBase(const char* name, LiveActor* host)
        : NerveStateBase(name)
        , mHost(host)
    {
    }
};

} // namespace al
