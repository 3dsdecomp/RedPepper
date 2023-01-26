#include "Game/MapObj/AppearStep.h"
#include "al/Functor/FunctorV0M.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"
#include "al/Stage/StageSwitchKeeper.h"

namespace NrvAppearStep {

NERVE_DEF(AppearStep, Appear)
NERVE_DEF(AppearStep, Wait)
NERVE_DEF(AppearStep, Disappear)
NERVE_DEF(AppearStep, End)

} // namespace NrvAppearStep

AppearStep::AppearStep(const sead::SafeString& name)
    : MapObjActor(name)
{
}

NON_MATCHING
// idk
void AppearStep::init(const al::ActorInitInfo& info)
{
    al::initActorPoseTQSV(this);
    al::initMapPartsActor(this, info);
    al::initNerve(this, &NrvAppearStep::End);
    al::initStageSwitchAppear(this, info);
    al::listenStageSwitchOnAppear(this, al::FunctorV0M<AppearStep*, void (AppearStep::*)()>(this, &AppearStep::startAppear), al::FunctorV0M<AppearStep*, void (AppearStep::*)()>(this, &AppearStep::startDisappear))
        ? makeActorDead()
        : makeActorAppeared();
}

void AppearStep::startAppear()
{
    if (al::isNerve(this, &NrvAppearStep::Disappear) || al::isNerve(this, &NrvAppearStep::End)) {
        al::invalidateClipping(this);
        al::setNerve(this, &NrvAppearStep::Appear);
        makeActorAppeared();
    }
}

void AppearStep::startDisappear()
{
    if (al::isNerve(this, &NrvAppearStep::Appear) || al::isNerve(this, &NrvAppearStep::Wait)) {
        al::invalidateClipping(this);
        al::setNerve(this, &NrvAppearStep::Disappear);
    }
}

void AppearStep::exeAppear()
{
    if (al::isFirstStep(this))
        al::tryStartAction(this, "Appear");

    if (al::isActionEnd(this))
        al::setNerve(this, &NrvAppearStep::Wait);
}

void AppearStep::exeWait()
{
    if (al::isFirstStep(this))
        al::validateClipping(this);
}

void AppearStep::exeDisappear()
{
    if (al::isFirstStep(this))
        al::tryStartAction(this, "Disappear");

    if (al::isActionEnd(this))
        al::setNerve(this, &NrvAppearStep::End);
}

void AppearStep::exeEnd()
{
    if (al::isFirstStep(this)) {
        al::validateClipping(this);
        kill();
    }
}
