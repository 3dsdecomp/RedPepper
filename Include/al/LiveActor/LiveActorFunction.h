#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/Nerve/NerveActionCtrl.h"
#include <sead/prim/seadSafeString.h>

namespace alLiveActorFunction {

void calcAnimDirect(al::LiveActor* actor);

} // namespace alLiveActorFunction

namespace al {

// ActorActionKeeper
void startAction(LiveActor* actor, const char* actionName);
bool tryStartAction(LiveActor* actor, const char* actionName);
bool isActionEnd(const LiveActor* actor);
void startNerveAction(LiveActor* actor, const char* actionName);

// Init
void initActor(LiveActor* actor, const ActorInitInfo& info);
void initMapPartsActor(LiveActor* actor, const ActorInitInfo& info);
void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* subArchiveName = nullptr);
void initActorWithArchiveNameNoPlacementInfo(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* subArchiveName = nullptr);

void initCreateActorNoPlacementInfo(LiveActor* actor, const ActorInitInfo& actorInitInfo);
void initCreateActorWithPlacementInfo(LiveActor* actor, const ActorInitInfo& actorInitInfo);

// ActorPoseKeeper
void initActorSRTAndPoseTRSV(LiveActor* actor, const ActorInitInfo& info);

// ModelKeeper
void showModel(LiveActor* actor);
void hideModel(LiveActor* actor);

void calcJointPos(sead::Vector3f* out, const LiveActor* actor, const char* jointName);

// EffectKeeper
void initActorEffectKeeper(LiveActor* actor, const ActorInitInfo& info, const char*);

// Nerve
void initNerve(LiveActor* actor, const Nerve* nerve, int step = 0); // may be al::LiveActor::initNerve
void initNerveAction(LiveActor* actor, const char* name, alNerveFunction::NerveActionCollector* collector, int maxNerveStates = 0);

// StageSwitchKeeper
void trySyncStageSwitchAppear(LiveActor* actor);

// Clipping
void invalidateClipping(LiveActor* actor);
void validateClipping(LiveActor* actor);

// Collider
void invalidateCollisionPartsBySystem(LiveActor* actor);
void validateCollisionPartsBySystem(LiveActor* actor);

// Math
void rotateQuatXDirDegree(LiveActor* actor, const sead::Quatf& from, float degrees);
void rotateQuatYDirDegree(LiveActor* actor, const sead::Quatf& from, float degrees);
void rotateQuatZDirDegree(LiveActor* actor, const sead::Quatf& from, float degrees);

} // namespace al
