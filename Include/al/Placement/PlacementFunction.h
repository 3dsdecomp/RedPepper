#pragma once

#include "al/LiveActor/ActorInitInfo.h"
#include "al/Placement/PlacementInfo.h"

namespace al {

bool isPlaced(const ActorInitInfo& info);

bool tryGetArg(bool* out, const PlacementInfo& info, const char* argName);
bool tryGetArg(float* out, const PlacementInfo& info, const char* argName);
bool tryGetArg(int* out, const PlacementInfo& info, const char* argName);

bool tryGetArg0(int* out, const PlacementInfo& info);

bool tryGetObjectName(const char** out, const al::ActorInitInfo& info);
bool tryGetObjectName(const char** out, const al::PlacementInfo& info);
bool isObjectName(const ActorInitInfo& info, const char* objectName);
bool isObjectName(const PlacementInfo& info, const char* objectName);

bool isExistRail(const ActorInitInfo& info);
bool tryGetRailIter(PlacementInfo* out, const PlacementInfo& info);

} // namespace al

namespace alPlacementFunction {

int getClippingViewId(const al::PlacementInfo& info);

} // namespace alPlacementFunction
