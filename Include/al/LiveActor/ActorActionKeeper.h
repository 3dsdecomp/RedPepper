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
void startHitReactionBreak(const LiveActor* actor);
void startHitReactionDeath(const LiveActor* actor);
void startHitReactionPressDown(const LiveActor* actor);

} // namespace al
