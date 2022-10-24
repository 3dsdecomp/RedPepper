#include "Game/Enemy/Togezo.h"
#include "Game/Player/PlayerFunction.h"
#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Nerve/NerveFunction.h"
#include "al/Nerve/NerveStateBase.h"

namespace NrvTogezo {

NERVE_DEF(Togezo, Wander);
NERVE_DEF(Togezo, Turn);
NERVE_DEF(Togezo, Search);
NERVE_DEF(Togezo, Chase);
NERVE_DEF(Togezo, Attack);
NERVE_DEF(Togezo, BlowDown);

} // namespace NrvTogezo

static WalkerStateParam sTogezoWalkerStateParam(4.0, 0.98, 0.85, 250.0, 700.0, 180.0, 70.0, 150.0);
static WalkerStateWanderParam sTogezoWalkerStateWanderParam(30, 90, 0.7, 4.0, 10.0, "Walk", "Wait");
static WalkerStateChaseParam sTogezoWalkerStateChaseParam(false, true, 1.3, 30.0, 150.0, 3.0, 20.0, "Run", "Wait");

#pragma O3
Togezo::Togezo(const sead::SafeString& name)
    : MapObjActor(name)
    , mWanderState(nullptr)
    , mChaseState(nullptr)
    , mBlowDownState(nullptr)
{
}

extern "C" void FUN_0027a1a0(al::LiveActor* actor, const char*); // inits al::Collider->_4
extern "C" void FUN_0027cf20(al::LiveActor* actor, const al::ActorInitInfo& info, int);

#ifdef NON_MATCHING // inline nop
void Togezo::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "Togezo");
    FUN_0027a1a0(this, "à⁄ìÆêßå¿");
    FUN_0027cf20(this, info, 1);
    al::initNerve(this, &NrvTogezo::Wander, 3);
    mWanderState = new WalkerStateWander(this, al::getFrontPtr(this), &sTogezoWalkerStateParam, &sTogezoWalkerStateWanderParam);
    mChaseState = new WalkerStateChase(this, al::getFrontPtr(this), &sTogezoWalkerStateParam, &sTogezoWalkerStateChaseParam, false);
    mBlowDownState = new EnemyStateBlowDown(this, nullptr, nullptr, 0);
    al::initNerveState(this, mWanderState, &NrvTogezo::Wander, "[State] úpúj");
    al::initNerveState(this, mChaseState, &NrvTogezo::Chase, "[State] í«Ç¢Ç©ÇØ");
    al::initNerveState(this, mBlowDownState, &NrvTogezo::BlowDown, "[State] êÅÇ¡îÚÇ—éÄ");
    makeActorAppeared();
}

extern "C" bool FUN_00272a9c();
extern "C" bool FUN_00259758(al::LiveActor*, const sead::Vector3f&, const WalkerStateParam*);

#endif

void Togezo::exeWander()
{
    al::updateNerveState(this);
    if (!FUN_00272a9c() && FUN_00259758(this, al::getFront(this), &sTogezoWalkerStateParam))
        al::setNerve(this, &NrvTogezo::Turn);
}

extern "C" bool FUN_00262988(al::LiveActor*, sead::Vector3f* out, const sead::Vector3f&, float); // turn (?)
extern "C" void FUN_00258774(Togezo*, const WalkerStateParam*);

#ifdef NON_MATCHING // inline nops
void Togezo::exeTurn()
{
    if (al::isFirstStep(this))
        al::startAction(this, "Turn");
    FUN_00258774(this, &sTogezoWalkerStateParam);
    if (FUN_00272a9c()) {
        al::setNerve(this, &NrvTogezo::Wander);
        return;
    }
    if (FUN_00262988(this, al::getFrontPtr(this), rp::getPlayerTrans(), 6.0))
        al::setNerve(this, &NrvTogezo::Search);
}

void Togezo::exeSearch() // inline nops
{
    if (al::isFirstStep(this))
        al::startAction(this, "Search");
    FUN_00258774(this, &sTogezoWalkerStateParam);
    FUN_00262988(this, al::getFrontPtr(this), rp::getPlayerTrans(), 6.0);
    if (al::isActionEnd(this)) {
        if (FUN_00272a9c())
            al::setNerve(this, &NrvTogezo::Wander);
        else
            al::setNerve(this, &NrvTogezo::Chase);
    }
}
#endif

extern "C" bool FUN_0026b6cc(WalkerStateWander*, const sead::Vector3f& trans);

void Togezo::exeChase()
{
    if (al::updateNerveStateAndNextNerve(this, &NrvTogezo::Wander))
        FUN_0026b6cc(mWanderState, al::getTrans(this));
}

#ifdef NON_MATCHING // inline nops
void Togezo::exeAttack()
{
    if (al::isFirstStep(this)) {
        al::startAction(this, "AttackSuccess");
        FUN_00258774(this, &sTogezoWalkerStateParam);
    }
    if (al::isActionEnd(this))
        al::setNerve(this, &NrvTogezo::Wander);
}
#endif

extern "C" void FUN_00279158(Togezo*, const EnemyStateBlowDown*);

void Togezo::exeBlowDown()
{
    if (al::updateNerveState(this)) {
        FUN_00279158(this, mBlowDownState);
        kill();
    }
}
