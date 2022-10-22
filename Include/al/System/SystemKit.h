#pragma once

#include "al/File/FileLoader.h"
#include <sead/heap/seadHeap.h>

namespace al {

class SystemKit {
    sead::Heap* mHeap;
    FileLoader* mFileLoader;

public:
    inline FileLoader* getFileLoader() { return mFileLoader; }
};

} // namespace al

namespace alProjectInterface {

al::SystemKit* getSystemKit();

} // namespace alProjectInterface
