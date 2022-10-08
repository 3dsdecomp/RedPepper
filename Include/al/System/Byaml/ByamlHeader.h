#pragma once

#include "types.h"

namespace al {

#pragma diag_suppress 368 // struct only for reading data
class ByamlHeader {
    const u16 mTag;
    const u16 mVersion;
    const int mHashKeyOffset;
    const int mStringTableOffset;
    const int mDataOffset;

public:
    u16 getTag() const { return mTag; }
    u16 getVersion() const { return mVersion; }
    u32 getHashKeyTableOffset() const { return mHashKeyOffset; }
    u32 getStringTableOffset() const { return mStringTableOffset; };
    u32 getDataOffset() const { return mDataOffset; };
};

} // namespace al

namespace alByamlLocalUtil {

bool verifiByaml(const u8* data);

} // namespace alByamlLocalUtil
