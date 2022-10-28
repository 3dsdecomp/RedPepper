#pragma once

#include "types.h"
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
class HitSensor {
    const char* mName;
    SensorType mSensorType;
    u8 unk[0x20];
    LiveActor* mHostActor;

public:
    const char* getName() { return mName; }
    LiveActor* getHost() { return mHostActor; }
};

bool isHitCylinderSensor(HitSensor*, HitSensor*, const sead::Vector3f&, float);

} // namespace al
