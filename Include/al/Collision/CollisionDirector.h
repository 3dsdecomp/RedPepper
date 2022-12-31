#pragma once

#include "al/Execute/ExecuteDirector.h"

namespace al {

class CollisionDirector : public IUseExecutor {
    void* _4;
    int _8;
    int _C;
    void* _10;
    void* _14;
    void* _18;

public:
    CollisionDirector();

    virtual void execute();

    void endInit();
};

} // namespace al
