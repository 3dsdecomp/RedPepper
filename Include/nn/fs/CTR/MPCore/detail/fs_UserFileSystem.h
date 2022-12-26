#pragma once

#include <nn/Handle.h>

namespace nn {
namespace fs {
    namespace CTR {
        namespace MPCore {
            namespace detail {
                class UserFileSystem {
                public:
                    static void Initialize(Handle handle);
                };
            } // namespace detail
        } // namespace MPCore
    } // namespace CTR

    void ForceDisableLatencyEmulation();
} // namespace fs
} // namespace nn
