#pragma once

#include "al/HitSensor/HitSensor.h"

namespace al {

bool isSensorName(HitSensor* sensor, const char* name);

bool isSensorPlayer(const HitSensor* sensor);
bool isSensorEnemy(const HitSensor* sensor);
bool isSensorMapObj(const HitSensor* sensor);

} // namespace al
