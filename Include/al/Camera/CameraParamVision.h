#pragma once

#include "al/System/Byaml/ByamlIter.h"

namespace al {

class CameraParamVision {
    float mFovyDegree;
    float mStereovisionDistance;
    float mStereovisionDepth;
    float mNearClipDistance;
    float mFarClipDistance;

public:
    CameraParamVision();

    bool init(const ByamlIter* ticket);
};

} // namespace al
