#include "al/LiveActor/SensorMsg.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

#define AL_LIVEACTOR_SENSORMSG(TYPE)                                                                                     \
    bool sendMsg##TYPE(HitSensor* to, HitSensor* from) { return to->getHost()->receiveMsg(SensorMsg_##TYPE, from, to); } \
    bool isMsg##TYPE(u32 msg) { return msg == SensorMsg_##TYPE; }

AL_LIVEACTOR_SENSORMSG(FloorTouch)
AL_LIVEACTOR_SENSORMSG(EnemyAttack)
AL_LIVEACTOR_SENSORMSG(52)
AL_LIVEACTOR_SENSORMSG(55)

#undef AL_LIVEACTOR_SENSORMSG

} // namepsace al
