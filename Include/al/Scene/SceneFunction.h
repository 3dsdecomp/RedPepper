#pragma once

#include "al/Placement/PlacementInfo.h"
#include "al/Resource/Resource.h"
#include "al/Scene/Scene.h"

namespace al {

void initPlacementMap(Scene* scene, const Resource* stageArchive, const ActorInitInfo& infoTemplate, const char* infoIterName);

bool tryGetPlacementInfo(PlacementInfo* out, const Resource* stageArchive, const char* infoIterName);

} // namespace al
