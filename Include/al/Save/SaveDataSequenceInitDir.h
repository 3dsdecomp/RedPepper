#pragma once

#include "al/Save/SaveDataSequenceBase.h"

namespace al {

class SaveDataSequenceInitDir : public SaveDataSequenceBase {
public:
    SaveDataSequenceInitDir();

    virtual void threadFunc(const char*);
};

} // namespace al
