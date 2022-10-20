#include "al/LiveActor/SensorMsg.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

#define AL_LIVEACTOR_SENSORMSG(TYPE) \
    bool sendMsg##TYPE(HitSensor* to, HitSensor* from) { return to->getHost()->receiveMsg(SensorMsg_##TYPE, from, to); }
AL_LIVEACTOR_SENSORMSG(EnemyAttack)
#undef AL_LIVEACTOR_SENSORMSG

} // namepsace al
