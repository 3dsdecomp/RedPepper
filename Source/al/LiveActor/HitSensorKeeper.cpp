#include "al/LiveActor/HitSensorKeeper.h"
#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Util/StringUtil.h"

namespace al {

NON_MATCHING
// stores host actor instead of getting it again
void HitSensorKeeper::attackSensor()
{
    for (int i = 0; i < mSensors.size(); i++) {
        HitSensor* sensor = mSensors.unsafeAt(i);
        for (int j = 0; j < sensor->mSensorCount; j++)
            if (!al::isDead(sensor->mSensors[j]->getHost()))
                sensor->mSensors[j]->getHost()->attackSensor(sensor, sensor->mSensors[j]);
    }
}

void HitSensorKeeper::validate()
{
    for (int i = 0; i < mSensors.size(); i++) {
        mSensors.unsafeAt(i)->validate();
    }
}

void HitSensorKeeper::invalidate()
{
    for (int i = 0; i < mSensors.size(); i++) {
        mSensors.unsafeAt(i)->invalidate();
    }
}

void HitSensorKeeper::validateBySystem()
{
    for (int i = 0; i < mSensors.size(); i++) {
        mSensors.unsafeAt(i)->validateBySystem();
    }
}

void HitSensorKeeper::invalidateBySystem()
{
    for (int i = 0; i < mSensors.size(); i++) {
        mSensors.unsafeAt(i)->invalidateBySystem();
    }
}

HitSensor* HitSensorKeeper::getSensor(const char* name) const
{
    if (mSensors.size() == 1)
        return mSensors.unsafeAt(0);

    for (int i = 0; i < mSensors.size(); i++) {
        if (al::isEqualString(mSensors.unsafeAt(i)->getName(), name))
            return mSensors.unsafeAt(i);
    }
    return nullptr;
}

void HitSensorKeeper::update()
{
    for (int i = 0; i < mSensors.size(); i++)
        mSensors.unsafeAt(i)->update();
}

} // namespace al
