#pragma once

#include "Game/Player/Player.h"
#include "al/MapObj/MapObjActor.h"
#include <sead/math/seadVector.h>

class PlayerActor : public al::MapObjActor {
    u8 unk[0x16];

public:
    Player* mPlayer;

private:
    u8 unk2[0xe4];

public:
    PlayerActor(const char* name);

    PlayerProperty* getProperty();
};
