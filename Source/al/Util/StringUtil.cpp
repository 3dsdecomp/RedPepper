#include "al/Util/StringUtil.h"
#include <cstdio>
#include <cstring>

namespace al {

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

bool isEqualSubString(const char* str, const char* substr)
{
    return std::strstr(str, substr) != nullptr;
}

char* removeExtensionString(char* res, size_t size, const char* str)
{
    std::snprintf(res, size, "%s", str);
    char* token1 = std::strrchr(res, '.');
    char* token2 = std::strrchr(res, '/');
    if (token2 > token1 || ++token2 == token1 || !token1)
        return token2;
    token2 = 0;
    *token1 = 0;
    return token2;
}

} // namespace al
