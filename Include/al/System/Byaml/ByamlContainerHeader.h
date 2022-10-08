#pragma once

#include "al/System/Byaml/ByamlData.h"

namespace al {

class ByamlContainerHeader {
    // ByamlDataType mType : 1;
    // u32 mSize : 3;
    union {
        u32 mSize;
        u8 mType;
    };

public:
    inline ByamlDataType getType() const { return (ByamlDataType)mType; }
    inline u32 getCount() const { return mSize >> 8; } // get last 3 bytes
};

} // namespace al
