#pragma once

#include "al/Placement/PlacementInfo.h"
#include <sead/math/seadVector.h>

namespace al {

class Rail {
    int _0;
    int _4;
    int _8;
    int _C;
    bool mIsClosed;

public:
    Rail();

    void init(const PlacementInfo& info);

    float getTotalLength() const;
    float normalizeLength(float) const;
    void calcPosDir(sead::Vector3f*, sead::Vector3f*, float);
    float calcNearestRailPosCoord(const sead::Vector3f&, float);

    bool isClosed() const { return mIsClosed; }
};

} // namespace al
