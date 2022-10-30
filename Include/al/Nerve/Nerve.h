#pragma once

#include "al/Nerve/NerveKeeper.h"

namespace al {

class NerveKeeper;

struct Nerve {
    virtual void execute(NerveKeeper* nerveKeeper) const = 0;
    virtual void executeOnEnd(NerveKeeper* nerveKeeper) const {};
};

#define NERVE_DEF(CLASS, ACTION)                                   \
    struct CLASS##Nrv##ACTION : public ::al::Nerve {               \
        virtual void execute(::al::NerveKeeper* keeper) const      \
        {                                                          \
            static_cast<CLASS*>(keeper->getHost())->exe##ACTION(); \
        }                                                          \
    };                                                             \
    const split(CLASS##Nrv##ACTION) ACTION = CLASS##Nrv##ACTION();

#define NERVE_DEF_END(CLASS, ACTION, ENDACTION)                       \
    struct CLASS##Nrv##ACTION : public ::al::Nerve {                  \
        virtual void execute(::al::NerveKeeper* keeper) const         \
        {                                                             \
            static_cast<CLASS*>(keeper->getHost())->exe##ACTION();    \
        }                                                             \
        virtual void executeOnEnd(::al::NerveKeeper* keeper) const    \
        {                                                             \
            static_cast<CLASS*>(keeper->getHost())->exe##ENDACTION(); \
        }                                                             \
    };                                                                \
    const split(CLASS##Nrv##ACTION) ACTION = CLASS##Nrv##ACTION();

} // namespace al
