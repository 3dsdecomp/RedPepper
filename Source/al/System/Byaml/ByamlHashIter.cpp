#include "al/System/Byaml/ByamlHashIter.h"

namespace al {

#pragma O3
const ByamlHashPair* ByamlHashIter::findPair(int keyIdx) const
{
    const ByamlHashPair* table = getPairTable();
    int low = 0;

    if (mData) {
        int high = getSize();
        if (high > 0) {
            const ByamlHashPair* pair;
            int idx;
            while (true) {
                idx = (low + high) / 2;
                pair = &table[idx];
                const int res = keyIdx - (pair->getKeyIndex());
                if (res < 0)
                    high = idx;
                if (res > 0)
                    low = idx + 1;
                if (res == 0)
                    return &table[idx];
                if (high <= low)
                    break;
            }
        }
    }

    return nullptr;
}

} // namespace al
