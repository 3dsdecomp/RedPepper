#include "al/Stage/StageResourceKeeper.h"

namespace al {

StageResourceKeeper::StageResourceKeeper()
    : mResources(nullptr)
{
}

al::Resource* StageResourceKeeper::getResourceDesign() const { return mResources[1]; }
al::Resource* StageResourceKeeper::getResourceMap() const { return mResources[0]; }
al::Resource* StageResourceKeeper::getResourceSound() const { return mResources[2]; }

} // namespace al
