#pragma once

#include "al/Scene/SceneObjHolder.h"

namespace SceneObjFactory {

al::SceneObjHolder* createSceneObjHolder();

} // namespace SceneObjFactory

enum SceneObjType {
    SceneObjType_SwitchAreaDirector = 3,
    SceneObjType_AudioDirector = 4, // not sure
    SceneObjType_CoinRotater = 7,
    SceneObjType_CoinCollectInfoKeeper = 9, // not sure
    SceneObjType_ItemHolder = 10,
    SceneObjType_GhostPlayerRecorder = 20
};
