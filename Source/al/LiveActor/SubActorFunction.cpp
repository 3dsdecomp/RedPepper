#include "al/LiveActor/SubActorFunction.h"
#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorFunction.h"

void alSubActorFunction::trySyncAlive(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.capacity(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 1)
            subActor->actor->makeActorAppeared();
    }
}

#pragma O3
NON_MATCHING
// nops
void alSubActorFunction::trySyncClippingStart(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.capacity(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 2 && al::isAlive(subActor->actor) && !subActor->actor->getLiveActorFlag().isClipped)
            subActor->actor->startClipped();
    }
}

void alSubActorFunction::tryCalcAnim(al::SubActorKeeper* p)
{
    for (int i = 0; i < p->mSubActors.capacity(); i++) {
        al::SubActorKeeper::Entry* subActor = p->mSubActors.unsafeAt(i);
        if (subActor->_8 & 8 && al::isAlive(subActor->actor))
            subActor->actor->calcAnim();
    }
}
