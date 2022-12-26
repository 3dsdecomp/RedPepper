#include "Game/Enemy/Fugumannen.h"
#include "Game/Enemy/EnemyStateBlowDown.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/HitSensorFunction.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/LiveActor/SensorMsg.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveFunction.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Rail/RailFunction.h"

namespace NrvFugumannen {

NERVE_DEF(Fugumannen, Move)
NERVE_DEF(Fugumannen, Move2)
NERVE_DEF(Fugumannen, BlowDown)

} // namespace NrvFugumannen

#pragma O3
Fugumannen::Fugumannen(const sead::SafeString& name)
    : MapObjActor(name)
    , mRailMoveSpeed(10.0)
    , mStateBlowDown(nullptr)
{
}

extern "C" void FUN_0027b51c(al::LiveActor*, const al::ActorInitInfo& info, int);
extern "C" void FUN_0027ee34(al::LiveActor*, const al::ActorInitInfo& info, int);

void Fugumannen::init(const al::ActorInitInfo& info)
{
    al::initActor(this, info);
    al::tryGetArg0(&mRailMoveSpeed, info);
    if (al::isExistRail(info)) {
        initRailKeeper(info);
        al::setSyncRailToStart(this);
    }
    al::initNerve(this, &NrvFugumannen::Move, 1);
    mStateBlowDown = new EnemyStateBlowDown(this, nullptr, "SwimBlowDown", 1);
    al::initNerveState(this, mStateBlowDown, &NrvFugumannen::BlowDown, "state:BlowDown");
    al::startAction(this, "SwimWait");
    FUN_0027b51c(this, info, 3);
    FUN_0027ee34(this, info, 3);
    al::offCollide(this);
    makeActorAppeared();
}

void Fugumannen::attackSensor(al::HitSensor* me, al::HitSensor* other)
{
    if (!al::isNerve(this, &NrvFugumannen::BlowDown) && al::isSensorName(me, "Attack")) {
        al::sendMsg41(other, me);
        al::sendMsgEnemyAttack(other, me);
    }
}

extern "C" bool FUN_0027b768(u32, al::HitSensor*, al::HitSensor*, al::NerveStateBase*, const al::Nerve*);
extern "C" bool FUN_0027b704(u32, al::HitSensor*, al::HitSensor*, al::NerveStateBase*);

bool Fugumannen::receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me)
{
    if (al::isNerve(this, &NrvFugumannen::BlowDown) || al::isSensorName(me, "Attack"))
        return false;

    bool rv = FUN_0027b768(msg, other, me, mStateBlowDown, &NrvFugumannen::BlowDown);
    if (rv) // 💀 ?
        rv = true;

    if (!rv && (rv = al::isMsg9(msg), rv)) {
        FUN_0027b704(msg, other, me, mStateBlowDown);
        al::setNerve(this, &NrvFugumannen::BlowDown);
        return true;
    }

    return rv;
}

extern "C" void FUN_00240e08(al::LiveActor*, const sead::Vector3f&, float);

NON_MATCHING
// no inline
void Fugumannen::exeMove()
{
    al::moveSyncRailTurn(this, mRailMoveSpeed);
    sead::Vector3f railDir = al::getRailDir(this);
    if (!al::isLoopRail(this))
        railDir *= -1;
    FUN_00240e08(this, railDir, 4.0);
    if (al::isRailReachedGoal(this))
        al::setNerve(this, &NrvFugumannen::Move2);
}

NON_MATCHING
// vector copy isn't optimized to ldm/stm for xy
void Fugumannen::exeMove2()
{
    sead::Vector3f railDir = al::getRailDir(this);
    if (!al::isLoopRail(this))
        railDir *= -1;
    FUN_00240e08(this, railDir, 4.0);
    if (al::isGreaterStep(this, 45))
        al::setNerve(this, &NrvFugumannen::Move);
}

extern "C" void FUN_002cd428(al::LiveActor*, al::NerveStateBase*);

void Fugumannen::exeBlowDown()
{
    if (al::updateNerveState(this)) {
        FUN_002cd428(this, mStateBlowDown);
        kill();
    }
}
