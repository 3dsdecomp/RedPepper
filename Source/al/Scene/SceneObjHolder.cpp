#include "al/Scene/SceneObjHolder.h"
#include "Game/System/Application.h"

namespace al {

#ifdef NON_MATCHING
SceneObjHolder* getSceneObjHolder()
{
#pragma no_inline
    return Application::instance()->getSceneObjHolder();
}
#endif

void* SceneObjHolder::getObj(int id)
{
    return mObjs[id];
}

#ifdef NON_MATCHING
void SceneObjHolder::setObj(void* obj, int id)
{
    mObjs[id] = obj;
}

void* getSceneObj(int id)
{
    return getSceneObjHolder()->getObj(id);
}

void setSceneObj(void* obj, int id)
{
    return getSceneObjHolder()->setObj(obj, id);
}
#endif

} // namespace al
