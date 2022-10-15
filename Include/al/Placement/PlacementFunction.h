#pragma once

#include "al/Placement/PlacementInfo.h"

namespace al {

bool tryGetArg(bool* out, const PlacementInfo& info, char* argName, int defaultValue = 0);
bool tryGetArg(float* out, const PlacementInfo& info, char* argName, int defaultValue = 0);

} // namespace al

namespace alPlacementFunction {

int getClippingViewId(const al::PlacementInfo& info);

} // namespace alPlacementFunction
