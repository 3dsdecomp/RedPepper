#include "al/AreaObj/SwitchAreaDirector.h"
#include "Game/Player/PlayerFunction.h"

namespace al {

SwitchAreaDirector::SwitchAreaDirector()
    : LiveActor("スイッチエリアディレクター")
    , mSwitchOnAreaGroup(nullptr)
    , mSwitchKeepOnAreaGroup(nullptr)
{
}

NON_MATCHING
// not using stm for vector copy
void SwitchAreaDirector::movement()
{
    sead::Vector3f pos = rp::getPlayerPos();
    if (mSwitchOnAreaGroup)
        mSwitchOnAreaGroup->update(pos);
    if (mSwitchKeepOnAreaGroup)
        mSwitchKeepOnAreaGroup->update(pos);
}

} // namespace al
