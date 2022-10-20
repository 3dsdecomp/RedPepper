#pragma once

#include "al/HitSensor/HitSensor.h"

namespace al {

enum SensorMsg {
    SensorMsg_EnemyAttack = 45
};

#define AL_LIVEACTOR_SENSORMSG(TYPE) bool sendMsg##TYPE(HitSensor* to, HitSensor* from)
AL_LIVEACTOR_SENSORMSG(EnemyAttack);
#undef AL_LIVEACTOR_SENSORMSG

} // namespace al
