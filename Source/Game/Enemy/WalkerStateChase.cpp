#include "Game/Enemy/WalkerStateChase.h"

static WalkerStateChaseParam sDefaultParam(false, false, 2.0, 65, 150, 4.0, 15, "Run", "Wait");

namespace NrvWalkerStateChase {

NERVE_DEF(WalkerStateChase, Start)

} // namespace

#ifdef NON_MATCHING
#pragma O3
WalkerStateChase::WalkerStateChase(al::LiveActor* host, sead::Vector3f* frontPtr, const WalkerStateParam* walkParam, const WalkerStateChaseParam* runParam, bool b)
    : ActorStateBase("ÉNÉäÉ{Å[í«Ç¢Ç©ÇØèÛë‘", host)
    , mFrontPtr(frontPtr)
    , mRunParam(runParam)
    , mWalkParam(walkParam)
    , _1C(b)
    , _20(nullptr)
{
    if (runParam == nullptr)
        mRunParam = &sDefaultParam;
    initNerve(&NrvWalkerStateChase::Start);
}

void WalkerStateChase::exeStart()
{
}
#endif
