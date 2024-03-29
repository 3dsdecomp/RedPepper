#include "al/Scene/Scene.h"
#include "Game/Scene/SceneObjFactory.h"
#include "Game/System/Application.h"
#include "al/Scene/SceneObjHolder.h"

namespace al {

Scene::Scene(const char* name)
    : NerveExecutor(name)
    , mAudioKeeper(nullptr)
    , mLiveActorKit(nullptr)
    , mLayoutKit(nullptr)
    , mSceneObjHolder(nullptr)
    , mActorFactory(nullptr)
    , _20(nullptr)
    , mResourceKeeper(nullptr)
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

NON_MATCHING
void Scene::initAndLoadStageResource(const char* stageName, int scenario, sead::Heap* heap)
{
    mResourceKeeper = new StageResourceKeeper;
    mResourceKeeper->initAndLoadResource(stageName, scenario, heap);
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

void Scene::endInit(const ActorInitInfo& info)
{
    if (mSceneObjHolder)
        mSceneObjHolder->initAfterPlacementSceneObj(info);
}

} // namespace al
