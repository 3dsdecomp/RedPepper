#pragma once

#include "al/LiveActor/LiveActorGroup.h"
#include "al/MapObj/MapObjActor.h"

class NoteObjGenerator : public al::MapObjActor {
    al::LiveActorGroup* mNoteObjGroup;
    void* _64;
    float _68;
    float _6C;
    void* _70;
    int _74;
    bool _78;
    float _7C;
    void* _80;
    bool _84;

public:
    NoteObjGenerator(const sead::SafeString& name);

    void exeWait();
    void exeMove();
    void exeDisappear();
    void exeSuccess();
};
