#include "al/LiveActor/LiveActorGroup.h"

namespace al {

void LiveActorGroup::makeActorDeadAll()
{
    for (int i = 0; i < mActors.capacity(); i++)
        mActors.unsafeAt(i)->makeActorDead();
}

} // namespace al
