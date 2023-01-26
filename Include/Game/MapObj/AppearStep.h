#pragma once

#include "al/MapObj/MapObjActor.h"

class AppearStep : public al::MapObjActor {
    void startAppear();
    void startDisappear();

public:
    AppearStep(const sead::SafeString& name);

    virtual void init(const al::ActorInitInfo& info);

    void exeAppear();
    void exeWait();
    void exeDisappear();
    void exeEnd();
};
