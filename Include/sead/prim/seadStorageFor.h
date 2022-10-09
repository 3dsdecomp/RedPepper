#pragma once

#include "sead/basis/seadTypes.h"
#include <utility>

namespace sead {
struct InitializeTag {
};

struct ZeroInitializeTag {
};

/// Provides suitably aligned uninitialized storage for a type T.
/// Use this as a std::aligned_storage replacement that is easier to use and less error prone for
/// common cases (std::aligned_storage_t<sizeof(T), alignof(T)>).
template <typename T, bool AutoDestruct = false>
class StorageFor {
public:
    StorageFor();
};
} // namespace sead
