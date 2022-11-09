#pragma once

#include "al/MapObj/MapObjActor.h"

namespace al {

class FallMapParts : public MapObjActor {
    sead::Vector3f mStartTrans;
    int mFallFrames;
    bool _70;

public:
    FallMapParts(const sead::SafeString& name);

    virtual void init(const ActorInitInfo& info);
    virtual bool receiveMsg(u32 msg, HitSensor* other, HitSensor* me);

    void exeAppear();
    void exeWait();
    void exeFallSign();
    void exeFall();
    void exeEnd();
};

} // namespace al
