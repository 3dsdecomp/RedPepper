#include "al/LiveActor/HitSensorFunction.h"
#include "al/Util/StringUtil.h"

namespace al {

bool isSensorName(HitSensor* sensor, const char* name) { return isEqualString(sensor->getName(), name); }

} // namespace al
