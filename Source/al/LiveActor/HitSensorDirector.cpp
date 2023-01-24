#include "al/LiveActor/HitSensorDirector.h"
#include "al/Execute/ExecuteTableHolder.h"

namespace al {

HitSensorDirector::HitSensorDirector()
    : mPlayerHitGroup(nullptr)
    , mRideHitGroup(nullptr)
    , mEyeHitGroup(nullptr)
    , mSimpleHitGroup(nullptr)
    , mMapObjHitGroup(nullptr)
    , mCharacterHitGroup(nullptr)
{
    mPlayerHitGroup = new SensorHitGroup(16, "Player");
    mRideHitGroup = new SensorHitGroup(128, "Ride");
    mEyeHitGroup = new SensorHitGroup(512, "Eye");
    mSimpleHitGroup = new SensorHitGroup(2048, "Simple");
    mMapObjHitGroup = new SensorHitGroup(1024, "MapObj");
    mCharacterHitGroup = new SensorHitGroup(1024, "Character");

    registerExecutorUser(this, "ÉZÉìÉTÅ[");
}

} // namespace al
