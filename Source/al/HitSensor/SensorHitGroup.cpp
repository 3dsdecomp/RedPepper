#include "al/HitSensor/SensorHitGroup.h"

namespace al
{

void SensorHitGroup::add(HitSensor *sensor)
{
    mSensors.pushBack(sensor);
}

} // namespace al
