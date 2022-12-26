#include <nn/fs/CTR/MPCore/detail/fs_UserFileSystem.h>

namespace nn {
namespace fs {
    namespace CTR {
        namespace MPCore {
            namespace detail {
                namespace {
                    Handle g_FileServerHandle;
                } // namespace

                static bool s_Something = true;
                static bool s_IsLatencyEmulationEnable = false;
            } // namespace detail
        } // namespace MPCore
    } // namespace CTR

    void ForceDisableLatencyEmulation()
    {
        CTR::MPCore::detail::s_IsLatencyEmulationEnable = false;
    }

} // namespace fs
} // namespace nn
