#pragma once

#include "types.h"

namespace al {

class ByamlStringTableIter {
    union Header {
        u32 mSize;
        u8 mType;
    };

    union {
        const u8* mData;
        const Header* mHeader;
    };

public:
    ByamlStringTableIter(const u8* data)
        : mData(data)
    {
    }

    const u8* getAddressTable() const { return mData + 4; }
    u32 getSize() const { return mHeader->mSize >> 8; } // get last 3 bytes

    u32 findStringIndex(const char* string) const;
};

} // namespace al
