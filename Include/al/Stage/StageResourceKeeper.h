#pragma once

#include "al/Resource/Resource.h"
#include <sead/heap/seadHeap.h>

namespace al {

class StageResourceKeeper {
    al::Resource** mResources;

public:
    StageResourceKeeper();

    void initAndLoadResource(const char* stageName, int scenario, sead::Heap* heap);

    al::Resource* getResourceDesign() const;
    al::Resource* getResourceMap() const;
    al::Resource* getResourceSound() const;
};

} // namespace al
