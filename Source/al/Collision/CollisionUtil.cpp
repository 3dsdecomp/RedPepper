#include "al/Collision/CollisionUtil.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

#ifdef NON_MATCHING // s0 <-> s1
bool isCollidedGround(const LiveActor* actor)
{
    return actor->getCollider()->getGroundDistance() >= 0;
}
#endif

} // namespace al
