#include "Game/Enemy/FireBall.h"
#include "al/Collision/CollisionUtil.h"
#include "al/LiveActor/ActorActionKeeper.h"
#include "al/LiveActor/HitSensorFunction.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/LiveActor/SensorMsg.h"
#include "al/Nerve/NerveFunction.h"

namespace NrvFireBall {

NERVE_DEF(FireBall, Shot)

} // namespace NrvFireBall

#pragma O3
FireBall::FireBall(const sead::SafeString& name)
    : MapObjActor(name)
{
}

void FireBall::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "FireBall");
    al::initNerve(this, &NrvFireBall::Shot);
    makeActorDead();
}

bool FireBall::receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me)
{
    if (al::isMsg9(msg) || al::isMsg12(msg) || al::isMsg40(msg) || al::isMsg16(msg)) {
        kill();
        if (al::isMsg16(msg))
            return false;
        else
            return true;
    }
    return false;
}

NON_MATCHING
// inline nops
void FireBall::exeShot()
{
    if (al::isFirstStep(this))
        al::tryStartAction(this, "Shot");
    if (al::isCollided(this)) {
        al::startHitReactionBreak(this);
        kill();
    }
    if (al::isGreaterStep(this, 90)) {
        al::startHitReactionDeath(this);
        kill();
    }
}
