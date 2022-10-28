#pragma once

#include "al/Camera/CameraDashAngleTunerParam.h"
#include "al/Camera/CameraParamVision.h"
#include "al/Camera/CameraRotatorParam.h"
#include "al/System/Byaml/ByamlIter.h"
#include <sead/math/seadVector.h>

namespace al {

class Camera {
    const char* const mName;

protected:
    sead::Vector3f _8;
    sead::Vector3f mPos;
    sead::Vector3f mTarget;
    sead::Vector3f _2C;
    int mInterpoleFrame;
    CameraParamVision* mVisionParam;
    CameraDashAngleTunerParam* mDashAngleTunerParam;
    u8* _44;
    CameraRotatorParam* mRotatorParam;

public:
    Camera(const char* name);

    virtual void load(const al::ByamlIter* ticket);
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void calc();
    virtual void v7();
};

const sead::Vector3f* getCameraPos();

} // namespace al
