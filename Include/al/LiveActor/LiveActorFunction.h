#pragma once

#include "al/LiveActor/LiveActor.h"
#include <sead/prim/seadSafeString.h>

namespace al {

void startAction(LiveActor* actor, const char* actionName);
bool isActionEnd(const LiveActor* actor);

void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* subArchiveName = nullptr);

} // namespace al
