#pragma once

#include "al/LiveActor/ActorInitInfo.h"
#include "al/Placement/PlacementInfo.h"

namespace al {

bool isPlaced(const ActorInitInfo& info);

bool tryGetArg(bool* out, const PlacementInfo& info, const char* argName);
bool tryGetArg(float* out, const PlacementInfo& info, const char* argName);
bool tryGetArg(int* out, const PlacementInfo& info, const char* argName);
bool tryGetArg0(int* out, const PlacementInfo& info);
bool tryGetArg0(float* out, const ActorInitInfo& info);
bool tryGetStringArg(const char** out, const ActorInitInfo& info, const char* argName);
bool tryGetStringArg(const char** out, const PlacementInfo& info, const char* argName);

bool tryGetObjectName(const char** out, const ActorInitInfo& info);
bool tryGetObjectName(const char** out, const PlacementInfo& info);
bool isObjectName(const ActorInitInfo& info, const char* objectName);
bool isObjectName(const PlacementInfo& info, const char* objectName);

bool isExistRail(const ActorInitInfo& info);
bool tryGetRailIter(PlacementInfo* out, const PlacementInfo& info);

bool getLinksInfoByIndex(PlacementInfo* out, const ActorInitInfo& info, int index);
const char* getLinksActorObjectName(const ActorInitInfo& info, int index);

} // namespace al

namespace alPlacementFunction {

int getClippingViewId(const al::PlacementInfo& info);

} // namespace alPlacementFunction
