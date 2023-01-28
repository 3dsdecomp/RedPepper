#pragma once

#include "types.h"
#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace al {

enum SensorType {
    SensorType_Eye,
    SensorType_Player,
    SensorType_Npc,
    SensorType_Ride,
    SensorType_Enemy,
    SensorType_EnemyBody,
    SensorType_EnemyAttack,
    SensorType_Dossun,
    SensorType_KillerMagnum,
    SensorType_EnemySimple,
    SensorType_MapObj,
    SensorType_MapObjSimple,
    SensorType_Bindable,
    SensorType_CollisionParts,
    SensorType_KickKoura,
    SensorType_PlayerFireBall,
    SensorType_WooGanSandBody
};

class LiveActor;
class SensorHitGroup;
class HitSensor {
    const char* mName;
    u32 mSensorType;
    u32 _8;
    u32 _C;
    float _10;
    float mSensorRadius;
    u16 mMaxSensorCount;
    u16 mSensorCount;
    HitSensor** mSensors;
    SensorHitGroup* mSensorHitGroup;
    bool mIsValidBySystem;
    bool mIsValid;
    LiveActor* mHostActor;
    sead::Vector3f* mFollowPos;
    sead::Matrix34f* mFollowMtx;
    sead::Vector3f _34;

public:
    const char* getName() { return mName; }
    LiveActor* getHost() { return mHostActor; }
    u32 getType() const { return mSensorType; }
    float getRadius() const { return mSensorRadius; }
    void validate();
    void invalidate();
    void validateBySystem();
    void invalidateBySystem();
    void update();

    friend class HitSensorKeeper;
};

static_assert(sizeof(HitSensor) == 0x40, "");

bool isHitCylinderSensor(HitSensor*, HitSensor*, const sead::Vector3f&, float);

} // namespace al
