#include "al/Scene/Scene.h"
#include "Game/Scene/SceneObjFactory.h"
#include "Game/System/Application.h"
#include "al/Scene/SceneObjHolder.h"

namespace al {

#ifdef NON_MATCHING
Scene::Scene(const char* name)
    : NerveExecutor()
    , mAudioKeeper(nullptr)
    , mLiveActorKit(nullptr)
    , mLayoutKit(nullptr)
    , mSceneObjHolder(nullptr)
    , mCCNTHolder(nullptr)
    , _20(nullptr)
    , _24(nullptr)
    , _28(nullptr)
    , _2C(nullptr)
    , mIsAlive(false)
{
}
#endif

void Scene::appear()
{
    if (!mIsAlive)
        mIsAlive = true;
}

void Scene::kill()
{
    mIsAlive = false;
}

#ifdef NON_MATCHING
void Scene::movement()
{
    if (mIsAlive) {
        updateNerve();
        control();
        if (mAudioKeeper)
            mAudioKeeper->update();
    }
}
#endif

void Scene::control()
{
}

#ifdef NON_MATCHING
void Scene::initSceneObjHolder()
{
    SceneObjHolder* holder = SceneObjFactory::createSceneObjHolder();
    mSceneObjHolder = holder;
    Application::instance()->setSceneObjHolder(holder);
}
#endif

} // namespace al
