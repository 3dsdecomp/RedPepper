#pragma once

#include <sead/math/seadVector.h>

class PlayerProperty {
    sead::Vector3f mTrans;
    sead::Vector3f mFront;
    sead::Vector3f mUp;
    u8 _C[0x54];

public:
    void setFrontVec(const sead::Vector3f& front);
    void setUpVec(const sead::Vector3f& up);
};
