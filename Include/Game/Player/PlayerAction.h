#pragma once

#include <sead/prim/seadRuntimeTypeInfo.h>

class PlayerAction {
    SEAD_RTTI_BASE(PlayerAction)
public:
    virtual ~PlayerAction();
    virtual void move();
    virtual void update();
    virtual void setup();
    virtual void teardown();
};
