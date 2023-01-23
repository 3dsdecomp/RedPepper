#pragma once

#include "al/Layout/LayoutActor.h"
#include "al/Layout/LayoutInitInfo.h"

class GameCountUp : public al::LayoutActor {
    sead::Vector3f _30;
    bool _3C;

public:
    GameCountUp(const al::LayoutInitInfo& info);
};
