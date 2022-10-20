#pragma once

#include "al/Stage/StageSwitchType.h"

namespace al {

const char* getStageSwitchName(StageSwitchType type)
{
    switch (type) {
    case StageSwitchType_Appear:
        return "SwitchAppear";
    case StageSwitchType_Kill:
        return "SwitchKill";
    case StageSwitchType_DeadOn:
        return "SwitchDeadOn";
    case StageSwitchType_A:
        return "SwitchA";
    case StageSwitchType_B:
        return "SwitchB";
    default:
        return "";
    }
}

} // namespace al
