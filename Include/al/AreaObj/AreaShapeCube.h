#pragma once

#include <al/AreaObj/AreaShape.h>

namespace al {

class AreaShapeCube : public AreaShape {
    bool mIsCubeBase;

public:
    AreaShapeCube(bool isCubeBase);

    virtual bool isInVolume(const sead::Vector3f& trans) const;
    // virtual void v2();
};

} // namespace al
