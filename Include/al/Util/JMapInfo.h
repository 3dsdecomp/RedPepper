#pragma once

#include "types.h"

struct JMapItem {
    enum Type {
        Long,
        String,
        Float,
        Long2,
        Short,
        Byte,
        StringPtr,
        Null
    };

    u32 mHash;
    u32 mMask;
    u16 mDataOffset;
    u8 mShift;
    Type mType;
};

struct JMapData {
    int _0;
    int mNumData;
    int mDataOffset;
    int _C;

    const JMapItem* getItems() { return reinterpret_cast<const JMapItem*>(reinterpret_cast<const u8*>(this) + sizeof(JMapData)); }
    const JMapItem* getItem(s32 index) { return &getItems()[index]; }

    static const JMapData* fromData(const void* data) { return static_cast<const JMapData*>(data); }
};

class JMapInfo {
    const JMapData* mData;
    const char* mName;

public:
    JMapInfo();

    bool attach(const void* data);

    int searchItemInfo(const char*);
    bool getValueFast(int, int index, u64* out);
};
