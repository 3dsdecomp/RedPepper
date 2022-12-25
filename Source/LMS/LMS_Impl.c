#include "LMS/LMS_Impl.h"

LMS_AllocFuncPtr LMSi_sAllocFuncPtr;
LMS_FreeFuncPtr LMSi_sFreeFuncPtr;

void* LMSi_Malloc(u32 size)
{
    return LMSi_sAllocFuncPtr(size);
}

void LMSi_Free(void* ptr)
{
    LMSi_sFreeFuncPtr(ptr);
}

void LMS_SetMemFuncs(LMS_AllocFuncPtr alloc_ptr, LMS_FreeFuncPtr free_ptr)
{
    LMSi_sAllocFuncPtr = alloc_ptr;
    LMSi_sFreeFuncPtr = free_ptr;
}

NON_MATCHING
s32 LMSi_SearchBlockByName(LMS_Binary* binary, const char* blockName)
{
    u16 index = 0;
    if (binary->numBlocks > 0) {
        while (index < binary->numBlocks) {
            // nop before beq
            __nop();
            if (LMSi_MemCmp(binary->blocks[index].type, blockName, 4))
                return index;
            index++; // binary->numBlocks gets loaded before this
        }
    }
    return -1;
}
