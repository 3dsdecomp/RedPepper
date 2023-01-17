#include "al/LiveActor/HitSensorKeeper.h"
#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorFunction.h"

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

} // namespace al
