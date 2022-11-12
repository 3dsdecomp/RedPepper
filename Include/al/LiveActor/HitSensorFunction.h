#pragma once

#include "al/HitSensor/HitSensor.h"

namespace al {

bool isSensorName(HitSensor* sensor, const char* name);
bool isSensorPlayer(const al::HitSensor* sensor);

} // namespace al
