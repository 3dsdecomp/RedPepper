#pragma once

#include "types.h"
#include <sead/heap/seadHeap.h>

namespace al {

class MemorySystem {
    u8 unk[0xc];
    sead::Heap* mSceneResourceHeap;
    sead::Heap* mSceneHeap;
    u8 unk1[0x2c];

public:
    void createSceneResourceHeap(const char* stageName);
};

} // namespace al
