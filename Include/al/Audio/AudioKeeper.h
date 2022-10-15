#pragma once

namespace al {

class AudioKeeper {
public:
    void update();
};

class IUseAudioKeeper {
public:
    virtual AudioKeeper* getAudioKeeper() const = 0;
};

} // namespace al
