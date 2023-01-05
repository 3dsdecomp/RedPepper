#pragma once

#include "Game/Player/PlayerActionNode.h"

class PlayerActionGraph {
    PlayerActionNode* mCurrentNode;

public:
    PlayerActionNode* getCurrentNode() const { return mCurrentNode; }

    void move();
};
