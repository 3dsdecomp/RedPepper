#pragma once

#include "al/Nerve/NerveExecutor.h"
#include "al/Sequence/Sequence.h"

class GameSystem : public al::NerveExecutor {
    al::Sequence* mCurrentSequence;
    void* _C;
    void* _10;
    void* _14;
    void* _18;
    void* _1C;
    void* _20;
    void* _24;
    void* _28;
    void* _2C;
    void* _30;
    void* _34;

public:
    GameSystem();

    virtual void init() {};
    virtual void movement() {};
    virtual void v6() {};
    virtual void v7() {};
    virtual void v8() {};
};
