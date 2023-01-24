#include "al/Rail/RailMoveMovement.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Rail/RailFunction.h"

namespace al {

namespace NrvRailMoveMovement {

    NERVE_DEF(RailMoveMovement, Move)

} // namespace NrvRailMoveMovement

NON_MATCHING // string
RailMoveMovement::RailMoveMovement(LiveActor* host, const ActorInitInfo& info, const char* speedParamName, const char* moveTypeParamName)
    : HostStateBase(host, "ƒŒ[ƒ‹ˆÚ“®‹““®")
    , mSpeed(10)
    , mMoveType(0)
{
    tryGetArg(&mSpeed, getPlacementInfo(info), speedParamName);
    tryGetArg((int*)&mMoveType, getPlacementInfo(info), moveTypeParamName);
    if (mMoveType >= 2)
        mMoveType = 0;
    initNerve(&NrvRailMoveMovement::Move);
}

void RailMoveMovement::exeMove()
{
    if (isExistRail(mHost)) {
        if (mMoveType == 0)
            moveSyncRail(mHost, mSpeed);
        else if (mMoveType == 1)
            moveSyncRailTurn(mHost, mSpeed);
        else if (mMoveType == 2)
            moveSyncRailLoop(mHost, mSpeed);
    }
}

} // namespace al
