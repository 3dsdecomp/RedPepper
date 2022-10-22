#pragma once

#include "al/Audio/AudioKeeper.h"
#include "al/Nerve/NerveExecutor.h"
#include "al/Scene/CreatorClassNameTableHolder.h"

namespace al {

class Scene : public NerveExecutor, IUseAudioKeeper {
    AudioKeeper* mAudioKeeper;
    class LiveActorKit* mLiveActorKit;
    class LayoutKit* mLayoutKit;
    class SceneObjHolder* mSceneObjHolder;
    CreatorClassNameTableHolder* mCCNTHolder;
    void* _20;
    void* _24;
    void* _28;
    void* _2C;

    bool mIsAlive;

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

    void initCreatorClassNameTableHolder();
    void initSceneObjHolder();
    // void initPlacement(al::Resource* stageFile, const ActorInitInfo& info, const char* infoIterName);
};

static_assert(sizeof(Scene) == 0x34, "");

} // namespace al
