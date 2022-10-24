#pragma once

#include "al/Nerve/NerveExecutor.h"
#include "al/Scene/Scene.h"
#include <sead/prim/seadSafeString.h>

namespace al {

class Sequence : public NerveExecutor {
    sead::FixedSafeString<64> mName;

public:
    Scene* mCurrentScene;
    u8 unk[0xf0];

    Sequence(const char* name);

    virtual void init(/*SequenceInitInfo& ?*/);
    virtual void update();
    virtual void unk1();
    virtual void unk2();
    virtual void unk3();
    virtual bool isDisposable() const;
    virtual void unk4();
    virtual void unk5();
    virtual void unk6();
};

} // namespace al
