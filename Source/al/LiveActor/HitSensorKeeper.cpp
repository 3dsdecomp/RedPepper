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

} // namespace al
