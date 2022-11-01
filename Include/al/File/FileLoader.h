#pragma once

#include <sead/filedevice/seadFileDevice.h>

namespace al {

class FileLoader {
    u8 _0[0x30];

public:
    FileLoader(int);

    void loadArchive(const sead::SafeString& archive, sead::FileDevice*);
};

} // namespace al
