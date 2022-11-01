#pragma once

#include "al/Save/SaveDataSequenceBase.h"
#include "al/Save/SaveDataSequenceInitDir.h"
#include "types.h"
namespace al {

class SaveDataDirector {
    void* _0;
    SaveDataSequenceBase* _4;
    SaveDataSequenceBase* _8;
    SaveDataSequenceInitDir* mInitDirSequence;
    u8 _10[0x58];
    class AsyncFunctorThread* mSaveDataThread;
    void* _6C;

public:
    SaveDataDirector(u32, s32);
};

} // namespace al
