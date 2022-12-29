#pragma once

#include "al/MapObj/MapObjActor.h"

class TrickHintPanel : public al::MapObjActor {
    u32 _96;
    bool _100;
public:
    TrickHintPanel(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);

    void exenrv1();
    void exenrv2();
    void exenrv3();
    void exenrv4();
};
