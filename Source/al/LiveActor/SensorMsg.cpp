#include "al/LiveActor/SensorMsg.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

#define AL_LIVEACTOR_SENSORMSG(TYPE)                                                                                     \
    bool sendMsg##TYPE(HitSensor* to, HitSensor* from) { return to->getHost()->receiveMsg(SensorMsg_##TYPE, from, to); } \
    bool isMsg##TYPE(u32 msg) { return msg == SensorMsg_##TYPE; }

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
AL_LIVEACTOR_SENSORMSG(EnemyAttack)
AL_LIVEACTOR_SENSORMSG(GororiAttack)
AL_LIVEACTOR_SENSORMSG(GororiBigAttack)
AL_LIVEACTOR_SENSORMSG(49)
AL_LIVEACTOR_SENSORMSG(50)
AL_LIVEACTOR_SENSORMSG(51)
AL_LIVEACTOR_SENSORMSG(52)
AL_LIVEACTOR_SENSORMSG(55)
AL_LIVEACTOR_SENSORMSG(58)

#undef AL_LIVEACTOR_SENSORMSG

} // namepsace al
