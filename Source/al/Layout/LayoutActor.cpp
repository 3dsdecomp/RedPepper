#include "al/Layout/LayoutActor.h"

namespace al {

#pragma O3
LayoutActor::LayoutActor(const char* name)
    : mName(name)
    , mNerveKeeper(nullptr)
    , mAudioKeeper(nullptr)
    , mEffectKeeper(nullptr)
    , _20(nullptr)
    , _24(nullptr)
    , _28(nullptr)
    , mIsAlive(false)
{
}

NerveKeeper* LayoutActor::getNerveKeeper() const { return mNerveKeeper; }

void LayoutActor::appear()
{
    mIsAlive = true;
    calcAnim();
}

void LayoutActor::kill()
{
    if (getEffectKeeper())
        getEffectKeeper()->deleteAndClearEffectAll();
    mIsAlive = false;
}

AudioKeeper* LayoutActor::getAudioKeeper() const { return mAudioKeeper; }
EffectKeeper* LayoutActor::getEffectKeeper() const { return mEffectKeeper; }

void LayoutActor::control() { }

void LayoutActor::initNerve(const Nerve* nerve, int step)
{
    mNerveKeeper = new NerveKeeper(this, nerve, step);
}

} // namespace al
