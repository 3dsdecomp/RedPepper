#pragma once

#include "al/Clipping/ClippingDirector.h"
#include "al/Collision/CollisionDirector.h"
#include "al/Effect/EffectSystem.h"
#include "al/Execute/ExecuteDirector.h"
#include "al/Fog/FogDirector.h"
#include "al/LiveActor/HitSensorDirector.h"
#include "al/LiveActor/LiveActorGroup.h"

namespace al {

class LiveActorKit {
    int mAllActorsBufferSize;
    ExecuteDirector* mExecuteDirector;
    EffectSystem* mEffectSystem;
    void* _C;
    void* _10;
    FogDirector* mFogDirector;
    void* _18;
    void* _1C;
    void* _20;
    ClippingDirector* mClippingDirector;
    CollisionDirector* mCollisionDirector;
    HitSensorDirector* mHitSensorDirector;
    void* _30;
    void* _34;
    void* _38;
    LiveActorGroup* mAllActors;
    void* _40;

public:
    LiveActorKit(int groupBufSize);

    void endInit();

    ClippingDirector* getClippingDirector() const { return mClippingDirector; }
    ExecuteDirector* getExecuteDirector() const { return mExecuteDirector; }
    LiveActorGroup* getAllActors() const { return mAllActors; }
};

void initLiveActorKit(LiveActorKit* kit);
LiveActorKit* getLiveActorKit();

} // namespace al
