#include "al/Npc/EffectObj.h"
#include "al/File/FileFunction.h"
#include "al/LiveActor/ActorInitUtil.h"
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

void EffectObjFunction::initActorEffectObj(EffectObj* actor, const ActorInitInfo& info, const char* objectName)
{
    if (isExistArchive(StringTmp<128>("ObjectData/%s.szs", objectName)))
        initActor(actor, info);
    else
        initActorWithArchiveName(actor, info, "EffectObj");
    initActorEffectKeeper(actor, info, objectName);
    makeMtxSRT(&actor->mBaseMtx, actor);
    trySyncStageSwitchAppear(actor);
}

} // namespace al
