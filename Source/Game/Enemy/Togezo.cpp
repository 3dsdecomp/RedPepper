#include "Game/Enemy/Togezo.h"
#include "Game/Enemy/WalkerStateParam.h"
#include "al/LiveActor/LiveActor.h"
#include "al/LiveActor/LiveActorFunction.h"

namespace {

NERVE_DEF(Togezo, Wander);

} // namespace

static WalkerStateParam sTogezoWalkerStateParam(4.0, 0.98, 0.85, 250.0, 700.0, 180.0, 70.0, 150.0);

#ifdef NON_MATCHING
Togezo::Togezo(const sead::SafeString& name)
    : MapObjActor(name)
    , _60(nullptr)
    , _64(nullptr)
    , _68(nullptr)
{
}

// inits al::Collider->_4
extern "C" void FUN_0027a1a0(al::LiveActor* actor, const char*);
extern "C" void FUN_0027cf20(al::LiveActor* actor, const al::ActorInitInfo& info, int);

// WIP
void Togezo::init(const al::ActorInitInfo& info)
{
    al::initActorWithArchiveName(this, info, "Togezo");
    FUN_0027a1a0(this, "移動制限");
    FUN_0027cf20(this, info, 1);
    al::initNerve(this, &nrvTogezoWander, 3);
}

void Togezo::exeWander() { }
#endif
