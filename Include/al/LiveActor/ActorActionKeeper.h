#pragma once

#include "al/LiveActor/ActionAnimCtrl.h"

namespace al {

class LiveActor;
class ActorActionKeeper {
    void* _0;
    void* _4;
    ActionAnimCtrl* mActionAnimCtrl;

public:
    void tryStartActionNoAnim(const char* name);
};

void startHitReaction(const LiveActor* actor, const char* name);

#define AL_LIVEACTOR_REACTION(TYPE)                         \
    void startHitReaction##TYPE(const LiveActor* actor);

AL_LIVEACTOR_REACTION(Appear)
AL_LIVEACTOR_REACTION(Disappear)
AL_LIVEACTOR_REACTION(PressDown)
AL_LIVEACTOR_REACTION(Death)
AL_LIVEACTOR_REACTION(Hit)
AL_LIVEACTOR_REACTION(BlowHit)
AL_LIVEACTOR_REACTION(Break)
AL_LIVEACTOR_REACTION(Start)
AL_LIVEACTOR_REACTION(End)
AL_LIVEACTOR_REACTION(OnGround)
AL_LIVEACTOR_REACTION(Get)

#undef AL_LIVEACTOR_REACTION

} // namespace al
