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

} // namespace sead
