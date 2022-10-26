#pragma once

#include "al/Layout/LayoutActor.h"

class WindowConfirmButton : public al::LayoutActor {
    void* _30;

public:
    WindowConfirmButton(const char* name, const al::LayoutInitInfo& info);
    virtual void appear();
};
