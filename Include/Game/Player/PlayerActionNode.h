#pragma once

#include "Game/Player/PlayerAction.h"
#include <sead/container/seadListImpl.h>

class PlayerActionNode {
    PlayerAction* mAction;
    sead::ListImpl mList;

public:
    PlayerAction* getAction() const { return mAction; }

    virtual ~PlayerActionNode();
};
