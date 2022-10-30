#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"

namespace al {

#pragma no_inline
void startNerveAction(LiveActor* actor, const char* actionName)
{
    if (actor->getActorActionKeeper())
        actor->getActorActionKeeper()->tryStartActionNoAnim(actionName);
    alNerveFunction::setNerveAction(actor, actionName);
}

NON_MATCHING // registers, too big for tail-reorder
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
