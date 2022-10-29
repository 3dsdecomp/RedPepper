#pragma once

#include "al/Rail/Rail.h"

namespace al {

class RailRider {
    Rail* mRail;
    sead::Vector3f mCurrentPos;
    sead::Vector3f mCurrentDir;
    float _1C;
    float _20;
    bool _24;

public:
    RailRider(Rail* rail);

    void moveToRailStart();

    const sead::Vector3f& getCurrentPos() { return mCurrentPos; }
    const sead::Vector3f& getCurrentDir() { return mCurrentDir; }
};

} // namespace al
