#pragma once

#include "al/Layout/LayoutInitInfo.h"

namespace al {
class WipeSimpleTopBottom;
} // namespace al

class StageWipeKeeper {
public:
    class al::WipeSimpleTopBottom* mWipes[7];
    void* unk;

    StageWipeKeeper(const al::LayoutInitInfo& info);
};
