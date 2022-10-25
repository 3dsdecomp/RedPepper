#pragma once

#include "al/Layout/LayoutActor.h"

class WindowConfirmSingle : public al::LayoutActor {
    void* _30;

public:
    WindowConfirmSingle(const char* name, const al::LayoutInitInfo& info);
    virtual void appear();
};
