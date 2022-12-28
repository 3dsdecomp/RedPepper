#include "Game/MapObj/TrickHintPanel.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/LiveActor/SensorMsg.h"
#include "al/Nerve/NerveFunction.h"
#include "al/Nerve/NerveStateBase.h"

namespace NrvTrickHintPanel {

NERVE_DEF(TrickHintPanel, nrv1);
NERVE_DEF(TrickHintPanel, nrv2);
NERVE_DEF(TrickHintPanel, nrv3);
NERVE_DEF(TrickHintPanel, nrv4);

} // namespace NrvTrickHintPanel

#pragma O3
TrickHintPanel::TrickHintPanel(const sead::SafeString& name)
    : MapObjActor(name),
    unk0(0),
    unk1(0)
{
}

extern "C" u32 FUN_002278CC(al::LiveActor* actor, char* str);

void TrickHintPanel::init(const al::ActorInitInfo& info)
{
    al::initActor(this, info);
    al::initNerve(this, &NrvTrickHintPanel::nrv1, 0);
    unk0 = FUN_002278CC(this, "");
    makeActorAppeared();
}

bool TrickHintPanel::receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me)
{
    if(al::isMsgFloorTouch(msg))
    {
        if(al::isNerve(this, &NrvTrickHintPanel::nrv1))
        {
            al::setNerve(this, &NrvTrickHintPanel::nrv2);
            return true;
        }

        if(al::isNerve(this, &NrvTrickHintPanel::nrv3))
        {
            al::setNerve(this, &NrvTrickHintPanel::nrv3);
            return true;
        }
    }
    return false;
}

void TrickHintPanel::exenrv1(){

}

void TrickHintPanel::exenrv2(){
    
}

void TrickHintPanel::exenrv3(){
    
}

void TrickHintPanel::exenrv4(){
    
}
