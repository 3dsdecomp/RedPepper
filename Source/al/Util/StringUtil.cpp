#include "al/Util/StringUtil.h"
#include <cstring>

namespace al {

NON_MATCHING
// addne swapped
const char* getBaseName(const char* name)
{
    const char* baseName = std::strrchr(name, '/');
    if (baseName)
        return baseName + 1;
    return name;
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
