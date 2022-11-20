#pragma once

#include "al/Scene/ISceneObj.h"

namespace al {

class SceneObjHolder {
    typedef ISceneObj* (*CreateFunc)(int id);

    CreateFunc mCreateFunc;
    ISceneObj** mObjs;
    int mSize;

public:
    SceneObjHolder(CreateFunc func, int size);

    void setObj(ISceneObj* obj, int id);
    ISceneObj* getObj(int id);
    ISceneObj* create(int id);

    void initAfterPlacementSceneObj(const ActorInitInfo& info);
};

SceneObjHolder* getSceneObjHolder();
ISceneObj* createSceneObj(int id);
void setSceneObj(ISceneObj* obj, int id);
ISceneObj* getSceneObj(int id);

} // namespace al
