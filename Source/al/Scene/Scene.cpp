#include "al/Scene/Scene.h"
#include "Game/Scene/SceneObjFactory.h"
#include "Game/System/Application.h"
#include "al/Scene/SceneObjHolder.h"

namespace al {

#pragma O3
Scene::Scene(const char* name)
    : NerveExecutor(name)
    , mAudioKeeper(nullptr)
    , mLiveActorKit(nullptr)
    , mLayoutKit(nullptr)
    , mSceneObjHolder(nullptr)
    , mActorFactory(nullptr)
    , _20(nullptr)
    , _24(nullptr)
    , _28(nullptr)
    , _2C(nullptr)
    , mIsAlive(false)
{
}

void Scene::appear()
{
    if (!mIsAlive)
        mIsAlive = true;
}

void Scene::kill()
{
    mIsAlive = false;
}

NON_MATCHING
void Scene::movement()
{
    if (mIsAlive) {
        updateNerve();
        control();
        if (mAudioKeeper)
            mAudioKeeper->update();
    }
}

void Scene::control()
{
}

AudioKeeper* Scene::getAudioKeeper() const
{
    return mAudioKeeper;
}

void Scene::initActorFactory()
{
    mActorFactory = new ActorFactory();
}

void Scene::initSceneObjHolder()
{
    SceneObjHolder* holder = SceneObjFactory::createSceneObjHolder();
    mSceneObjHolder = holder;
    Application::instance()->setSceneObjHolder(holder);
}

} // namespace al
