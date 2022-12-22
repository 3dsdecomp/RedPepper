#include <nn/fs/CTR/MPCore/detail/fs_UserFileSystem.h>

namespace nn {
namespace fs {
    namespace CTR {
        namespace MPCore {
            namespace detail {
                namespace {
                    Handle g_FileServerHandle;
                } // namespace

                static bool s_IsLatencyEmulationEnable = false;
            } // namespace detail
        } // namespace MPCore
    } // namespace CTR
} // namespace fs
} // namespace nn
