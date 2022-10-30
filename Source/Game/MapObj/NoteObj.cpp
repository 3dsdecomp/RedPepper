#include "Game/MapObj/NoteObj.h"
#include "Game/MapObj/CoinRotater.h"
#include "al/LiveActor/ActorPoseKeeper.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Scene/SceneObjHolder.h"

NON_MATCHING // sucky sead inlines
NoteObj::NoteObj(const char* name)
    : MapObjActor(name)
    , mStartQuat(sead::Quatf::unit)
    , _70(false)
    , _71(true)
    , _74(-1)
    , _78(sead::Vector3f::zero)
    , mGenerator(nullptr)
{
    rp::createCoinRotater();
}

NON_MATCHING
NoteObj::NoteObj(NoteObjGenerator* generator)
    : MapObjActor("音符オブジェ")
    , mStartQuat(sead::Quatf::unit)
    , _70(false)
    , _71(true)
    , _74(-1)
    , _78(sead::Vector3f::zero)
    , mGenerator(generator)
{
    rp::createCoinRotater();
}

extern "C" void FUN_00270fc4(al::LiveActor*, float, int); // MtxConnector (?)

static const char* sNoteObjArchive = "NoteObj";

NON_MATCHING
void NoteObj::init(const al::ActorInitInfo& info) // STUPID sead inlines
{
    if (al::isPlaced(info)) {
        al::initActorWithArchiveName(this, info, sNoteObjArchive);
        mStartQuat = al::getQuat(this);
        FUN_00270fc4(this, 70.0, 1);
        _78 = al::getTrans(this);
        al::invalidateClipping(this);
    }
    al::initActorWithArchiveNameNoPlacementInfo(this, info, sNoteObjArchive);
    makeActorDead();
}

NON_MATCHING // creates new path instead of conditional instructions
void NoteObj::control()
{
    if (!_71)
        al::addVelocityToGravity(this, 0.5);
    al::rotateQuatYDirDegree(this, mStartQuat, rp::getCoinRotateY());
}
