#pragma once

namespace nn {
namespace fs {
    namespace detail {

        class FileSystemBase {
            int* _0;

        public:
            FileSystemBase() { }
            FileSystemBase(int* a)
                : _0(a)
            {
            }
        };

        void RegisterGlobalFileSystemBase(FileSystemBase&);

    } // namespace detail
} // namespace fs
} // namespace nn
