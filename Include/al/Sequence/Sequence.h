#pragma once

#include "al/Nerve/NerveExecutor.h"
#include "al/Scene/Scene.h"
#include <sead/prim/seadSafeString.h>

namespace al {

class Sequence : public NerveExecutor {
    sead::FixedSafeString<64> mName;
    Scene* mCurrentScene;
    u8 unk[0xf0];

public:
    Sequence(const char* name);

    virtual void init(/*SequenceInitInfo& ?*/);
    virtual void update();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual bool isDisposable() const;
    virtual bool unk4();
    virtual int unk5();
    virtual int unk6();
};

} // namespace al
