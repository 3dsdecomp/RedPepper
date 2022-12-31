#pragma once

#include "al/Execute/ExecuteOrder.h"

namespace al {

class ExecuteTableHolderDraw {
    int _0;
    int _4;
    int _8;
    int _C;
    int _10;
    int _14;
    int _18;
    int _1C;
    int _20;
    int _24;
    int _28;
    int _2C;
    int _30;
    int _34;
    int _38;
    int _3C;
    int _40;
    int _44;
    void* _48;
    void* _4C;

public:
    ExecuteTableHolderDraw();

    void init(const char*, const ExecuteOrder* order, int);
    void createExecutorListTable();

    friend class ExecuteDirector;
};

} // namespace al
