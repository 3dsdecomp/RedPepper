#include "al/MapObj/MapObjActor.h"

namespace al {

#pragma O3
MapObjActor::MapObjActor(const sead::SafeString& name)
    : LiveActor(name.cstr())
{
}

} // namespace al
