#pragma once

#include <sead/basis/seadTypes.h>
#include <sead/container/seadListImpl.h>
#include <sead/container/seadOffsetList.h>

namespace sead {
class MemBlock {
public:
    static MemBlock* FindManageArea(void* ptr);

    static u32 getOffset() { return offsetof(MemBlock, mListNode); }

protected:
    ListNode mListNode;
    u16 mHeapCheckTag;
    u16 mOffset;
    size_t mSize;
};

typedef OffsetList<MemBlock> MemBlockList;
} // namespace sead
