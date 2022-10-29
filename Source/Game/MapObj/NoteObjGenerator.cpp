#include "Game/MapObj/NoteObjGenerator.h"
#include "Game/MapObj/NoteObj.h"

#pragma O3
NoteObjGenerator::NoteObjGenerator(const sead::SafeString& name)
    : MapObjActor(name)
    , mNoteObjGroup(nullptr)
    , _64(nullptr)
    , _68(20)
    , _6C(200)
    , _70(nullptr)
    , _74(180)
    , _78(false)
    , _7C(0)
    , _80(nullptr)
    , _84(false)
{
}
