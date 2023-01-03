#pragma once

#include "Game/Player/PlayerActorInitInfo.h"
#include "al/LiveActor/ActorInitInfo.h"
#include <sead/math/seadVector.h>

class PlayerModelHolder {
public:
    PlayerModelHolder(const al::ActorInitInfo& info, const PlayerActorInitInfo& playerInfo, const sead::Vector3f* transPtr, const sead::Vector3f* rotatePtr, long long);
};
