#pragma once

#include "al/System/Byaml/ByamlData.h"
#include "types.h"

namespace al {

class ByamlStringTableIter {
    struct Header {
        const ByamlDataType type : 8;
        const u32 stringAmount : 24;
    };

    union {
        const u8* mData;
        uintptr_t mDataPtr;
        const Header* mHeader;
    };

public:
    ByamlStringTableIter(const u8* data)
        : mData(data)
    {
    }

    const u32* getAddressTable() const { return reinterpret_cast<u32*>(mDataPtr + sizeof(mDataPtr)); }

    int findStringIndex(const char* str) const;
};

} // namespace al
