#include "Game/Player/PlayerTrigger.h"

PlayerTrigger::PlayerTrigger()
    : mSensorTrigger(0)
    , mCollisionTrigger(0)
{
}

void PlayerTrigger::set(PlayerTrigger::ESensorTrigger trigger)
{
    mSensorTrigger |= 1 << trigger;
}

void PlayerTrigger::set(PlayerTrigger::ECollisionTrigger trigger)
{
    mCollisionTrigger |= 1 << trigger;
}

bool PlayerTrigger::isOn(PlayerTrigger::ESensorTrigger trigger) const
{
    return (mSensorTrigger & (1 << trigger)) != 0;
}

bool PlayerTrigger::isOn(PlayerTrigger::ECollisionTrigger trigger) const
{
    return (mCollisionTrigger & (1 << trigger)) != 0;
}

void PlayerTrigger::clearSensorTrigger()
{
    mSensorTrigger = 0;
}

void PlayerTrigger::clearCollisionTrigger()
{
    mCollisionTrigger = 0;
}
