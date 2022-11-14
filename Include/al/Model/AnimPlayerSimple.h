#pragma once

#include "al/Model/AnimInfoTable.h"

namespace al {

class AnimPlayerSimple {
    void* _0;
    AnimInfoTable* mAnimInfoTable;
    void* _8;
    void* _C;
    void* _10;
    void* _14;
    void* _18;

public:
    bool isAnimExist(const char* animName) const;
    bool startAnim(const char* animName);
};

} // namespace al
