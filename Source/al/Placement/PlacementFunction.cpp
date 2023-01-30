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

int calcLinkChildNum(const ActorInitInfo& info)
{
    ByamlIter children;
    if (getPlacementInfo(info).tryGetIterByKey(&children, "GenerateChildren"))
        return children.getSize();
    return 0;
}

NON_MATCHING
// 4 bytes less on stack ?
bool tryGetTrans(sead::Vector3f* out, const ActorInitInfo& info)
{
    if (tryGetTrans(out, getPlacementInfo(info)))
        return true;
    return false;
}

bool tryGetTrans(sead::Vector3f* out, const PlacementInfo& info)
{
    sead::Vector3f trans;
    bool valid = info.isValid() && info.tryGetFloatByKey(&trans.x, "pos_x") && info.tryGetFloatByKey(&trans.y, "pos_y") && info.tryGetFloatByKey(&trans.z, "pos_z");
    if (!valid)
        return valid;

    out->x = trans.x;
    out->y = trans.y;
    out->z = trans.z;
    return true;
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

bool getLinksInfoByIndex(PlacementInfo* out, const ActorInitInfo& info, int index)
{
    ByamlIter links;
    if (getPlacementInfo(info).tryGetIterByKey(&links, "GenerateChildren"))
        return links.tryGetIterByIndex(out, index);
    return false;
}

const char* getLinksActorObjectName(const ActorInitInfo& info, int index)
{
    PlacementInfo placementInfo;
    getLinksInfoByIndex(&placementInfo, info, index);
    const char* objectName = nullptr;
    tryGetObjectName(&objectName, placementInfo);
    return objectName;
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
