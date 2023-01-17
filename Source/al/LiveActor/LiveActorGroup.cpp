#include "al/LiveActor/LiveActorGroup.h"

namespace al {

NON_MATCHING // stupid
LiveActorGroup::LiveActorGroup(const char* name, int bufSize)
    : mName(name)
{
    mActors.allocBufferInline(bufSize);
}

void LiveActorGroup::registerActor(LiveActor* actor)
{
    mActors.pushBack(actor);
}

void LiveActorGroup::killAll()
{
    for (int i = 0; i < mActors.size(); i++)
        mActors.unsafeAt(i)->kill();
}

void LiveActorGroup::makeActorDeadAll()
{
    for (int i = 0; i < mActors.size(); i++)
        mActors.unsafeAt(i)->makeActorDead();
}

} // namespace al
