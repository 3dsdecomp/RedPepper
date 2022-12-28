#pragma once

#include <sead/math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace al {

class AreaShape {
    const sead::Matrix34f* mBaseMtxPtr;
    sead::Vector3f mScale;

public:
    AreaShape();

    virtual bool isInVolume(const sead::Vector3f& trans) const = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;

    bool calcLocalPos(sead::Vector3f* out, const sead::Vector3f& trans) const;
    void setBaseMtxPtr(const sead::Matrix34f* baseMtxPtr) { mBaseMtxPtr = baseMtxPtr; }
    void setScale(const sead::Vector3f& scale);
};

} // namespace al
