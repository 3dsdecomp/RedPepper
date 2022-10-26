#pragma once

#include "al/LiveActor/ActorInitInfo.h"
#include "al/Placement/PlacementInfo.h"

namespace al {

bool isPlaced(const ActorInitInfo& info);

bool tryGetArg(bool* out, const PlacementInfo& info, char* argName, int defaultValue = 0);
bool tryGetArg(float* out, const PlacementInfo& info, char* argName, int defaultValue = 0);

bool tryGetObjectName(const char** out, const al::ActorInitInfo& info);
bool tryGetObjectName(const char** out, const al::PlacementInfo& info);

} // namespace al

namespace alPlacementFunction {

int getClippingViewId(const al::PlacementInfo& info);

} // namespace alPlacementFunction
