#pragma once

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

_Bool LMSi_MemCmp(const void*, const void*, u32 size);

typedef void* (*LMS_AllocFuncPtr)(u32 size);
typedef void (*LMS_FreeFuncPtr)(void* ptr);

void* LMSi_Malloc(u32 size);
void LMSi_Free(void* ptr);

void LMS_SetMemFuncs(LMS_AllocFuncPtr alloc_ptr, LMS_FreeFuncPtr free_ptr);

typedef struct LMS_BinaryBlock {
    const void* data;
    char type[4];
    u32 size;
    u16 unk;
} LMS_BinaryBlock;

typedef enum LMS_MessageEncoding {
    LMS_MessageEncoding_UTF8,
    LMS_MessageEncoding_UTF16,
    LMS_MessageEncoding_UTF32
} LMS_MessageEncoding;

typedef struct LMS_Binary {
    const void* data;
    u32 fileSize;
    LMS_MessageEncoding encoding;
    u16 numBlocks;
    LMS_BinaryBlock* blocks;
} LMS_Binary;

void LMSi_AnalyzeMessageBinary(LMS_Binary* binary, const char* magic);
s32 LMSi_SearchBlockByName(LMS_Binary* binary, const char* blockName);

#ifdef __cplusplus
}
#endif
