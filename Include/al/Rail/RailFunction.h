#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

void setSyncRailToStart(LiveActor* actor);

void moveSyncRail(LiveActor* actor, float speed);
void moveSyncRailTurn(LiveActor* actor, float speed);
void moveSyncRailLoop(LiveActor* actor, float speed);

bool isExistRail(const LiveActor* actor);

} // namespace al
