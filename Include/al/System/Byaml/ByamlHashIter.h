#pragma once

#include "al/System/Byaml/ByamlData.h"
#include "types.h"

namespace al {

class ByamlHashPair {
    union {
        ByamlDataType mType;
        u32 mKeyIndex;
    };
    u32 mValue;

public:
    ByamlDataType getType() const { return mType; }
    u32 getKeyIndex() const { return mKeyIndex & 0xFFFFFF; }
    u32 getValue() const { return mValue; }
};

class ByamlHashIter {
    struct Header {
        al::ByamlDataType type : 8;
        u32 hashAmount : 24;
    };

    union {
        const u8* mData;
        uintptr_t mDataPtr;
        const Header* mHeader;
    };

    const ByamlHashPair* getPairTable() const { return !mDataPtr ? nullptr : reinterpret_cast<ByamlHashPair*>(mDataPtr + sizeof(mDataPtr)); }
    u32 getSize() const { return mHeader->hashAmount; }

public:
    ByamlHashIter(const u8* data)
        : mData(data)
    {
    }

    const ByamlHashPair* findPair(int keyIdx) const;
    bool getDataByKey(ByamlData* out, int index) const;
};

} // namespace al
