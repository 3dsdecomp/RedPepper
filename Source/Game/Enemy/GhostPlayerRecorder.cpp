#include "Game/Enemy/GhostPlayerRecorder.h"

#pragma O3
GhostPlayerRecorder::GhostPlayerRecorder()
    : mFrames(nullptr)
    , mGhostPlayer(nullptr)
    , mNumFrames(0)
    , mCurrentFrame(0)
    , _14(0)
    , _18(0)
    , _1C(true)
    , _1D(true)
{
}

#pragma O3
void GhostPlayerRecorder::create(int numFrames)
{
    if (mFrames)
        delete[] mFrames;
    mFrames = new Frame[numFrames];
    mCurrentFrame = 0;
    _1C = 1;
    mNumFrames = numFrames;
}

NON_MATCHING
void GhostPlayerRecorder::initSceneObj() { }
