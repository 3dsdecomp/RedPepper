#pragma once

#include "Game/Enemy/GhostPlayer.h"
#include "al/Scene/ISceneObj.h"

class GhostPlayerRecorder : public al::ISceneObj {
    struct Frame {
        sead::Vector3f mTrans;
        sead::Vector3f mRotate;
        int _18;
        const char* mActionName;
        int _20;
    };

    Frame* mFrames;
    GhostPlayer* mGhostPlayer;
    int mNumFrames;
    int mCurrentFrame;
    int _14;
    int _18;
    bool _1C;
    bool _1D;

public:
    GhostPlayerRecorder();

    void create(int numFrames);

    virtual const char* getSceneObjName() const { return "ゴーストプレイヤー記録"; }
    virtual void initSceneObj();

    void initGhostPlayer(GhostPlayer* player) { mGhostPlayer = player; }

    friend class GhostPlayer;
};
