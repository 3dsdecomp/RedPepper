#pragma once

#include "al/Execute/ExecuteDirector.h"
#include "al/System/Byaml/ByamlIter.h"
#include "types.h"

namespace al {

class FogDirector : public IUseExecutor {
    u8* _4[0x78];
    ByamlIter _7C;

public:
    virtual void execute();

    void endInit();
};

} // namespace al
