#pragma once

namespace nn {
namespace os {

    /// Arbitration modes.
    enum ArbitrationType {
        ArbitrationType_SIGNAL = 0, ///< Signal #value threads for wake-up.
        ArbitrationType_WAIT_IF_LESS_THAN = 1, ///< If the memory at the address is strictly lower than #value, then wait for signal.
        ArbitrationType_DECREMENT_AND_WAIT_IF_LESS_THAN = 2, ///< If the memory at the address is strictly lower than #value, then decrement it and wait for signal.
        ArbitrationType_WAIT_IF_LESS_THAN_TIMEOUT = 3, ///< If the memory at the address is strictly lower than #value, then wait for signal or timeout.
        ArbitrationType_DECREMENT_AND_WAIT_IF_LESS_THAN_TIMEOUT = 4, ///< If the memory at the address is strictly lower than #value, then decrement it and wait for signal or timeout.
    };

} // namespace os
} // namespace nn
