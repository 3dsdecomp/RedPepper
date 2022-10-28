#include "al/Scene/SceneFunction.h"

namespace al {

static const char* sStageDataByamlName = "StageData";
static const char* sAllInfosKey = "AllInfos";

#ifdef NON_MATCHING // SafeString construction is backwards, extra return path
bool tryGetPlacementInfo(PlacementInfo* out, const Resource* stageArchive, const char* infoIterName)
{
    if (stageArchive) {
        const u8* stageData = stageArchive->getByml(sStageDataByamlName);
        ByamlIter stageDataByaml(stageData);
        ByamlIter allInfos;
        if (stageDataByaml.tryGetIterByKey(&allInfos, sAllInfosKey)) {
            ByamlIter unused;
            allInfos.tryGetIterByKey(out, infoIterName);
            return true;
        }
    }
    return false;
}
#endif

} // namespace al
