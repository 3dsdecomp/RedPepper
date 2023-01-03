#pragma once

struct PlayerModelInfo {
    const char** modelArcs;

    const char* getModelArchive(int index) const { return modelArcs[index]; }
};

struct PlayerAnimInfo {
    const char** animArcs;

    const char* getAnimArchive(int index) const { return animArcs[index]; }
};

class PlayerActorInitInfo {
    const PlayerModelInfo* mModelInfo;
    const PlayerAnimInfo* mAnimInfo;
    void* _8;

public:
    PlayerActorInitInfo();
};
