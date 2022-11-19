#pragma once

#include <sead/math/seadVector.h>

namespace al {

class EffectKeeper {
public:
    void update();
    void deleteAndClearEffectAll();
};

class IUseEffectKeeper {
public:
    virtual EffectKeeper* getEffectKeeper() const = 0;
};

void emitEffect(IUseEffectKeeper* p, const char* name, const sead::Vector3f* at = nullptr);
bool tryEmitEffect(IUseEffectKeeper* p, const char* name);

} // namespace al
