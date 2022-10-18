#include "Game/Enemy/WalkerStateChase.h"

static WalkerStateChaseParam sDefaultParam;

namespace {

NERVE_DEF(WalkerStateChase, Start)

} // namespace

#ifdef NON_MATCHING
WalkerStateChase::WalkerStateChase(al::LiveActor* host, al::LiveActor* walker, WalkerStateParam* walkParam, WalkerStateChaseParam* runParam, bool b)
    : ActorStateBase("ÉNÉäÉ{Å[í«Ç¢Ç©ÇØèÛë‘", host)
    , mWalker(walker)
    , mRunParam(runParam)
    , mWalkParam(walkParam)
    , _1C(b)
    , _20(nullptr)
{
    if (runParam == nullptr)
        mRunParam = &sDefaultParam;
    initNerve(&nrvWalkerStateChaseStart);
}

void WalkerStateChase::exeStart()
{
}
#endif
