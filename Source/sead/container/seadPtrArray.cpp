#include <sead/container/seadPtrArray.h>

namespace sead {

#pragma O3 // weird
void PtrArrayImpl::setBuffer(s32 ptrNumMax, void* buf)
{
    if (ptrNumMax <= 0) {
        SEAD_ASSERT_MSG(false, "ptrNumMax[%d] must be larger than zero", ptrNumMax);
        return;
    }

    if (buf == NULL) {
        SEAD_ASSERT_MSG(false, "buf is null");
        return;
    }

    mPtrs = static_cast<void**>(buf);
    mPtrNumMax = 0;
    mPtrNum = ptrNumMax;
}

NON_MATCHING
// ip garbage
#pragma O3
void PtrArrayImpl::erase(s32 pos, s32 count)
{
    if (pos < 0) {
        SEAD_ASSERT_MSG(false, "illegal position[%d]", pos);
        return;
    }

    if (count < 0) {
        SEAD_ASSERT_MSG(false, "illegal number[%d]", count);
        return;
    }

    const s32 endPos = pos + count;
    if (endPos > mPtrNumMax) {
        SEAD_ASSERT_MSG(false, "pos[%d] + num[%d] exceed size[%d]", pos, count, mPtrNumMax);
        return;
    }

    if (mPtrNumMax > endPos)
        MemUtil::copyOverlap(mPtrs + pos, mPtrs + endPos, sizeof(void*) * (mPtrNumMax - endPos));

    mPtrNumMax -= count;
}

} // namespace sead
