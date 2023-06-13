#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/LiveActor/SensorMsg.h"
#include "al/MapObj/FallMapParts.h"
#include "al/Nerve/NerveFunction.h"
#include "al/Nerve/NerveKeeper.h"
#include "al/Placement/PlacementFunction.h"

namespace al {

namespace NrvFallMapParts {

    NERVE_DEF(FallMapParts, Appear);
    NERVE_DEF(FallMapParts, Wait);
    NERVE_DEF(FallMapParts, FallSign);
    NERVE_DEF(FallMapParts, Fall);
    NERVE_DEF(FallMapParts, End);

} // namespace NrvFallMapParts

NON_MATCHING // float
FallMapParts::FallMapParts(const sead::SafeString& name)
    : MapObjActor(name)
    , mStartTrans(sead::Vector3f::zero)
    , mFallFrames(60)
    , _70(false)
{
}

NON_MATCHING
// instruction swap
void FallMapParts::init(const ActorInitInfo& info)
{
    initActorPoseTQSV(this);
    initMapPartsActor(this, info); // this should be a thunk
    mStartTrans = getTrans(this);
    tryGetArg0(&mFallFrames, getPlacementInfo(info));
    initNerve(this, &NrvFallMapParts::Wait);
    initStageSwitchAppear(this, info);
    trySyncStageSwitchAppear(this);
}

bool FallMapParts::receiveMsg(u32 msg, HitSensor* other, HitSensor* me)
{
    if (isMsg52(msg)) {
        setNerve(this, &NrvFallMapParts::End);
        return true;
    }
    if (isMsgPlayerFloorTouch(msg) && isNerve(this, &NrvFallMapParts::Wait)) {
        setNerve(this, &NrvFallMapParts::FallSign);
        invalidateClipping(this);
        return true;
    }
    return false;
}

NON_MATCHING
// inline nop
void FallMapParts::exeAppear()
{
    if (isFirstStep(this)) {
        validateCollisionPartsBySystem(this);
        if (!tryStartAction(this, "Appear"))
            goto end; // ?
    }
    if (isActionEnd(this))
    end:
        setNerve(this, &NrvFallMapParts::Wait);
}

void FallMapParts::exeWait()
{
    if (isFirstStep(this)) {
        tryStartAction(this, "Wait");
        validateClipping(this);
    }
}

NON_MATCHING
void FallMapParts::exeFallSign() { }

extern "C" bool FUN_00268df8(IUseAudioKeeper*, const sead::SafeString& name); // something with sound

NON_MATCHING
// inline nop, string locations
void FallMapParts::exeFall()
{
    if (isFirstStep(this)) {
        tryStartAction(this, "Fall");
        FUN_00268df8(this, "FallStart");
        setTrans(this, mStartTrans);
    }
    addVelocityToGravity(this, 1.0);
    scaleVelocity(this, 0.9);
    if (isGreaterStep(this, mFallFrames))
        setNerve(this, &NrvFallMapParts::End);
}

void FallMapParts::exeEnd()
{
    if (isFirstStep(this)) {
        tryStartAction(this, "End");
        hideModel(this);
        invalidateCollisionPartsBySystem(this);
        setVelocityZero(this);
    }
    if (isGreaterStep(this, 60)) {
        setTrans(this, mStartTrans);
        resetPosition(this);
        showModel(this);
        setNerve(this, &NrvFallMapParts::Appear);
    }
}

} // namespace al
