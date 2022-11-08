#include "al/AreaObj/AreaObj.h"
#include "al/Stage/StageSwitchKeeper.h"

namespace al {

StageSwitchKeeper* AreaObj::getStageSwitchKeeper() const { return mStageSwitchKeeper; }
void AreaObj::initStageSwitchKeeper() { mStageSwitchKeeper = new StageSwitchKeeper; }

bool AreaObj::isInVolume(const sead::Vector3f& trans) const
{
    if (_48)
        return mAreaShape->isInVolume(trans);
    return false;
}

} // namespace al
