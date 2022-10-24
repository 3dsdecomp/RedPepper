#include "Game/Player/PlayerProperty.h"

#ifdef NON_MATCHING
void PlayerProperty::setFrontVec(const sead::Vector3f& front)
{
    mFront = front;
}

void PlayerProperty::setUpVec(const sead::Vector3f& up)
{
    mUp = up;
}
#endif
