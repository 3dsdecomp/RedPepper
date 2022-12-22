#include <cstring>
#include <nn/err/CTR/err_Api.h>
#include <nn/fs/CTR/MPCore/detail/fs_UserFileSystem.h>
#include <nn/fs/detail/fs_FileSystemBase.h>
#include <nn/fs/fs_Api.h>
#include <nn/srv/srv_Api.h>

namespace nn {
namespace fs {

    namespace {
        nn::Handle s_FileServerSession;

        int /* ? */ s_FileSystemBaseImpl;
        detail::FileSystemBase s_FileSystemBase;
    } // namespace

} // namespace fs
} // namespace nn
