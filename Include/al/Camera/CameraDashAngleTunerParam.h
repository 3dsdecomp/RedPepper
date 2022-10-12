#pragma once

#include "al/System/Byaml/ByamlIter.h"

namespace al {

class CameraDashAngleTunerParam {
    float mAddAngleMax;
    float mZoomOutOffsetMax;

public:
    CameraDashAngleTunerParam();

    void init(const ByamlIter* ticket);
};

} // namespace al
