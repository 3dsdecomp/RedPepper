#pragma once

#include "al/LiveActor/LiveActor.h"

namespace al {

void initActor(LiveActor* actor, const ActorInitInfo& info);
void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* suffix = nullptr);
void initActorWithArchiveNameNoPlacementInfo(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* suffix = nullptr);
void initMapPartsActor(LiveActor* actor, const ActorInitInfo& info);

void initCreateActorNoPlacementInfo(LiveActor* actor, const ActorInitInfo& hostInfo);
void initCreateActorWithPlacementInfo(LiveActor* actor, const ActorInitInfo& hostInfo);

} // namespace al
