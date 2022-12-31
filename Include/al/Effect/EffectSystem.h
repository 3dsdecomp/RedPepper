#pragma once

#include <sead/heap/seadHeap.h>

namespace al {

class EffectSystem {
    sead::Heap* _0;

public:
    EffectSystem();

    void init();
    void startScene();
};

} // namespace al
