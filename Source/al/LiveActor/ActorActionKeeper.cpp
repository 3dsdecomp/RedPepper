#include "al/LiveActor/ActorActionKeeper.h"

namespace al {

#define AL_LIVEACTOR_REACTION(TYPE, NAME)               \
    void startHitReaction##TYPE(const LiveActor* actor) \
    {                                                   \
        startHitReaction(actor, NAME);                  \
    }

AL_LIVEACTOR_REACTION(Appear, "�o��")
AL_LIVEACTOR_REACTION(Disappear, "����")
AL_LIVEACTOR_REACTION(PressDown, "���ݒׂ���")
AL_LIVEACTOR_REACTION(Death, "���S")
AL_LIVEACTOR_REACTION(Hit, "����")
AL_LIVEACTOR_REACTION(BlowHit, "������уq�b�g")
AL_LIVEACTOR_REACTION(Break, "�j��")
AL_LIVEACTOR_REACTION(Start, "�J�n")
AL_LIVEACTOR_REACTION(End, "�I��")
AL_LIVEACTOR_REACTION(OnGround, "���n")
AL_LIVEACTOR_REACTION(Get, "�擾")

#undef AL_LIVEACTOR_REACTION

} // namespace al
