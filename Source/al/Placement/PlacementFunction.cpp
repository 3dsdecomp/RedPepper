#include "al/Placement/PlacementFunction.h"

namespace al {

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
