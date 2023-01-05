#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

void syncCollisionMtx(LiveActor* actor, const sead::Matrix34f*);

bool isCollided(const LiveActor* actor);
bool isCollidedGround(const LiveActor* actor);
bool isCollidedWall(const LiveActor* actor);

} // namespace al
