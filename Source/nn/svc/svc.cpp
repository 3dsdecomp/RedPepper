#include <nn/svc/svc.h>

namespace nn {
namespace svc {

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

    __asm nn::Result __attribute__((section("i._ZN2nn3svc16ArbitrateAddressEjjNS_2os15ArbitrationTypeEix"))) ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns)
    {
        svc 0x22
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc11CloseHandleEj"))) CloseHandle(nn::Handle handle)
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
