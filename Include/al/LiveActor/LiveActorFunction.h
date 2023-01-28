#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/Nerve/NerveActionCtrl.h"
#include <sead/prim/seadSafeString.h>

class alLiveActorFunction {
public:
    static void calcAnimDirect(al::LiveActor* actor);
};

namespace al {

// ActorPoseKeeper
void initActorSRTAndPoseTRSV(LiveActor* actor, const ActorInitInfo& info);

// ActorActionKeeper
void startAction(LiveActor* actor, const char* actionName);
bool tryStartAction(LiveActor* actor, const char* actionName);
bool isActionEnd(const LiveActor* actor);
void startNerveAction(LiveActor* actor, const char* actionName);
bool tryStartSklAnimIfExist(LiveActor* actor, const char* animName);
bool tryStartMtsAnimIfExist(LiveActor* actor, const char* animName);
bool tryStartMtpAnimIfExist(LiveActor* actor, const char* animName);
bool tryStartMclAnimIfExist(LiveActor* actor, const char* animName);
bool tryStartVisAnimIfExist(LiveActor* actor, const char* animName);

void setBaseMtxAndCalcAnim(LiveActor* actor, const sead::Matrix34f&, const sead::Vector3f&);

// ??

bool isClipped(const LiveActor* actor);
bool isInvalidClipping(const LiveActor* actor);
bool isDead(const LiveActor* actor);
bool isAlive(const LiveActor* actor);

void onCollide(LiveActor* actor);
void offCollide(LiveActor* actor);
void onDrawClipping(LiveActor* actor);

void invalidateClipping(LiveActor* actor);
void validateClipping(LiveActor* actor);

// CollisionParts
void invalidateCollisionPartsBySystem(LiveActor* actor);
void validateCollisionPartsBySystem(LiveActor* actor);

// ModelKeeper
void showModel(LiveActor* actor);
void hideModel(LiveActor* actor);
void showShadow(LiveActor* actor);
void hideShadow(LiveActor* actor);

const sead::Matrix34f* getJointMtxPtr(const LiveActor* actor, const char* jointName);
void calcJointPos(sead::Vector3f* out, const LiveActor* actor, const char* jointName);

// NerveKeeper
void initNerve(LiveActor* actor, const Nerve* nerve, int maxNerveStates = 0); // may be al::LiveActor::initNerve
void initNerveAction(LiveActor* actor, const char* name, alNerveFunction::NerveActionCollector* collector, int maxNerveStates = 0);

// HitSensorKeeper
HitSensor* getHitSensor(const LiveActor* actor, const char* name);
float getSensorRadius(const LiveActor* actor, const char* sensorName);

// EffectKeeper
void initActorEffectKeeper(LiveActor* actor, const ActorInitInfo& info, const char*);

// StageSwitchKeeper
void trySyncStageSwitchAppear(LiveActor* actor);
void trySyncStageSwitchKill(LiveActor* actor);

// Math
void rotateQuatXDirDegree(LiveActor* actor, const sead::Quatf& from, float degrees);
void rotateQuatYDirDegree(LiveActor* actor, const sead::Quatf& from, float degrees);
void rotateQuatZDirDegree(LiveActor* actor, const sead::Quatf& from, float degrees);

void calcQuatSide(sead::Vector3f* out, const LiveActor* from);

} // namespace al
