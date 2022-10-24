#include "Game/MapObj/MapObjActor.h"

#pragma O3
MapObjActor::MapObjActor(const sead::SafeString& name)
    : LiveActor(name.cstr())
{
}
