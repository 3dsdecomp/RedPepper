#pragma once

namespace nn {
namespace dbg {

    enum BreakReason {
        BreakReason_PANIC,
        BreakReason_ASSERT,
        BreakReason_USER,
        BreakReason_LOAD_RO,
        BreakReason_UNLOAD_RO,
    };

} // namespace dbg
} // namespace nn
