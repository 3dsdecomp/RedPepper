#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"

namespace al {

// ModelKeeper

NON_MATCHING
// register swap, maybe inlined
bool tryStartMclAnimIfExist(LiveActor* actor, const char* animName)
{
    AnimPlayerSimple* animPlayer = actor->getModelKeeper()->getModel()->getMclAnimPlayer();
    if (animPlayer && animPlayer->isAnimExist(animName)) {
        actor->getModelKeeper()->getModel()->getMclAnimPlayer()->startAnim(animName);
        return true;
    }
    return false;
}

// NerveKeeper
#pragma no_inline
void startNerveAction(LiveActor* actor, const char* actionName)
{
    if (actor->getActorActionKeeper())
        actor->getActorActionKeeper()->tryStartActionNoAnim(actionName);
    alNerveFunction::setNerveAction(actor, actionName);
}

NON_MATCHING
// registers
void initNerve(LiveActor* actor, const Nerve* nerve, int maxNerveStates)
{
    actor->initNerveKeeper(new NerveKeeper(actor, nerve, maxNerveStates));
}

NON_MATCHING
// registers, too big for tail-reorder
void initNerveAction(LiveActor* actor, const char* name, alNerveFunction::NerveActionCollector* collector, int maxNerveStates)
{
    NerveActionCtrl* nerveActionCtrl = new NerveActionCtrl(collector);
    NerveAction* nerve = nerveActionCtrl->findNerve(name);
    NerveKeeper* nk = new NerveKeeper(actor, nerve, maxNerveStates);
    actor->initNerveKeeper(nk);
    actor->getNerveKeeper()->initNerveAction(nerveActionCtrl);
    startNerveAction(actor, name);
}

} // namespace al
