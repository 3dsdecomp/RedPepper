#pragma once

#include "al/Layout/LayoutInitInfo.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveKeeper.h"
#include <sead/prim/seadSafeString.h>

namespace al {

class LayoutActor : public IUseNerve, public IUseUnknown, public IUseEffectKeeper {
protected:
    sead::SafeString mName;
    NerveKeeper* mNerveKeeper;
    void* mUnknown;
    EffectKeeper* mEffectKeeper;
    void* _20;
    void* _24;
    void* _28;
    bool mIsAlive;

public:
    LayoutActor(const char* name);

    virtual NerveKeeper* getNerveKeeper() const;
    virtual void appear();
    virtual void kill();
    virtual void movement();
    virtual void calcAnim();
    virtual void* getUnknown() const;
    virtual EffectKeeper* getEffectKeeper() const;
    virtual void control();
    virtual void unk1();
    virtual void unk2();

    void initNerve(const Nerve* nerve, int step);
};

void initLayoutActor(LayoutActor* layoutActor, const LayoutInitInfo& info, const char* archiveName, const char*);

void startAction(LayoutActor* actor, const sead::SafeString& actionName);

void setPaneString(LayoutActor* actor, const char* paneName, const char16* text);
void hidePane(LayoutActor* actor, const char* paneName);

} // namespace al
