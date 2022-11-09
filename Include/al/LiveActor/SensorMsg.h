#pragma once

#include "al/HitSensor/HitSensor.h"

namespace al {

enum SensorMsg {
    SensorMsg_FloorTouch = 27,
    SensorMsg_EnemyAttack = 45,
    SensorMsg_52 = 52, // something with the KoopaLast door
    SensorMsg_55 = 55 // something with the KoopaLast door
};

#define AL_LIVEACTOR_SENSORMSG(TYPE)                    \
    bool sendMsg##TYPE(HitSensor* to, HitSensor* from); \
    bool isMsg##TYPE(u32 msg);

AL_LIVEACTOR_SENSORMSG(FloorTouch)
AL_LIVEACTOR_SENSORMSG(EnemyAttack)
AL_LIVEACTOR_SENSORMSG(52)
AL_LIVEACTOR_SENSORMSG(55)

#undef AL_LIVEACTOR_SENSORMSG

} // namespace al
