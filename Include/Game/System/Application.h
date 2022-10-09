#pragma once

#include "al/Scene/SceneObjHolder.h"
#include "al/System/SystemKit.h"
#include "types.h"
#include <sead/heap/seadDisposer.h>

class Application {
public:
    SEAD_SINGLETON_DISPOSER(Application)

    u8 unk[0x8];
    al::SystemKit* mSystemKit;
    u8 unk2[0x34];
    al::SceneObjHolder* mSceneObjHolder;
    u8 unk3[0xc];

public:
    al::SceneObjHolder* getSceneObjHolder() const { return mSceneObjHolder; }
    void setSceneObjHolder(al::SceneObjHolder* holder) { mSceneObjHolder = holder; }
};

static_assert(sizeof(Application) == 0x60, "");
