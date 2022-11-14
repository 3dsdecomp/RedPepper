#pragma once

#include "al/Model/AnimPlayerSimple.h"
#include "al/Model/AnimPlayerSkl.h"

class alModelCtr {
    void* _0;
    void* _4;
    void* _8;
    void* _C;
    void* _10;
    void* _14;
    void* _18;
    al::AnimPlayerSkl* mSklAnimPlayer;
    al::AnimPlayerSimple* mMtpAnimPlayer;
    al::AnimPlayerSimple* mMtsAnimPlayer;
    al::AnimPlayerSimple* mMclAnimPlayer;
    al::AnimPlayerSimple* mVisAnimPlayer;

public:
    al::AnimPlayerSkl* getSklAnimPlayer() const { return mSklAnimPlayer; }
    al::AnimPlayerSimple* getMtpAnimPlayer() const { return mMtpAnimPlayer; }
    al::AnimPlayerSimple* getMtsAnimPlayer() const { return mMtsAnimPlayer; }
    al::AnimPlayerSimple* getMclAnimPlayer() const { return mMclAnimPlayer; }
    al::AnimPlayerSimple* getVisAnimPlayer() const { return mVisAnimPlayer; }
};
