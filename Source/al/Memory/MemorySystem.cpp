#include "al/Memory/MemorySystem.h"
#include "al/Resource/Resource.h"
#include "al/System/Byaml/ByamlIter.h"
#include "al/System/SystemKit.h"
#include "al/Util/StringUtil.h"

namespace al {

void MemorySystem::createSequenceHeap()
{
    mSequenceHeap = sead::ExpHeap::create(0, "SequenceHeap", nullptr, sead::ExpHeap::cHeapDirection_Forward, false);
}

extern "C" void FUN_002911e8(sead::FrameHeap** out, u32 heapSize, const char* name, u8, int); // creates FrameHeap(?)

NON_MATCHING
// WIP
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

void MemorySystem::freeAllSequenceHeap() { mSequenceHeap->freeAll(); }

sead::ExpHeap* getStationedHeap() { return alProjectInterface::getSystemKit()->getMemorySystem()->getStationedHeap(); }
sead::ExpHeap* getSequenceHeap() { return alProjectInterface::getSystemKit()->getMemorySystem()->getSequenceHeap(); }
sead::FrameHeap* getSceneResourceHeap() { return alProjectInterface::getSystemKit()->getMemorySystem()->getSceneResourceHeap(); }
sead::FrameHeap* getCourseSelectHeap() { return alProjectInterface::getSystemKit()->getMemorySystem()->getCourseSelectHeap(); }

bool isCreatedSceneResourceHeap() { return getSceneResourceHeap() != nullptr; }

} // namespace al
