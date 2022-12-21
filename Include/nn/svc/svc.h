#pragma once

#include "nn/Handle.h"
#include "nn/Result.h"
#include "nn/dbg/types.h"
#include "nn/os/types.h"
#include "types.h"

namespace nn {
namespace svc {
    __asm nn::Result ControlMemory(u32 *addr, u32 addr0, u32 addr1, u32 size, u32 op, u32 perms);
    __asm void ExitProcess();
    __asm void SleepThread(u64 nanos);
    __asm nn::Result ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns);
    __asm nn::Result GetThreadPriority(s32* prio, nn::Handle thread);
    __asm nn::Result CloseHandle(nn::Handle handle);

    // Debug
    __asm nn::Result Break(nn::dbg::BreakReason reason);

} // namespace svc
} // namespace nn
