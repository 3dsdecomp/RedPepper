#pragma once

#include <cstddef>

namespace al {

class LiveActor;
class ExecuteRequestKeeper {
public:
    ExecuteRequestKeeper(std::size_t);

    void request(LiveActor*, int);
};

} // namespace al
