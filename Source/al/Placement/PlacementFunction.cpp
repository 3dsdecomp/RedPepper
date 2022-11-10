#include "al/Placement/PlacementFunction.h"
#include "al/Util/StringUtil.h"

namespace al {

bool isPlaced(const ActorInitInfo& info)
{
    return info.mPlacementInfo->isValid();
}

static const char split(sObjectNameKey)[] = "name";

NON_MATCHING
// registers
bool tryGetObjectName(const char** out, const al::ActorInitInfo& info)
{
    return al::getPlacementInfo(info).tryGetStringByKey(out, sObjectNameKey);
}

bool tryGetObjectName(const char** out, const al::PlacementInfo& info)
{
    return info.tryGetStringByKey(out, sObjectNameKey);
}

NON_MATCHING // will match when tryGetObjectName matches
bool isObjectName(const ActorInitInfo& info, const char* objectName)
{
    const char* name = nullptr;
    if (tryGetObjectName(&name, info))
        return isEqualString(name, objectName);
    return false;
}

bool isObjectName(const PlacementInfo& info, const char* objectName)
{
    const char* name = nullptr;
    if (tryGetObjectName(&name, info))
        return isEqualString(name, objectName);
    return false;
}

static const char sRailKey[] = "Rail";

NON_MATCHING // ???
bool isExistRail(const ActorInitInfo& info)
{
    ByamlIter rail;
    if (al::getPlacementInfo(info).tryGetIterByKey(&rail, sRailKey))
        return rail.isTypeContainer();
    return false;
}

bool tryGetRailIter(PlacementInfo* out, const PlacementInfo& info)
{
    if (info.tryGetIterByKey(out, sRailKey))
        return out->isTypeContainer();
    return false;
}

} // namespace al

namespace alPlacementFunction {

int getClippingViewId(const al::PlacementInfo& info)
{
    int id = -1;
    if (!info.tryGetIntByKey(&id, "ViewId"))
        return -1;
    return id;
}

} // namespace alPlacementFunction
