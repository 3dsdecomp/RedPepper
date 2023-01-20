#include <nn/svc/svc_Api.h>

namespace nn {
namespace svc {

    // clang-format off

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

    __asm void __attribute__((section("i._ZN2nn3svc12CreateThreadEPNS_6HandleEPFvjEjjii"))) CreateThread(nn::Handle* handle, void (*func)(u32), u32 arg, u32 stackTop, s32 prio, s32 processorId)
    {
        push {r0, r4}
        ldr r0, [sp, #8]
        ldr r4, [sp, #0xc]
        svc 0x8
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        pop {r4}
        bx lr
    }

    __asm void __attribute__((section("i._ZN2nn3svc11SleepThreadEy"))) SleepThread(u64 nanos)
    {
        svc 0xa
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

    __asm nn::Result __attribute__((section("i._ZN2nn3svc11CreateMutexEPNS_6HandleEb"))) CreateMutex(nn::Handle* mutex, bool initialLocked)
    {
        push {r0}
        svc 0x13
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc11CreateEventEPNS_6HandleENS_2os9ResetTypeE"))) CreateEvent(nn::Handle* event, nn::os::ResetType type)
    {
        push {r0}
        svc 0x17
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc17CreateMemoryBlockEPNS_6HandleEjjjj"))) CreateMemoryBlock(nn::Handle* memblock, u32 addr, u32 size, u32 myperms, u32 otherperms)
    {
        push {r0}
        ldr r0, [sp, #4]
        svc 0x1e
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc20CreateAddressArbiterEPNS_6HandleE"))) CreateAddressArbiter(nn::Handle* arbiter)
    {
        push {r0}
        svc 0x21
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc16ArbitrateAddressENS_6HandleEjNS_2os15ArbitrationTypeEix"))) ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns)
    {
        svc 0x22
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc11CloseHandleENS_6HandleE"))) CloseHandle(nn::Handle handle)
    {
        svc 0x23
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc20WaitSynchronizationNEPiPKNS_6HandleEibx"))) WaitSynchronizationN(int* out, const nn::Handle* handles, s32 handleCount, bool waitAll, s64 timeout_ns)
    {
        push {r0, r4}
        ldr r0, [sp, #4]
        ldr r4, [sp, #0xC]
        svc 0x25
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        pop {r4}
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc15DuplicateHandleEPNS_6HandleES1_"))) DuplicateHandle(nn::Handle* out, nn::Handle original)
    {
        push {r0}
        svc 0x27
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc13ConnectToPortEPNS_6HandleEPKc"))) ConnectToPort(nn::Handle* port, const char* portName)
    {
        push {r0}
        svc 0x2D
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc12GetProcessIdEPjNS_6HandleE"))) GetProcessId(unsigned int *id, nn::Handle handle)
    {
        push {r0}
        svc 0x35
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc11GetThreadIdEPjNS_6HandleE"))) GetThreadId(unsigned int *id, nn::Handle handle)
    {
        push {r0}
        svc 0x37
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    __asm nn::Result __attribute__((section("i._ZN2nn3svc16GetResourceLimitEPNS_6HandleES1_"))) GetResourceLimit(Handle *resourceLimit, nn::Handle handle)
    {
        push {r0}
        svc 0x38
        ldr r2, [sp]
        str r1, [r2]
        add sp, sp, #4
        bx lr
    }

    // Debug
    __asm nn::Result __attribute__((section("i._ZN2nn3svc5BreakENS_3dbg11BreakReasonE"))) Break(nn::dbg::BreakReason reason)
    {
        svc 0x3c
        bx lr
    }

    // clang-format on

} // namespace svc
} // namespace nn
