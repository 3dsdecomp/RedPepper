#include <nn/svc/svc.h>

namespace nn {
namespace svc {

    __asm nn::Result __attribute__((section("i._ZN2nn3svc13ControlMemoryEPjjjjjj"))) ControlMemory(u32* addr, u32 addr0, u32 addr1, u32 size, u32 op, u32 perms)
    {
        push {r0, r4}
        ldr r0, [sp, #8]
        ldr r4, [sp, #0xc]
        svc 0x1
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        pop {r4}
        bx lr
    }

    __asm void __attribute__((section("i._ZN2nn3svc11ExitProcessEv"))) ExitProcess()
    {
        svc 0x3
        bx lr
    }

    __asm void __attribute__((section("i._ZN2nn3svc11SleepThreadEy"))) SleepThread(u64 nanos)
    {
        svc 0xa
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc16ArbitrateAddressENS_6HandleEjNS_2os15ArbitrationTypeEix"))) ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns)
    {
        svc 0x22
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc17GetThreadPriorityEPiNS_6HandleE"))) GetThreadPriority(s32* prio, nn::Handle thread)
    {
        push {r0}
        svc 0xb
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc11CloseHandleENS_6HandleE"))) CloseHandle(nn::Handle handle)
    {
        svc 0x23
        bx lr
    }

    // Debug
    __asm nn::Result __attribute__((section("i._ZN2nn3svc5BreakENS_3dbg11BreakReasonE"))) Break(nn::dbg::BreakReason reason)
    {
        svc 0x3c
        bx lr
    }

} // namespace svc
} // namespace nn
