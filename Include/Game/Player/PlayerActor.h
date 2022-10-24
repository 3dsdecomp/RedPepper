#pragma once

#include "Game/Player/Player.h"
#include "al/LiveActor/LiveActor.h"
#include <sead/math/seadVector.h>

class PlayerActor : public al::LiveActor {
    u8 unk[0x16];

public:
    Player* mPlayer;

private:
    u8 unk2[0xe4];
};
