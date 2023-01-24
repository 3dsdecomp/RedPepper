#include "Game/MapObj/TrickHintPanel.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/LiveActor/SensorMsg.h"
#include "al/Nerve/NerveFunction.h"
#include "al/Nerve/NerveStateBase.h"

namespace NrvTrickHintPanel {

NERVE_DEF(TrickHintPanel, Wait);
NERVE_DEF(TrickHintPanel, On);
NERVE_DEF(TrickHintPanel, nrv3);
NERVE_DEF(TrickHintPanel, Off);

} // namespace NrvTrickHintPanel

TrickHintPanel::TrickHintPanel(const sead::SafeString& name)
    : MapObjActor(name)
    , _96(0)
    , mPlayedSound(false)
{
}

extern "C" u32 FUN_002278CC(al::LiveActor* actor, char* str);

void TrickHintPanel::init(const al::ActorInitInfo& info)
{
    al::initActor(this, info);
    al::initNerve(this, &NrvTrickHintPanel::Wait, 0);
    _96 = FUN_002278CC(this, "");
    makeActorAppeared();
}

bool TrickHintPanel::receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me)
{
    if (al::isMsgFloorTouch(msg)) {
        if (al::isNerve(this, &NrvTrickHintPanel::Wait)) {
            al::setNerve(this, &NrvTrickHintPanel::On);
            return true;
        }

        if (al::isNerve(this, &NrvTrickHintPanel::nrv3)) {
            al::setNerve(this, &NrvTrickHintPanel::nrv3);
            return true;
        }
    }
    return false;
}

void TrickHintPanel::exeWait()
{
}

extern "C" int FUN_0026A9B8(u32);
extern "C" int FUN_0026AA60(u32);
extern "C" int FUN_002786F4();

NON_MATCHING
// inline nops
void TrickHintPanel::exeOn()
{
    if (!mPlayedSound) {
        al::startHitReactionStart(this);
        mPlayedSound = true;
    }
    al::startHitReaction(this, "ƒIƒ“"); // "ƒIƒ“" -> On
    FUN_0026A9B8(_96);
    al::invalidateClipping(this);
    al::setNerve(this, &NrvTrickHintPanel::nrv3);
}

void TrickHintPanel::exenrv3()
{
    if (!FUN_002786F4() || al::isGreaterStep(this, 20)) {
        al::setNerve(this, &NrvTrickHintPanel::Off);
    }
}

void TrickHintPanel::exeOff()
{
    if (FUN_002786F4()) {
        FUN_0026AA60(_96);
        al::validateClipping(this);
        al::setNerve(this, &NrvTrickHintPanel::Wait);
    }
}
