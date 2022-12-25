#include "al/LiveActor/SensorMsg.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

#define AL_LIVEACTOR_SENSORMSG(TYPE)                                                                                     \
    bool sendMsg##TYPE(HitSensor* to, HitSensor* from) { return to->getHost()->receiveMsg(SensorMsg_##TYPE, from, to); } \
    bool isMsg##TYPE(u32 msg) { return msg == SensorMsg_##TYPE; }

AL_LIVEACTOR_SENSORMSG(9)
AL_LIVEACTOR_SENSORMSG(12)
AL_LIVEACTOR_SENSORMSG(14)
AL_LIVEACTOR_SENSORMSG(16)
AL_LIVEACTOR_SENSORMSG(17)
AL_LIVEACTOR_SENSORMSG(18)
AL_LIVEACTOR_SENSORMSG(23)
AL_LIVEACTOR_SENSORMSG(FloorTouch)
AL_LIVEACTOR_SENSORMSG(34)
AL_LIVEACTOR_SENSORMSG(37)
AL_LIVEACTOR_SENSORMSG(40)
AL_LIVEACTOR_SENSORMSG(EnemyAttack)
AL_LIVEACTOR_SENSORMSG(49)
AL_LIVEACTOR_SENSORMSG(50)
AL_LIVEACTOR_SENSORMSG(51)
AL_LIVEACTOR_SENSORMSG(52)
AL_LIVEACTOR_SENSORMSG(55)
AL_LIVEACTOR_SENSORMSG(58)

#undef AL_LIVEACTOR_SENSORMSG

} // namepsace al
