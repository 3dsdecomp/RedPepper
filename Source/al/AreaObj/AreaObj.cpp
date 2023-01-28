#include "al/AreaObj/AreaObj.h"
#include "al/Stage/StageSwitchKeeper.h"

namespace al {

NON_MATCHING
AreaObj::AreaObj(const char* name)
    : mName(name)
    , mAreaShape(nullptr)
    , mStageSwitchKeeper(nullptr)
    , _10(sead::Matrix34f::ident)
    , _40(nullptr)
    , _44(-1)
    , _48(1)
{
}

StageSwitchKeeper* AreaObj::getStageSwitchKeeper() const { return mStageSwitchKeeper; }
void AreaObj::initStageSwitchKeeper() { mStageSwitchKeeper = new StageSwitchKeeper; }

bool AreaObj::isInVolume(const sead::Vector3f& trans) const
{
    if (_48)
        return mAreaShape->isInVolume(trans);
    return false;
}

} // namespace al
