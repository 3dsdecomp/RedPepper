#include "al/Placement/PlacementFunction.h"

namespace al {

bool isPlaced(const ActorInitInfo& info)
{
    return info.mPlacementInfo->isValid();
}

#ifdef NON_MATCHING // idek
bool tryGetArg(bool* out, const PlacementInfo& info, char* argName, int defaultValue)
{
    int value = defaultValue;

    if (info.isValid() && info.tryGetIntByKey(&value, argName) && value != -1) {
        *out = value != 0;
        return true;
    }
    return false;
}

// registers
bool tryGetArg(float* out, const PlacementInfo& info, char* argName, int defaultValue)
{
    int value = defaultValue;

    if (info.isValid() && info.tryGetIntByKey(&value, argName) && value != -1) {
        *out = value;
        return true;
    }
    return false;
}
#endif

static const char sObjectNameKey[] = "name";

#ifdef NON_MATCHING // registers
bool tryGetObjectName(const char** out, const al::ActorInitInfo& info)
{
    return info.mPlacementInfo->tryGetStringByKey(out, sObjectNameKey);
}
#endif

bool tryGetObjectName(const char** out, const al::PlacementInfo& info)
{
    return info.tryGetStringByKey(out, sObjectNameKey);
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
