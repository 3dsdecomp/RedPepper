#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

class NerveKeeper;

struct Nerve {
    virtual void execute(NerveKeeper* nerveKeeper) const = 0;
    virtual void executeOnEnd(NerveKeeper* nerveKeeper) const {};
};

} // namespace al
