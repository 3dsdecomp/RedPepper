#pragma once

#include "al/MapObj/MapObjActor.h"

class TrickHintPanel : public al::MapObjActor {
    u32 _96;
    bool mPlayedSound;
public:
    TrickHintPanel(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);
    virtual bool receiveMsg(u32 msg, al::HitSensor* other, al::HitSensor* me);

    void exeWait();
    void exeOn();
    void exenrv3();
    void exeOff();
};
