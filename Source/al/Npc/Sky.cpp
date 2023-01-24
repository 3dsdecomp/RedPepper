#include "al/Npc/Sky.h"
#include "al/Camera/Camera.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Stage/StageSwitchKeeper.h"

namespace al {

Sky::Sky(const char* name)
    : MapObjActor(name)
    , mCameraTransPtr(nullptr)
{
}

void Sky::init(const ActorInitInfo& info)
{
    initActor(this, info);
    initStageSwitchAppear(this, info);
    mCameraTransPtr = al::getCameraPos();
    invalidateClipping(this);
    makeActorAppeared();
    trySyncStageSwitchAppear(this);
}

void Sky::calcAnim()
{
    setTrans(this, *mCameraTransPtr);
    LiveActor::calcAnim();
}

} // namespace al
