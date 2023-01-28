#pragma once

namespace al {

struct LiveActorFlag {
    bool isDead;
    bool isClipped;
    bool isInvalidClipping;
    bool isDrawClipping;
    bool flag5;
    bool isHideModel;
    bool isOffCollide;
    bool flag8;
    bool isValidMaterialCode;

    LiveActorFlag();
};

} // namespace al
