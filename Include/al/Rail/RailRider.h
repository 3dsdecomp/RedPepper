#pragma once

#include "al/Rail/Rail.h"

namespace al {

class RailRider {
    Rail* mRail;
    sead::Vector3f mCurrentPos;
    sead::Vector3f mCurrentDir;
    float _1C;
    float mSpeed;
    bool _24;

public:
    RailRider(Rail* rail);

    void moveToRailStart();
    void moveToNearestRail(const sead::Vector3f& r1);

    void setSpeed(float speed) { mSpeed = speed; }

    const sead::Vector3f& getCurrentPos() { return mCurrentPos; }
    const sead::Vector3f& getCurrentDir() { return mCurrentDir; }
};

} // namespace al
