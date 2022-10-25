#pragma once

namespace al {

class EffectKeeper {
public:
    void deleteAndClearEffectAll();
};

class IUseEffectKeeper {
public:
    virtual EffectKeeper* getEffectKeeper() const = 0;
};

} // namespace al
