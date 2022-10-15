#pragma once

#include "al/LiveActor/LiveActor.h"
#include <sead/prim/seadSafeString.h>

class MapObjActor : public al::LiveActor {
public:
    MapObjActor(const sead::SafeString& name);
};
