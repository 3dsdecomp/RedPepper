#pragma once

#include "types.h"
#include <sead/heap/seadExpHeap.h>
#include <sead/heap/seadFrameHeap.h>
#include <sead/heap/seadHeap.h>
#include <sead/heap/seadHeapMgr.h>

namespace al {

class MemorySystem {
    sead::ExpHeap* mStationedHeap;
    sead::Heap* _4;
    sead::ExpHeap* mSequenceHeap;
    sead::FrameHeap* mSceneResourceHeap;
    sead::FrameHeap* mSceneHeap;
    sead::Heap* _14;
    sead::Heap* _18;
    sead::FrameHeap* mCourseSelectHeap;
    u8 unk1[0x20];

public:
    void createSequenceHeap();
    void createSceneHeap(const char* stageName);
    void createSceneResourceHeap(const char* stageName);

    void destroySceneHeap(bool destroyResource);
    void destroyCourseSelect();

    void freeAllSequenceHeap();

    sead::ExpHeap* getStationedHeap() const { return mStationedHeap; }
    sead::ExpHeap* getSequenceHeap() const { return mSequenceHeap; }
    sead::FrameHeap* getSceneResourceHeap() const { return mSceneResourceHeap; }
    sead::FrameHeap* getSceneHeap() const { return mSceneHeap; }
    sead::FrameHeap* getCourseSelectHeap() const { return mCourseSelectHeap; }
};

void createSequenceHeap();
void createSceneResourceHeap(const char* stageName);
void createSceneHeap(const char* stageName);
void createCourseSelectHeap();

sead::ExpHeap* getStationedHeap();
sead::ExpHeap* getSequenceHeap();
sead::FrameHeap* getSceneResourceHeap();
sead::FrameHeap* getSceneHeap();
sead::FrameHeap* getCourseSelectHeap();

void destroySceneHeap();

bool isCreatedSceneResourceHeap();

class SceneHeapSetter : public sead::ScopedCurrentHeapSetter {
    sead::Heap* _8;

public:
    SceneHeapSetter();
};

} // namespace al
