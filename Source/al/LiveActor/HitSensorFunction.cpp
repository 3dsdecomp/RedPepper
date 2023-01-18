#include "al/LiveActor/HitSensorFunction.h"
#include "al/HitSensor/HitSensor.h"
#include "al/Util/StringUtil.h"

namespace al {

bool isSensorName(HitSensor* sensor, const char* name) { return isEqualString(sensor->getName(), name); }

bool isSensorPlayer(const HitSensor* sensor) { return sensor->getType() == SensorType_Player || sensor->getType() == SensorType_PlayerFireBall; }
bool isSensorRide(const HitSensor* sensor) { return sensor->getType() == SensorType_Ride; }
bool isSensorEnemy(const HitSensor* sensor) { return sensor->getType() == SensorType_Enemy || sensor->getType() == SensorType_EnemyBody || sensor->getType() == SensorType_EnemyAttack || sensor->getType() == SensorType_KillerMagnum || sensor->getType() == SensorType_Dossun; }
bool isSensorEnemyBody(const HitSensor* sensor) { return sensor->getType() == SensorType_EnemyBody; }
bool isSensorEnemyAttack(const HitSensor* sensor) { return sensor->getType() == SensorType_EnemyAttack; }
bool isSensorSimple(const HitSensor* sensor) { return sensor->getType() == SensorType_EnemySimple || sensor->getType() == SensorType_MapObjSimple || sensor->getType() == SensorType_Bindable; }
bool isSensorMapObj(const HitSensor* sensor) { return sensor->getType() == SensorType_MapObj; }

} // namespace al
