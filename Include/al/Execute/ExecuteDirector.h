#pragma once

#include "al/Execute/ExecuteRequestKeeper.h"
#include "al/Execute/ExecuteTableHolderDraw.h"
#include "al/Execute/ExecuteTableHolderUpdate.h"

namespace al {

class IUseExecutor {
public:
    virtual void execute() { }
    virtual void draw() { }
};

class ExecuteDirector {
    std::size_t _0;
    ExecuteTableHolderUpdate* mUpdateTable;
    int mDrawTableAmount;
    ExecuteTableHolderDraw** mDrawTables;
    ExecuteRequestKeeper* mRequestKeeper;
    void* _14;
    void* _18;

public:
    ExecuteDirector(int);

    void init();
    void createExecutorListTable();

    friend class LayoutKit;
};

} // namespace al
