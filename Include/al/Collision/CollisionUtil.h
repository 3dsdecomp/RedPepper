#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

bool isCollided(const LiveActor* actor);
bool isCollidedGround(const LiveActor* actor);

} // namespace al
