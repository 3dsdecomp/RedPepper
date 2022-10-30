#include "al/LiveActor/SensorFunction.h"
#include "al/HitSensor/HitSensor.h"
#include "al/Util/StringUtil.h"

namespace alSensorFunction {

struct NameToType {
    const char* name;
    al::SensorType type;

    inline NameToType(const char* pName, al::SensorType pType)
        : name(pName)
        , type(pType)
    {
    }
};

NON_MATCHING

#define ALSENSORFUNCTION_ENTRY(TYPE) NameToType(#TYPE, al::SensorType_##TYPE),

// is somehow directly initialized, this shouldn't have a sti
const NameToType sNameToTypeLookupTable[] = {
ALSENSORFUNCTION_ENTRY(Eye)
ALSENSORFUNCTION_ENTRY(Player)
ALSENSORFUNCTION_ENTRY(Npc)
ALSENSORFUNCTION_ENTRY(Ride)
ALSENSORFUNCTION_ENTRY(Enemy)
ALSENSORFUNCTION_ENTRY(EnemyBody)
ALSENSORFUNCTION_ENTRY(EnemyAttack)
ALSENSORFUNCTION_ENTRY(Dossun)
ALSENSORFUNCTION_ENTRY(KillerMagnum)
ALSENSORFUNCTION_ENTRY(EnemySimple)
ALSENSORFUNCTION_ENTRY(MapObj)
ALSENSORFUNCTION_ENTRY(MapObjSimple)
ALSENSORFUNCTION_ENTRY(Bindable)
ALSENSORFUNCTION_ENTRY(CollisionParts)
ALSENSORFUNCTION_ENTRY(KickKoura)
ALSENSORFUNCTION_ENTRY(PlayerFireBall)
ALSENSORFUNCTION_ENTRY(WooGanSandBody)
};

#undef ALSENSORFUNCTION_ENTRY

al::SensorType findSensorTypeByName(const char* name)
{
    int size = sizeof(sNameToTypeLookupTable) / sizeof(sNameToTypeLookupTable[0]);
    al::SensorType type = al::SensorType_MapObj;
    for (int i = 0; i < size; i++) {
        if (al::isEqualString(sNameToTypeLookupTable[i].name, name)) {
            // nop before beq
            __nop();
            type = sNameToTypeLookupTable[i].type;
            break;
        }
    }
    return type;
}

} // namespace alSensorFunction
