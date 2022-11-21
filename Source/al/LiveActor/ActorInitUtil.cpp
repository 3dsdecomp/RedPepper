#include "al/LiveActor/ActorInitUtil.h"
#include "al/Placement/PlacementFunction.h"
#include "al/Util/StringUtil.h"

namespace al {

#pragma push
#pragma no_inline
NON_MATCHING
static void initActorImpl(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& objectName, const sead::SafeString& archivePath, const char* suffix = nullptr)
{ // placeholder
}
#pragma pop

NON_MATCHING
// SafeString construction backwards
void initActor(LiveActor* actor, const ActorInitInfo& info)
{
    const char* objectName = nullptr;
    tryGetObjectName(&objectName, info);
    initActorImpl(actor, info, objectName, StringTmp<256>("ObjectData/%s", objectName));
}

NON_MATCHING
// ???
void initActorWithArchiveName(LiveActor* actor, const ActorInitInfo& info, const sead::SafeString& archiveName, const char* suffix)
{
    initActorImpl(actor, info, archiveName.cstr(), StringTmp<256>("ObjectData/%s", archiveName.cstr()), suffix);
}

void initCreateActorNoPlacementInfo(LiveActor* actor, const ActorInitInfo& hostInfo)
{
    PlacementInfo placementInfo;
    ActorInitInfo info;
    info.initViewIdHost(&placementInfo, hostInfo);
    actor->init(info);
}

void initCreateActorWithPlacementInfo(LiveActor* actor, const ActorInitInfo& hostInfo)
{
    actor->init(hostInfo);
}

} // namespace al
