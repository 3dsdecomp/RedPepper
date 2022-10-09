#pragma once

namespace al {

class SceneObjHolder {
public:
    typedef void* (*CreateFunction)(int id);

    SceneObjHolder(CreateFunction func, int size);
    void setObj(void* obj, int id);
    void* getObj(int id);

private:
    CreateFunction mCreateFunction;
    void** mObjs;
    int mSize;
};

SceneObjHolder* getSceneObjHolder();
void* getSceneObj(int id);
void setSceneObj(void* obj, int id);

} // namespace al
