#include "al/LiveActor/ActorActionKeeper.h"

namespace al {

#define AL_LIVEACTOR_REACTION(TYPE, NAME)               \
    void startHitReaction##TYPE(const LiveActor* actor) \
    {                                                   \
        startHitReaction(actor, NAME);                  \
    }

AL_LIVEACTOR_REACTION(Appear, "出現")
AL_LIVEACTOR_REACTION(Disappear, "消滅")
AL_LIVEACTOR_REACTION(PressDown, "踏み潰され")
AL_LIVEACTOR_REACTION(Death, "死亡")
AL_LIVEACTOR_REACTION(Hit, "命中")
AL_LIVEACTOR_REACTION(BlowHit, "吹き飛びヒット")
AL_LIVEACTOR_REACTION(Break, "破壊")
AL_LIVEACTOR_REACTION(Start, "開始")
AL_LIVEACTOR_REACTION(End, "終了")
AL_LIVEACTOR_REACTION(OnGround, "着地")
AL_LIVEACTOR_REACTION(Get, "取得")

#undef AL_LIVEACTOR_REACTION

} // namespace al
