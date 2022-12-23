#pragma once

// Temporary file because I can't figure out what the folder is (al/A____ or al/B____)
// please replace

#include <sead/prim/seadSafeString.h>

namespace al {

template <s32 L>
class StringTmp : public sead::FixedSafeString<L> {
public:
    StringTmp(const char* format, ...)
        : sead::FixedSafeString<L>()
    {
        std::va_list args;
        va_start(args, format);
        this->formatV(format, args);
        va_end(args);
    }
};

const char* getBaseName(const char* name);
const char* createStringIfInStack(const char* str);
bool isEqualString(const char* s1, const char* s2);
bool isEqualSubString(const char* str, const char* substr);
bool isInStack(const void* ptr);

} // namespace al
