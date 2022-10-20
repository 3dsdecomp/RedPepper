#include "al/Util/StringUtil.h"

namespace al {

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
