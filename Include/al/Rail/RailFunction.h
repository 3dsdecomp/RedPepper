#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

void setSyncRailToStart(LiveActor* actor);

const sead::Vector3f& getRailDir(const LiveActor* actor);
bool isRailReachedGoal(const LiveActor* actor);

void moveSyncRail(LiveActor* actor, float speed);
void moveSyncRailTurn(LiveActor* actor, float speed);
void moveSyncRailLoop(LiveActor* actor, float speed);

bool isLoopRail(const LiveActor* actor);
bool isExistRail(const LiveActor* actor);

} // namespace al
