#pragma once

#include "LMS/LMS_Impl.h"
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct LMS_MessageBinary {
    LMS_Binary common;
    s32 labelsIndex;
    s32 textIndex;
    s32 attributesIndex;
    s32 styleIndex;
} LMS_MessageBinary;

LMS_MessageBinary* LMS_InitMessage(const void* data);
void LMS_CloseMessage(LMS_MessageBinary* binary);

int LMS_GetTextNum(LMS_MessageBinary* binary);
wchar_t* LMS_GetText(LMS_MessageBinary* binary, int index);
int LMS_GetTextIndexByLabel(LMS_MessageBinary* binary, const char* label);
wchar_t* LMS_GetTextByLabel(LMS_MessageBinary* binary, const char* label);

#ifdef __cplusplus
}
#endif
