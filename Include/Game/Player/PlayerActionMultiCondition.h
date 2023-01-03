#pragma once

#include "Game/Player/PlayerActionCondition.h"
#include <sead/container/seadOffsetList.h>

class PlayerActionMultiCondition : public PlayerActionCondition {
    sead::OffsetList<PlayerActionCondition*> mConditions;

public:
    PlayerActionMultiCondition();

    virtual bool check();
    virtual void setup();

    void append(PlayerActionCondition* condition);
};
