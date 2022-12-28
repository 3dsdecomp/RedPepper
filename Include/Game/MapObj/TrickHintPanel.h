#pragma once

#include "al/MapObj/MapObjActor.h"

class TrickHintPanel : public al::MapObjActor {
    u32 unk0;
    u8 unk1;
public:
    TrickHintPanel(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);

    void exenrv1();
    void exenrv2();
    void exenrv3();
    void exenrv4();
};
