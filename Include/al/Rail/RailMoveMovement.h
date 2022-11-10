#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/Nerve/HostStateBase.h"

namespace al {

class RailMoveMovement : public HostStateBase<LiveActor> {
    float mSpeed;
    u32 mMoveType;

public:
    RailMoveMovement(LiveActor* host, const ActorInitInfo& info, const char* speedParamName = "Arg0", const char* moveTypeParamName = "Arg1");

    void exeMove();
};

} // namespace al
