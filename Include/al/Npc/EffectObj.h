#pragma once

#include "al/MapObj/MapObjActor.h"

namespace al {

class EffectObj : public MapObjActor {
    sead::Matrix34f mBaseMtx;

public:
    EffectObj(const sead::SafeString& name);

    virtual void init(const ActorInitInfo& info);
    virtual void makeActorAppeared();
    virtual void kill();
    virtual const sead::Matrix34f* getBaseMtx() const;
    virtual void control();

    friend class EffectObjFunction;
};

class EffectObjFunction {
public:
    static void initActorEffectObj(EffectObj* actor, const ActorInitInfo& info, const char* objectName);
};

} // namespace al
