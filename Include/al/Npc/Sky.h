#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/MapObj/MapObjActor.h"

namespace al {

class Sky : public MapObjActor {
    const sead::Vector3f* mCameraTransPtr;

public:
    Sky(const char* name);

    virtual void init(const ActorInitInfo& info);
    virtual void calcAnim();
};

} // namespace al
