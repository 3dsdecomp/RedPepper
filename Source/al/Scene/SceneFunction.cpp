#include "al/Scene/SceneFunction.h"
#include "al/Factory/ActorFactory.h"
#include "al/LiveActor/ActorInitUtil.h"
#include "al/Placement/PlacementFunction.h"

namespace al {

NON_MATCHING
// WIP
void initPlacementMap(Scene* scene, const Resource* stageArchive, const ActorInitInfo& infoTemplate, const char* infoIterName)
{
    PlacementInfo infoIter;
    if (tryGetPlacementInfo(&infoIter, stageArchive, infoIterName) && scene->getActorFactory()) {
        int size = infoIter.getSize();
        for (int i = 0; i < size; i++) {
            PlacementInfo placementInfo;
            infoIter.tryGetIterByIndex(&placementInfo, i);
            const char* objectName = nullptr;
            if (al::tryGetObjectName(&objectName, placementInfo)) {
                al::CreateActorFuncPtr create = scene->getActorFactory()->getCreator(objectName);
                if (create) {
                    ActorInitInfo info;
                    info.initNew(&placementInfo, infoTemplate);
                    LiveActor* actor = create(objectName);
                    al::initCreateActorWithPlacementInfo(actor, info);
                }
            }
        }
    }
}

bool tryGetPlacementInfo(PlacementInfo* out, const Resource* stageArchive, const char* infoIterName)
{
    if (!stageArchive)
        return false;
    if (stageArchive) {
        const u8* stageData = stageArchive->getByml("StageData");
        ByamlIter stageDataByaml(stageData);
        ByamlIter allInfosIter;
        if (stageDataByaml.tryGetIterByKey(&allInfosIter, "AllInfos")) {
            ByamlIter unused;
            if (allInfosIter.tryGetIterByKey(out, infoIterName))
                return true;
        } else
            return false;
    }
}

} // namespace al
