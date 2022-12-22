#pragma once

#include "types.h"
#include <nn/Handle.h>
#include <nn/Result.h>
#include <nn/dbg/dbg_Types.h>
#include <nn/os/os_Types.h>

namespace nn {
namespace svc {
    __asm nn::Result ControlMemory(u32 *addr, u32 addr0, u32 addr1, u32 size, u32 op, u32 perms);
    __asm void ExitProcess();
    __asm void SleepThread(u64 nanos);
    __asm nn::Result GetThreadPriority(s32* prio, nn::Handle thread);
    __asm nn::Result CreateMutex(nn::Handle* mutex, bool initialLocked);
    __asm nn::Result CreateEvent(nn::Handle* event, nn::os::ResetType type);
    __asm nn::Result CreateMemoryBlock(nn::Handle* memblock, u32 addr, u32 size, u32 myperms, u32 otherperms);
    __asm nn::Result CreateAddressArbiter(nn::Handle* arbiter);
    __asm nn::Result ArbitrateAddress(nn::Handle arbiter, uintptr_t addr, nn::os::ArbitrationType type, s32 value, s64 ns);
    __asm nn::Result CloseHandle(nn::Handle handle);
    __asm nn::Result WaitSynchronizationN(int* out, const nn::Handle* handles, s32 handleCount, bool waitAll, s64 timeout_ns);
    __asm nn::Result DuplicateHandle(nn::Handle* out, nn::Handle original);
    __asm nn::Result ConnectToPort(nn::Handle* port, const char* portName);
    __asm nn::Result GetProcessId(unsigned int *id, nn::Handle handle);
    __asm nn::Result GetThreadId(unsigned int *id, nn::Handle handle);
    __asm nn::Result GetResourceLimit(Handle *resourceLimit, nn::Handle handle);

    // Debug
    __asm nn::Result Break(nn::dbg::BreakReason reason);

} // namespace svc
} // namespace nn
