#include "Game/Player/PlayerActionConditionAnimEnd.h"

PlayerActionConditionAnimEnd::PlayerActionConditionAnimEnd(IUsePlayerAnimator* animator, const char* animName, int animEndFrame)
    : mAnimName(animName)
    , mUsePlayerAnimator(animator)
    , mAnimEndFrame(animEndFrame)
{
}

bool PlayerActionConditionAnimEnd::check()
{
    if (mAnimName) {
        if (!(mUsePlayerAnimator->isAnim(mAnimName) && !mUsePlayerAnimator->isAnimEnd() && (mAnimEndFrame < 0 || mUsePlayerAnimator->getAnimFrame() < mAnimEndFrame)))
            return true;
    } else {
        if (mUsePlayerAnimator->isAnimEnd())
            return true;
        if ((mAnimEndFrame < 0))
            return false;
        if (!(mUsePlayerAnimator->getAnimFrame() < mAnimEndFrame))
            return true;
    }
    return false;
}
