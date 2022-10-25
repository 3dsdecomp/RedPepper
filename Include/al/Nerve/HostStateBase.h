#pragma once

#include "al/Nerve/NerveStateBase.h"

namespace al {

template <typename T>
class HostStateBase : public NerveStateBase {
protected:
    T* const mHost;

public:
    HostStateBase(T* host, const char* name)
        : NerveStateBase(name)
        , mHost(host)
    {
    }
};

} // namespace al
