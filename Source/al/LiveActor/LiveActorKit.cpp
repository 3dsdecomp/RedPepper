#include "al/LiveActor/LiveActorKit.h"
#include "Game/System/Application.h"
#include "al/Functor/FunctorV0F.h"

namespace al {

LiveActorKit::LiveActorKit(int groupBufSize)
    : mAllActorsBufferSize(groupBufSize)
    , mExecuteDirector(nullptr)
    , mEffectSystem(nullptr)
    , _C(nullptr)
    , _10(nullptr)
    , mFogDirector(nullptr)
    , _18(nullptr)
    , _1C(nullptr)
    , _20(nullptr)
    , mClippingDirector(nullptr)
    , mCollisionDirector(nullptr)
    , mHitSensorDirector(nullptr)
    , _30(nullptr)
    , _34(nullptr)
    , _38(nullptr)
    , mAllActors(nullptr)
    , _40(nullptr)
{
    mAllActors = new LiveActorGroup("全てのアクター", mAllActorsBufferSize);
}

extern "C" void FUN_00240350();
extern "C" void FUN_001e8a64();

extern "C" void FUN_001cc9b0(const char*, const FunctorV0F&);

NON_MATCHING
// loop is weird
void LiveActorKit::endInit()
{
    FUN_001cc9b0("プレイヤー影ボリュームのフィル", FunctorV0F(FUN_00240350));
    FUN_001cc9b0("影ボリュームのフィル", FunctorV0F(FUN_001e8a64));
    mEffectSystem->startScene();
    mExecuteDirector->createExecutorListTable();
    mCollisionDirector->endInit();
    mFogDirector->endInit();
    mClippingDirector->endInit();
    sead::PtrArray<LiveActor> actors = mAllActors->getArray<LiveActor>();
    for (int i = 0; i < actors.size(); i++)
        actors[i]->initAfterPlacement();
}

void initLiveActorKit(LiveActorKit* kit)
{
    al::getApplication()->mLiveActorKit = kit;
}

LiveActorKit* getLiveActorKit()
{
    return al::getApplication()->mLiveActorKit;
}

} // namespace al
