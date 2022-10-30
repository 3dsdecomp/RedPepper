#include "al/LiveActor/LiveActorGroup.h"

namespace al {

void LiveActorGroup::registerActor(LiveActor* actor)
{
    mActors.pushBack(actor);
}

void LiveActorGroup::killAll()
{
    for (int i = 0; i < mActors.capacity(); i++)
        mActors.unsafeAt(i)->kill();
}

void LiveActorGroup::makeActorDeadAll()
{
    for (int i = 0; i < mActors.capacity(); i++)
        mActors.unsafeAt(i)->makeActorDead();
}

} // namespace al
