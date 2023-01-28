#pragma once

#include "al/Execute/ExecuteRequestKeeper.h"

namespace al {

class ActorExecuteInfo {
    ExecuteRequestKeeper* mRequestKeeper;

public:
    ExecuteRequestKeeper* getRequestKeeper() const { return mRequestKeeper; }
};

} // namespace al
