#include "al/Rail/RailKeeper.h"
#include "al/Placement/PlacementFunction.h"

namespace al {

RailKeeper::RailKeeper(const PlacementInfo& info)
    : mRail(nullptr)
    , mRailRider(nullptr)
{
    mRail = new Rail;
    mRail->init(info);
    mRailRider = new RailRider(mRail);
}

NON_MATCHING // mov instructions swapped (dd4d8)
    RailKeeper*
    tryCreateRailKeeper(const PlacementInfo& info)
{
    PlacementInfo railIter;
    if (tryGetRailIter(&railIter, info))
        return new RailKeeper(railIter);
    return nullptr;
}

bool RailKeeper::isExistRail() const { return mRail != nullptr; }

} // namespace al
