#include "Game/MapObj/MapObjActor.h"

#ifdef NON_MATCHING
MapObjActor::MapObjActor(const sead::SafeString& name)
    : LiveActor(name.cstr())
{
}
#endif
