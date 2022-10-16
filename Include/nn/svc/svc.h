#pragma once

#include "nn/Handle.h"
#include "nn/Result.h"
#include "nn/dbg/types.h"
#include "nn/os/types.h"
#include "types.h"

namespace nn {
namespace svc {

    __asm void ExitProcess();
    __asm void SleepThread(u64 nanos);
    __asm nn::Result ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns);
    __asm nn::Result CloseHandle(nn::Handle handle);

    // Debug
    __asm nn::Result Break(nn::dbg::BreakReason reason);

} // namespace svc
} // namespace nn
