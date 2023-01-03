#include "Game/Player/PlayerAnimator.h"
#include "Game/Player/PlayerAnimFrameCtrl.h"

float PlayerAnimator::getAnimFrame() const { return mAnimFrameCtrl->getCurrentFrame(); }
