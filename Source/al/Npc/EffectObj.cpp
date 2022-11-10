#include "al/Npc/EffectObj.h"
#include "al/File/FileFunction.h"
#include "al/LiveActor/LiveActorFunction.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Se/SeFunction.h"
#include "al/Util/StringUtil.h"

namespace al {

NON_MATCHING // something with mBaseMtx
EffectObj::EffectObj(const sead::SafeString& name)
    : MapObjActor(name)
    , mBaseMtx(sead::Matrix34f::ident)
{
}

NON_MATCHING
// same problem as initActorEffectObj
void EffectObj::init(const ActorInitInfo& info)
{
    const char* objectName = nullptr;
    tryGetObjectName(&objectName, info);
    EffectObjFunction::initActorEffectObj(this, info, objectName);
}

void EffectObj::makeActorAppeared()
{
    LiveActor::makeActorAppeared();
    makeMtxSRT(&mBaseMtx, this);
    emitEffect(this, "Wait", nullptr);
}

void EffectObj::kill()
{
    tryEmitEffect(this, "Wait");
    LiveActor::kill();
}

const sead::Matrix34f* EffectObj::getBaseMtx() const { return &mBaseMtx; }

void EffectObj::control()
{
    makeMtxSRT(&mBaseMtx, this);
    tryStartSe(this, "Wait", 2);
}

#pragma inline
NON_MATCHING
// nop missing (O3), does unnecessary move for isExistArchive arg
void EffectObjFunction::initActorEffectObj(EffectObj* actor, const ActorInitInfo& info, const char* objectName)
{
    StringTmp<128> path = StringTmp<128>("ObjectData/%s.szs", objectName);
    if (isExistArchive(path))
        initActor(actor, info);
    else
        initActorWithArchiveName(actor, info, "EffectObj");
    initActorEffectKeeper(actor, info, objectName);
    makeMtxSRT(&actor->mBaseMtx, actor);
    trySyncStageSwitchAppear(actor);
}

} // namespace al
