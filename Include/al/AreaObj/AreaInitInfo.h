#pragma once

#include "al/Placement/PlacementInfo.h"

namespace al {

class AreaInitInfo {
    PlacementInfo mPlacementInfo;
    // ?
public:
    PlacementInfo& getPlacementInfo() { return mPlacementInfo; }
};

} // namespace al
