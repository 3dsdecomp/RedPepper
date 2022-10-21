#pragma once

namespace al {

class AudioKeeper {
public:
    void update();
};

class IUseAudioKeeper {
    virtual void v1();
    virtual void v2();

public:
    virtual AudioKeeper* getAudioKeeper() const = 0;

private:
    virtual void v4();
    virtual void v5();
};

} // namespace al
