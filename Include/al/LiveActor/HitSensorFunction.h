#pragma once

#include "al/HitSensor/HitSensor.h"

namespace al {

bool isSensorName(HitSensor* sensor, const char* name);

bool isSensorPlayer(const HitSensor* sensor);
bool isSensorRide(const HitSensor* sensor);
bool isSensorEnemy(const HitSensor* sensor);
bool isSensorEnemyBody(const HitSensor* sensor);
bool isSensorEnemyAttack(const HitSensor* sensor);
bool isSensorSimple(const HitSensor* sensor);
bool isSensorMapObj(const HitSensor* sensor);

} // namespace al
