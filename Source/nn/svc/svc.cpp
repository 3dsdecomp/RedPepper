#include "nn/svc/svc.h"

namespace nn {
namespace svc {

    __asm void ExitProcess()
    {
        svc 0x3
        bx lr
    }

    __asm void SleepThread(u64 nanos)
    {
        svc 0xa
        bx lr
    }

    __asm nn::Result ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns)
    {
        svc 0x22
        bx lr
    }

    __asm nn::Result CloseHandle(nn::Handle handle)
    {
        svc 0x23
        bx lr
    }

    // Debug
    __asm nn::Result Break(nn::dbg::BreakReason reason)
    {
        svc 0x3c
        bx lr
    }

} // namespace svc
} // namespace nn
