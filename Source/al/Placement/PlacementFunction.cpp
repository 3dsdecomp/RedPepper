#include "al/Placement/PlacementFunction.h"

namespace alPlacementFunction {

int getClippingViewId(const al::PlacementInfo* info)
{
    int id = -1;
    if (!info->tryGetIntByKey(&id, "ViewId"))
        return -1;
    return id;
}

} // namespace alPlacementFunction
