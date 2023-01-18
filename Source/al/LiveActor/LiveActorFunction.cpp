#include "al/LiveActor/LiveActorFunction.h"
#include "al/Collision/CollisionUtil.h"
#include "al/Execute/ExecuteTableHolder.h"
#include "al/LiveActor/ActorPoseFunction.h"
#include "al/LiveActor/LiveActorKit.h"
#include "al/LiveActor/SubActorFunction.h"
#include "al/Math/MtxUtil.h"
#include "al/Model/ModelKeeper.h"
#include "al/Nerve/NerveFunction.h"

void alLiveActorFunction::calcAnimDirect(al::LiveActor* actor)
{
    sead::Matrix34f baseMtx;
    actor->mActorPoseKeeper->calcBaseMtx(&baseMtx); /* alActorPoseFunction::calcBaseMtx */
    if (actor->mModelKeeper)
        al::setBaseMtxAndCalcAnim(actor, baseMtx, actor->mActorPoseKeeper->getScale() /* al::getScale */);
    if (actor->mCollisionParts) {
        al::preScaleMtx(&baseMtx, actor->mActorPoseKeeper->getScale() /* al::getScale */);
        al::syncCollisionMtx(actor, &baseMtx);
    }
    if (actor->getEffectKeeper())
        actor->getEffectKeeper()->update();
    if (actor->mSubActorKeeper)
        alSubActorFunction::tryCalcAnim(actor->mSubActorKeeper);
}

namespace al {

// ??
bool isClipped(const LiveActor* actor) { return actor->getLiveActorFlag().isClipped; }
bool isInvalidClipping(const LiveActor* actor) { return actor->getLiveActorFlag().isInvalidClipping; }
bool isDead(const LiveActor* actor) { return actor->getLiveActorFlag().isDead; }
bool isAlive(const LiveActor* actor) { return !actor->getLiveActorFlag().isDead; }

void onCollide(LiveActor* actor)
{
    Collider* collider = actor->getCollider();
    actor->getLiveActorFlag().isOffCollide = false;
    if (collider)
        collider->onInvalidate();
}
void offCollide(LiveActor* actor) { actor->getLiveActorFlag().isOffCollide = true; }

void invalidateClipping(LiveActor* actor)
{
    if (isClipped(actor))
        actor->endClipped();

    if (!isInvalidClipping(actor))
        getLiveActorKit()->getClippingDirector()->getClippingActorHolder()->invalidateClipping(actor);
}

void validateClipping(LiveActor* actor)
{
    if (isInvalidClipping(actor))
        getLiveActorKit()->getClippingDirector()->getClippingActorHolder()->validateClipping(actor);
}

// ModelKeeper

NON_MATCHING
// optimization is too smart
void hideModel(LiveActor* actor)
{
    if (isAlive(actor) && !isClipped(actor)) {
        if (actor->getModelKeeper())
            actor->getModelKeeper()->hide();
        if (actor->getShadowKeeper())
            hideShadow(actor);
        alActorSystemFunction::removeFromExecutorDraw(actor);
    }
    actor->getLiveActorFlag().isHideModel = true;
}

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

NON_MATCHING
// ldr for getting ModelKeeper is optimized
void calcJointPos(sead::Vector3f* out, const LiveActor* actor, const char* jointName)
{
    const sead::Matrix34f* jointMtx = getJointMtxPtr(actor->getModelKeeper(), jointName);
    out->x = jointMtx->m[0][3];
    out->y = jointMtx->m[1][3];
    out->z = jointMtx->m[2][3];
}

// HitSensorKeeper

HitSensor* getHitSensor(const LiveActor* actor, const char* name)
{
    return actor->getHitSensorKeeper()->getSensor(name);
}

float getSensorRadius(const LiveActor* actor, const char* sensorName)
{
    return getHitSensor(actor, sensorName)->getRadius();
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
