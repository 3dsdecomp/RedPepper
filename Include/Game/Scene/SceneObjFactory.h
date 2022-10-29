#pragma once

#include "al/Scene/SceneObjHolder.h"

namespace SceneObjFactory {

al::SceneObjHolder* createSceneObjHolder();

} // namespace SceneObjFactory

enum SceneObjType {
    SceneObjType_CoinRotater = 7
};
