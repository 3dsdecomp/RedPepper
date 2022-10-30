#include "al/Memory/MemorySystem.h"
#include "al/Resource/Resource.h"
#include "al/System/Byaml/ByamlIter.h"
#include "al/Util/StringUtil.h"

namespace al {

extern "C" void FUN_002911e8(sead::Heap** out, u32 heapSize, const char* name, u8, int); // creates FrameHeap(?)

NON_MATCHING // WIP
void MemorySystem::createSceneResourceHeap(const char* stageName)
{
    int heapSize;
    if (stageName) {
        al::Resource* gameSystemDataTable = al::findOrCreateResource("ObjectData/GameSystemDataTable");
        const u8* tableData = gameSystemDataTable->getByml("HeapSizeDefine");
        al::ByamlIter table(tableData);
        for (int i = 0; i < table.getSize(); i++) {
            al::ByamlIter entry;
            table.tryGetIterByIndex(&entry, i);
            const char* stage = nullptr;
            entry.tryGetStringByKey(&stage, "Stage");
            if (al::isEqualString(stage, stageName)) {
                float resourceMb = 0;
                entry.tryGetFloatByKey(&resourceMb, "SceneResource");
                heapSize = resourceMb * 1024 * 1024;
                break;
            }
        }
    } else
        heapSize = 8 * 1024 * 1024; // 8 MB
    FUN_002911e8(&mSceneResourceHeap, heapSize, "SceneHeapResource", 0, 1);
}

} // namespace al
