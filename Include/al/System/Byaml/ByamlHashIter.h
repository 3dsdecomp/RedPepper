#pragma once

#include "al/System/Byaml/ByamlData.h"
#include "types.h"

namespace al {

class ByamlHashIter {
    const u8* mData;

public:
    ByamlHashIter(const u8* data)
        : mData(data)
    {
    }

    bool getDataByKey(ByamlData* out, int index);
};

} // namespace al
