#include "al/Scene/SceneObjHolder.h"
#include "Game/System/Application.h"

namespace al {

#pragma no_inline // probably belongs in another file
SceneObjHolder* getSceneObjHolder()
{
    return al::getApplication()->getSceneObjHolder();
}

ISceneObj* SceneObjHolder::getObj(int id)
{
    return mObjs[id];
}

void SceneObjHolder::setObj(ISceneObj* obj, int id)
{
    mObjs[id] = obj;
}

ISceneObj* SceneObjHolder::create(int id)
{
    if (mObjs[id] == nullptr) {
        ISceneObj* newObj = mCreateFunc(id);
        mObjs[id] = newObj;
        newObj->initSceneObj();
    }
    return mObjs[id];
}

ISceneObj* createSceneObj(int id)
{
    return getSceneObjHolder()->create(id);
}

void setSceneObj(ISceneObj* obj, int id)
{
    return getSceneObjHolder()->setObj(obj, id);
}

ISceneObj* getSceneObj(int id)
{
    return getSceneObjHolder()->getObj(id);
}

} // namespace al
