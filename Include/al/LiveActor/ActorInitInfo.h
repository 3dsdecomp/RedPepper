#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/System/Byaml/ByamlIter.h"
#include <sead/prim/seadSafeString.h>

namespace al {

class ActorInitInfo {
public:
    const PlacementInfo* mPlacementInfo;
    void* _4;
    void* _8;
    void* _C;
    void* _10;
    int mViewId;

    ActorInitInfo();

    void initViewIdSelf(const PlacementInfo* placement, const ActorInitInfo& base);

    friend const PlacementInfo& getPlacementInfo(const ActorInitInfo& info);
};

inline const PlacementInfo& getPlacementInfo(const ActorInitInfo& info) { return *info.mPlacementInfo; }

void initActorInitInfo(ActorInitInfo* info, const PlacementInfo* placement, const ActorInitInfo& baseInfo);

class LiveActor;

void initActor(LiveActor* actor, const ActorInitInfo& info);
void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* subArchiveName = nullptr);
void initActorWithArchiveNameNoPlacementInfo(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* subArchiveName = nullptr);
void initMapPartsActor(LiveActor* actor, const ActorInitInfo& info);

void initCreateActorNoPlacementInfo(LiveActor* actor, const ActorInitInfo& actorInitInfo);
void initCreateActorWithPlacementInfo(LiveActor* actor, const ActorInitInfo& actorInitInfo);

} // namespace al
