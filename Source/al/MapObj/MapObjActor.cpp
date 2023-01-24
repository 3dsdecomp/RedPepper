#include "al/MapObj/MapObjActor.h"

namespace al {

MapObjActor::MapObjActor(const sead::SafeString& name)
    : LiveActor(name.cstr())
{
}

} // namespace al
