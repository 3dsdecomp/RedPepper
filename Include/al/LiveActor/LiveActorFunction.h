#pragma once

#include "al/LiveActor/LiveActor.h"
#include <sead/prim/seadSafeString.h>

namespace alLiveActorFunction {

void calcAnimDirect(al::LiveActor* actor);

} // namespace alLiveActorFunction

namespace al {

// ActorActionKeeper
void startAction(LiveActor* actor, const char* actionName);
bool isActionEnd(const LiveActor* actor);

// Init
void initActor(LiveActor* actor, const ActorInitInfo& info);
void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* subArchiveName = nullptr);

// StageSwitch
void trySyncStageSwitchAppear(LiveActor* actor);

// Clipping
void invalidateClipping(LiveActor* actor);

} // namespace al
