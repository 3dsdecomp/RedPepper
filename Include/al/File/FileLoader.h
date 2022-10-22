#pragma once

#include <sead/filedevice/seadFileDevice.h>

namespace al {

class FileLoader {
public:
    void loadArchive(const sead::SafeString& archive, sead::FileDevice*);
};

} // namespace al
