#include "al/Scene/SceneObjHolder.h"
#include "Game/System/Application.h"

namespace al {

SceneObjHolder* getSceneObjHolder()
{
#pragma no_inline
    return al::getApplication()->getSceneObjHolder();
}

void* SceneObjHolder::getObj(int id)
{
    return mObjs[id];
}

#ifdef NON_MATCHING
void SceneObjHolder::setObj(void* obj, int id)
{
    mObjs[id] = obj;
}
#endif

void* getSceneObj(int id)
{
    return getSceneObjHolder()->getObj(id);
}

void setSceneObj(void* obj, int id)
{
    return getSceneObjHolder()->setObj(obj, id);
}

} // namespace al
