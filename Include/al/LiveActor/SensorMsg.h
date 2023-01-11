#pragma once

#include "al/HitSensor/HitSensor.h"

namespace al {

enum SensorMsg {
    SensorMsg_UpperPunch = 2,
    SensorMsg_9 = 9,
    SensorMsg_PlayerStatueTouch = 12,
    SensorMsg_PlayerRollingAttack = 13,
    SensorMsg_14 = 14,
    SensorMsg_PlayerInvincibleAttack = 16,
    SensorMsg_PlayerFireBallAttack = 17,
    SensorMsg_PlayerTailAttack = 18,
    SensorMsg_PlayerKick = 19,
    SensorMsg_PlayerBoomerangAttack = 20,
    SensorMsg_PlayerBoomerangReflect = 22,
    SensorMsg_PlayerBoomerangBreak = 23,
    SensorMsg_FloorTouch = 27,
    SensorMsg_PlayerInvincibleTouch = 30,
    SensorMsg_34 = 34,
    SensorMsg_KickKouraReflect = 36,
    SensorMsg_KickKouraBreak = 37,
    SensorMsg_KickStoneAttack = 40,
    SensorMsg_41 = 41,
    SensorMsg_EnemyAttack = 45,
    SensorMsg_GororiAttack = 46,
    SensorMsg_GororiBigAttack = 47,
    SensorMsg_49 = 49,
    SensorMsg_50 = 50,
    SensorMsg_51 = 51,
    SensorMsg_52 = 52,
    SensorMsg_53 = 53,
    SensorMsg_55 = 55, // something with the KoopaLast door
    SensorMsg_58 = 58 // something with the KoopaLast door
};

#define AL_LIVEACTOR_SENSORMSG(TYPE)                    \
    bool sendMsg##TYPE(HitSensor* to, HitSensor* from); \
    bool isMsg##TYPE(u32 msg);

AL_LIVEACTOR_SENSORMSG(UpperPunch)
AL_LIVEACTOR_SENSORMSG(9)
AL_LIVEACTOR_SENSORMSG(PlayerStatueTouch)
AL_LIVEACTOR_SENSORMSG(PlayerRollingAttack)
AL_LIVEACTOR_SENSORMSG(14)
AL_LIVEACTOR_SENSORMSG(PlayerInvincibleAttack)
AL_LIVEACTOR_SENSORMSG(PlayerFireBallAttack)
AL_LIVEACTOR_SENSORMSG(PlayerTailAttack)
AL_LIVEACTOR_SENSORMSG(PlayerKick)
AL_LIVEACTOR_SENSORMSG(PlayerBoomerangAttack)
AL_LIVEACTOR_SENSORMSG(PlayerBoomerangReflect)
AL_LIVEACTOR_SENSORMSG(PlayerBoomerangBreak)
AL_LIVEACTOR_SENSORMSG(FloorTouch)
AL_LIVEACTOR_SENSORMSG(PlayerInvincibleTouch)
AL_LIVEACTOR_SENSORMSG(34)
AL_LIVEACTOR_SENSORMSG(KickKouraReflect)
AL_LIVEACTOR_SENSORMSG(KickKouraBreak)
AL_LIVEACTOR_SENSORMSG(KickStoneAttack)
AL_LIVEACTOR_SENSORMSG(41)
AL_LIVEACTOR_SENSORMSG(EnemyAttack)
AL_LIVEACTOR_SENSORMSG(GororiAttack)
AL_LIVEACTOR_SENSORMSG(GororiBigAttack)
AL_LIVEACTOR_SENSORMSG(49)
AL_LIVEACTOR_SENSORMSG(50)
AL_LIVEACTOR_SENSORMSG(51)
AL_LIVEACTOR_SENSORMSG(52)
AL_LIVEACTOR_SENSORMSG(53)
AL_LIVEACTOR_SENSORMSG(55)
AL_LIVEACTOR_SENSORMSG(58)

#undef AL_LIVEACTOR_SENSORMSG

} // namespace al
