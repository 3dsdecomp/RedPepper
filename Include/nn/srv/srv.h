#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>

namespace nn {
namespace srv {

    Result GetServiceHandle(Handle* out, const char* service, s32, u32);

} // namespace srv
} // namespace nn
