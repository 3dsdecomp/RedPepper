#pragma once

#include "types.h"

class PlayerTrigger {
    u32 mSensorTrigger;
    u32 mCollisionTrigger;

public:
    enum ESensorTrigger {
    };

    enum ECollisionTrigger {
    };

    PlayerTrigger();
    void set(PlayerTrigger::ESensorTrigger trigger);
    void set(PlayerTrigger::ECollisionTrigger trigger);
    bool isOn(PlayerTrigger::ESensorTrigger trigger) const;
    bool isOn(PlayerTrigger::ECollisionTrigger trigger) const;
    void clearSensorTrigger();
    void clearCollisionTrigger();
};
