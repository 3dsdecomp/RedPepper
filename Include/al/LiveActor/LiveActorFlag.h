#pragma once

namespace al {

class LiveActor;
struct LiveActorFlag {
    bool isDead;
    bool isClipped;
    bool isInvalidClipping;
    bool flag4;
    bool flag5;
    bool isHideModel;
    bool isOffCollide;
    bool flag8;
    bool isValidMaterialCode;

    LiveActorFlag();
};

} // namespace al
