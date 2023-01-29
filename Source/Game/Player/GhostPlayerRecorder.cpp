#include "Game/Player/GhostPlayerRecorder.h"

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
