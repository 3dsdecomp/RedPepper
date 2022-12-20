#include "al/Rail/RailRider.h"

namespace al {

NON_MATCHING // compiler completely skips _4 _10 (????????)
RailRider::RailRider(Rail* rail)
    : mRail(rail)
    , mCurrentPos(sead::Vector3f::zero)
    , mCurrentDir(sead::Vector3f::zero)
    , _1C(0.0)
    , mSpeed(0.0)
    , _24(true)
{
    _1C = mRail->normalizeLength(_1C);
    mRail->calcPosDir(&mCurrentPos, &mCurrentDir, _1C);
}

void RailRider::moveToRailStart()
{
    _1C = 0.0;
    _1C = mRail->normalizeLength(_1C);
    mRail->calcPosDir(&mCurrentPos, &mCurrentDir, _1C);
}

void RailRider::moveToNearestRail(const sead::Vector3f& r1)
{
    _1C = mRail->calcNearestRailPosCoord(r1, 20.0f);
    _1C = mRail->normalizeLength(_1C);
    mRail->calcPosDir(&mCurrentPos, &mCurrentDir, _1C);
}

} // namespace al