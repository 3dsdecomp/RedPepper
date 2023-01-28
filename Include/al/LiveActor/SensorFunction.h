#pragma once

#include "al/HitSensor/HitSensor.h"
#include "al/LiveActor/LiveActor.h"

namespace alSensorFunction {

al::SensorType findSensorTypeByName(const char* name);
void updateHitSensorsAll(al::LiveActor* actor);

} // namespace alSensorFunction
