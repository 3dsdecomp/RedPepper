#include "al/LiveActor/SubActorFunction.h"
#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorFunction.h"

void alSubActorFunction::trySyncAlive(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.size(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 1)
            subActor->actor->makeActorAppeared();
    }
}

void alSubActorFunction::trySyncDead(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.size(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 1)
            subActor->actor->makeActorDead();
    }
}

#pragma O3
void alSubActorFunction::trySyncClippingStart(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.size(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 2 && al::isAlive(subActor->actor) && !al::isClipped(subActor->actor))
            subActor->actor->startClipped();
    }
}

void alSubActorFunction::trySyncClippingEnd(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.size(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 2 && al::isAlive(subActor->actor) && al::isClipped(subActor->actor))
            subActor->actor->endClipped();
    }
}

void alSubActorFunction::tryCalcAnim(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.size(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 8 && al::isAlive(subActor->actor))
            subActor->actor->calcAnim();
    }
}
