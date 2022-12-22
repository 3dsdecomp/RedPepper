#include "Game/MapObj/TransparentWall.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Stage/StageSwitchKeeper.h"

#pragma O3
TransparentWall::TransparentWall(const sead::SafeString& name)
    : MapObjActor(name)
{
}

#pragma O3 // nop
void TransparentWall::init(const al::ActorInitInfo& info)
{
    if (al::isObjectName(info, "TransparentWallMoveLimit"))
        al::initActorWithArchiveName(this, info, "TransparentWall", "MoveLimit");
    else
        al::initActor(this, info);
    al::initStageSwitchAppear(this, info);
    al::trySyncStageSwitchAppear(this);
    al::initStageSwitchKill(this, info);
    al::trySyncStageSwitchKill(this);
}

void TransparentWall::makeActorDead() { LiveActor::makeActorDead(); }
