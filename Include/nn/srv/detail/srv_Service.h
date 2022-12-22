#pragma once

#include <nn/Handle.h>
#include <nn/Result.h>

namespace nn {
namespace srv {
    namespace detail {

        class Service {
        public:
            static Result GetServiceHandle(Handle* out, const char* service, s32, u32);
        };

    } // namespace detail
} // namespace srv
} // namespace nn
