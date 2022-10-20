#pragma once

namespace al {

enum StageSwitchType {
    StageSwitchType_Appear,
    StageSwitchType_Kill,
    StageSwitchType_DeadOn,
    StageSwitchType_A,
    StageSwitchType_B
};

const char* getStageSwitchName(StageSwitchType type);

} // namespace al
