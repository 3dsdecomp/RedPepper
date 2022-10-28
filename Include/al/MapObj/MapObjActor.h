#pragma once

#include "al/LiveActor/LiveActor.h"
#include <sead/prim/seadSafeString.h>

namespace al {

class MapObjActor : public al::LiveActor {
public:
    MapObjActor(const sead::SafeString& name);
};

} // namespace al
