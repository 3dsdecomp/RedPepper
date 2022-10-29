#pragma once

#include "al/LiveActor/LiveActor.h"
#include "al/Scene/ISceneObj.h"

class CoinRotater : public al::LiveActor, public al::ISceneObj {
    float mRotateY;
    u8 _68[0x64];

public:
    CoinRotater();

    virtual const char* getSceneObjName() const;
    virtual void initAfterPlacementSceneObj(const al::ActorInitInfo& info);

    float getRotateY() { return mRotateY; }

    virtual void movement();
};

namespace rp {

void createCoinRotater();
float getCoinRotateY();

} // namespace rp
