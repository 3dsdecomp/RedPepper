#include "Game/Sequence/ProductSequence.h"
#include "al/Nerve/Nerve.h"
#include "al/Nerve/NerveFunction.h"

namespace NrvProductSequence {

NERVE_DEF(ProductSequence, Title)
NERVE_DEF(ProductSequence, Opening)
NERVE_DEF(ProductSequence, CourseSelect)
NERVE_DEF(ProductSequence, Stage)
NERVE_DEF(ProductSequence, KinopioHouse)
NERVE_DEF(ProductSequence, MysteryBox)
NERVE_DEF(ProductSequence, Ending)
NERVE_DEF(ProductSequence, GameOverRoom)
NERVE_DEF(ProductSequence, Unk1)

} // namespace NrvProductSequence

#pragma O3
ProductSequence::ProductSequence(const char* name)
    : Sequence(name)
    , mStageStartParam(nullptr)
    , _14C(nullptr)
    , _150(nullptr)
    , mWipeKeeper(nullptr)
    , _158(nullptr)
    , _15C(nullptr)
    , mStateTitle(nullptr)
    , mStateOpening(nullptr)
    , mStateCourseSelect(nullptr)
    , mStateStage(nullptr)
    , mStateKinopioHouse(nullptr)
    , mStateMysteryBox(nullptr)
    , mStateEnding(nullptr)
    , mStateGameOverRoom(nullptr)
    , _180(nullptr)
    , _184(nullptr)
    , _188(nullptr)
    , _18C(nullptr)
    , _190(nullptr)
{
}

#ifdef NON_MATCHING // WIP, vtable needs this
void ProductSequence::init()
{
}
#endif

extern "C" bool FUN_0025ba7c(const char*);

void ProductSequence::exeTitle()
{
    if (al::updateNerveState(this)) {
        if (FUN_0025ba7c("オープニング実行"))
            al::setNerve(this, &NrvProductSequence::CourseSelect);
        else
            al::setNerve(this, &NrvProductSequence::Opening);
    }
}

void ProductSequence::exeOpening()
{
    if (al::updateNerveState(this))
        al::setNerve(this, &NrvProductSequence::CourseSelect);
}

void ProductSequence::exeKinopioHouse()
{
    if (al::updateNerveState(this)) {
        mStateCourseSelect->set_10(4);
        al::setNerve(this, &NrvProductSequence::CourseSelect);
    }
}

extern "C" bool FUN_0025ddd0();

void ProductSequence::exeEnding()
{
    if (al::updateNerveState(this)) {
        if (FUN_0025ddd0())
            al::setNerve(this, &NrvProductSequence::Unk1);
        else
            al::setNerve(this, &NrvProductSequence::Title);
    }
}
