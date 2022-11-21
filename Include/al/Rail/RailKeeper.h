#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/Rail/Rail.h"
#include "al/Rail/RailRider.h"

namespace al {

class RailKeeper {
    Rail* mRail;
    RailRider* mRailRider;

    RailKeeper(const PlacementInfo& info);

public:
    Rail* getRail() { return mRail; }
    RailRider* getRailRider() { return mRailRider; }

    bool isExistRail() const;

    friend RailKeeper* tryCreateRailKeeper(const PlacementInfo& info);
};

RailKeeper* tryCreateRailKeeper(const PlacementInfo& info);

} // namespace al
