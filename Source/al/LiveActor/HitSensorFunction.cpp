#include "al/LiveActor/HitSensorFunction.h"
#include "al/HitSensor/HitSensor.h"
#include "al/Util/StringUtil.h"

namespace al {

bool isSensorName(HitSensor* sensor, const char* name) { return isEqualString(sensor->getName(), name); }

bool isSensorPlayer(const HitSensor* sensor) { return sensor->getType() == SensorType_Player || sensor->getType() == SensorType_PlayerFireBall; }
bool isSensorEnemy(const HitSensor* sensor) { return sensor->getType() == SensorType_Enemy || sensor->getType() == SensorType_EnemyBody || sensor->getType() == SensorType_EnemyAttack || sensor->getType() == SensorType_KillerMagnum || sensor->getType() == SensorType_Dossun; }
bool isSensorEnemyAttack(const HitSensor* sensor) { return sensor->getType() == SensorType_EnemyAttack; }
bool isSensorEnemyBody(const HitSensor* sensor) { return sensor->getType() == SensorType_EnemyBody; }
bool isSensorMapObj(const HitSensor* sensor) { return sensor->getType() == SensorType_MapObj; }

} // namespace al
