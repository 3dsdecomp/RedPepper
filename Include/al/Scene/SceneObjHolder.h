#pragma once

#include "al/Scene/ISceneObj.h"

namespace al {

class SceneObjHolder {
public:
    typedef ISceneObj* (*CreateFunc)(int id);

    SceneObjHolder(CreateFunc func, int size);
    void setObj(ISceneObj* obj, int id);
    ISceneObj* getObj(int id);
    ISceneObj* create(int id);

private:
    CreateFunc mCreateFunc;
    ISceneObj** mObjs;
    int mSize;
};

SceneObjHolder* getSceneObjHolder();
ISceneObj* createSceneObj(int id);
void setSceneObj(ISceneObj* obj, int id);
ISceneObj* getSceneObj(int id);

} // namespace al
