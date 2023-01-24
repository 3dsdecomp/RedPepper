#pragma once

#include "al/Audio/AudioKeeper.h"
#include "al/Factory/ActorFactory.h"
#include "al/Layout/LayoutKit.h"
#include "al/LiveActor/LiveActorKit.h"
#include "al/Nerve/NerveExecutor.h"
#include "al/Scene/SceneObjHolder.h"
#include "al/Stage/StageResourceKeeper.h"

namespace al {

class Scene : public NerveExecutor, public IUseAudioKeeper {
    AudioKeeper* mAudioKeeper;
    LiveActorKit* mLiveActorKit;
    LayoutKit* mLayoutKit;
    SceneObjHolder* mSceneObjHolder;
    ActorFactory* mActorFactory;
    void* _20;
    StageResourceKeeper* mResourceKeeper;
    void* _28;
    void* _2C;

    bool mIsAlive;

public:
    Scene(const char* name);

    virtual void appear();
    virtual void kill();
    virtual void init(/*SceneInitInfo& ?*/) = 0;
    virtual void movement();
    virtual void control();
    virtual void unk1() {}; // drawMain?
    virtual void unk2() {}; // drawSub?
    virtual void unk3() {};
    virtual void unk4() {};
    virtual void unk5() {};
    virtual void unk6() {};
    virtual void unk7() {};
    virtual AudioKeeper* getAudioKeeper() const; // probably not the right location
    virtual void unk8() {};
    virtual void unk9() {}; // does draw/execute stuff
    virtual void unk10() {};

    void initAndLoadStageResource(const char* stageName, int scenario, sead::Heap* heap);
    void initSceneAudio(const char* stageName, int scenario, int, const sead::SafeString&, const char* userName);
    void initCameraDirector();
    void initActorFactory();
    void initSceneObjHolder();
    void initLiveActorKit();
    void initLayoutKit();

    void endInit(const ActorInitInfo& info);

    bool isAlive() const { return mIsAlive; }
    ActorFactory* getActorFactory() const { return mActorFactory; }
};

static_assert(sizeof(Scene) == 0x34, "");

} // namespace al
