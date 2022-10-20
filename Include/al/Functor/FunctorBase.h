#pragma once

namespace al {

class FunctorBase {
public:
    virtual void operator()() const = 0;
    virtual FunctorBase* clone() const = 0;
};

} // namespace al
