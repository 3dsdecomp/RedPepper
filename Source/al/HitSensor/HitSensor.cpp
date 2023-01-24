#include "al/HitSensor/HitSensor.h"
#include "al/HitSensor/SensorHitGroup.h"

namespace al {

void HitSensor::validate()
{
    if (!mIsValid) {
        mIsValid = true;
        if (mMaxSensorCount && mIsValidBySystem)
            mSensorHitGroup->add(this);
    }
    mSensorCount = 0;
}

void HitSensor::invalidate()
{
    if (mIsValid) {
        mIsValid = false;
        if (mMaxSensorCount && mIsValidBySystem)
            mSensorHitGroup->remove(this);
    }
    mSensorCount = 0;
}

void HitSensor::validateBySystem()
{
    if (mIsValidBySystem)
        return;
    if (mMaxSensorCount && mIsValid)
        mSensorHitGroup->add(this);
    mIsValidBySystem = true;
    mSensorCount = 0;
}

void HitSensor::invalidateBySystem()
{
    if (!mIsValidBySystem)
        return;
    if (mMaxSensorCount && mIsValid)
        mSensorHitGroup->remove(this);
    mIsValidBySystem = false;
    mSensorCount = 0;
}

} // namespace al
