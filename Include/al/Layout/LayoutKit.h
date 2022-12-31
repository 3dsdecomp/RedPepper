#pragma once

#include "al/Execute/ExecuteDirector.h"

namespace al {

class LayoutKit {
    void* _0;
    class FontHolder* mFontHolder;
    ExecuteDirector* mExecuteDirector;
    void* _C;
    void* _10;
    void* _14;

public:
    LayoutKit(FontHolder* fontHolder);

    void createExecuteDirector(int p);
};

} // namespace al
