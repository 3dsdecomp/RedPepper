#include "Game/MapObj/NoteObjGenerator.h"
#include "Game/MapObj/NoteObj.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveActionCtrl.h"
#include "al/Nerve/NerveFunction.h"

static alNerveFunction::NerveActionCollector sCollector;

namespace NrvNoteObjGenerator {

NERVEACTION_DEF(NoteObjGenerator, Wait)
NERVEACTION_DEF(NoteObjGenerator, Move)
NERVEACTION_DEF(NoteObjGenerator, Disappear)
NERVEACTION_DEF(NoteObjGenerator, Success)

} // namesapce NrvNoteObjGenerator

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

void NoteObjGenerator::exeSuccess()
{
    if (al::isGreaterEqualStep(this, 12))
        kill();
}
