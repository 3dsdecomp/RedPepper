#pragma once

#include "Game/Layout/GameCountUp.h"
#include "al/Audio/AudioKeeper.h"
#include "al/Layout/LayoutInitInfo.h"
#include "al/Nerve/NerveExecutor.h"

class CoinCharger : public al::NerveExecutor {
    GameCountUp* mGameCountUp;
    void* _C;
    void* _10;
    al::AudioKeeper* mAudioKeeper;

public:
    CoinCharger(const al::LayoutInitInfo& info);
};
