#pragma once

namespace al {

class SaveDataSequenceBase {
public:
    SaveDataSequenceBase() { }

    virtual void threadFunc(const char*) = 0;
};

} // namespace al
