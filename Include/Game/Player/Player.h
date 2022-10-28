#pragma once

#include "Game/Player/PlayerProperty.h"

class Player {
    PlayerProperty* mPlayerProperty;
    u8 _4[0xf4];

public:
    PlayerProperty* getProperty() { return mPlayerProperty; }
};
