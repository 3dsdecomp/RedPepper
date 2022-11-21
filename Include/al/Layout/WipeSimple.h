#pragma once

#include "al/Layout/LayoutActor.h"

namespace al {

class WipeSimple : public al::LayoutActor {
    int _30;

public:
    WipeSimple(const char* name, const char* archive, const LayoutInitInfo& info, const char* suffix = nullptr);

    virtual void appear();

    void exeClose();
    void exeWait();
    void exeOpen();
};

} // namespace al
