#include <sead/heap/seadHeapMgr.h>

namespace sead {

HeapMgr HeapMgr::sInstance;
HeapMgr::RootHeaps HeapMgr::sRootHeaps;

#pragma no_inline
HeapMgr::HeapMgr()
    : unk(nullptr)
    , mAllocFailedCallback(nullptr)
    , unk1(0)
{
}

} // namespace sead
