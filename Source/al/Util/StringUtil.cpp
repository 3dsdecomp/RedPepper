#include "al/Util/StringUtil.h"
#include <cstdio>
#include <cstring>

namespace al {

NON_MATCHING
// addne swapped
const char* getBaseName(const char* name)
{
    const char* baseName = std::strrchr(name, '/');
    return !baseName ? name : baseName + 1;
}

const char* createStringIfInStack(const char* str)
{
    if (isInStack(str)) {
        std::size_t size = std::strlen(str) + 1;
        char* newString = new char[size];
        std::snprintf(newString, size, "%s", str);
        return newString;
    }
    return str;
}

bool isEqualString(const char* s1, const char* s2)
{
    char val2 = *s2++, val1 = *s1++;
    while (val1 == val2) {
        if (val1 == '\0')
            return true;
        val1 = *s1++;
        val2 = *s2++;
    }
    return false;
}

} // namespace al
