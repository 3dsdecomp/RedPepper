#include "al/Collision/CollisionUtil.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

bool isCollidedGround(const LiveActor* actor)
{
    return actor->getCollider()->getGroundDistance() >= 0;
}

} // namespace al
