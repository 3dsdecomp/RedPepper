#include "Game/Player/PlayerActionMultiCondition.h"

PlayerActionMultiCondition::PlayerActionMultiCondition()
{
    mConditions.initOffset(sead::OffsetListNode<PlayerActionCondition*>::getListNodeOffset());
}

void PlayerActionMultiCondition::append(PlayerActionCondition* condition)
{
    mConditions.pushBack(*new sead::OffsetListNode<PlayerActionCondition*>(condition));
}

NON_MATCHING
bool PlayerActionMultiCondition::check() { return true; }

NON_MATCHING
// really very incorrect
void PlayerActionMultiCondition::setup()
{
    for (sead::OffsetList<PlayerActionCondition*>::iterator cur = mConditions.begin(); cur != mConditions.end(); ++cur)
        (*cur)->setup();
}
