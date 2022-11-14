#include "al/Placement/PlacementFunction.h"
#include "al/Util/StringUtil.h"

namespace al {

bool tryGetStringArg(const char** out, const PlacementInfo& info, const char* argName)
{
    const char* arg = "";
    if (info.tryGetStringByKey(&arg, argName)) {
        if (!isEqualString("-", arg)) {
            *out = arg;
            return true;
        }
        return false; // this is required to match
    }
    return false;
}

bool tryGetStringArg(const char** out, const ActorInitInfo& info, const char* argName)
{
    return tryGetStringArg(out, getPlacementInfo(info), argName);
}

bool isPlaced(const ActorInitInfo& info)
{
    return info.mPlacementInfo->isValid();
}

bool tryGetObjectName(const char** out, const al::ActorInitInfo& info)
{
    return tryGetObjectName(out, getPlacementInfo(info));
}

bool tryGetObjectName(const char** out, const al::PlacementInfo& info)
{
    return info.tryGetStringByKey(out, "name");
}

bool isObjectName(const ActorInitInfo& info, const char* objectName)
{
    return isObjectName(getPlacementInfo(info), objectName);
}

bool isObjectName(const PlacementInfo& info, const char* objectName)
{
    const char* name = nullptr;
    if (tryGetObjectName(&name, info))
        return isEqualString(name, objectName);
    return false;
}

bool isExistRail(const ActorInitInfo& info)
{
    PlacementInfo rail;
    return tryGetRailIter(&rail, getPlacementInfo(info));
}

bool tryGetRailIter(PlacementInfo* out, const PlacementInfo& info)
{
    if (info.tryGetIterByKey(out, "Rail"))
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
