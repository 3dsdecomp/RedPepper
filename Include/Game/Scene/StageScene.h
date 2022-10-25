#pragma once

#include "Game/Player/PlayerActor.h"
#include "Game/Sequence/ProductStageStartParam.h"
#include "al/Scene/Scene.h"

class StageScene : public al::Scene {
    ProductStageStartParam* mStageStartParam;
    PlayerActor* mPlayerActor;
    void* _3C;
    void* _40;
    void* _44;
    void* _48;
    void* _4C;
    void* _50;
    void* _54;
    void* _58;
    void* _5C;
    class StageSceneStateGameOver* mStateGameOver;
    void* _64;
    void* _68;
    void* _6C;
    void* _70;
    void* _74;
    void* _78;
    void* _7C;
    void* _80;
    void* _84;
    void* _88;
    void* _8C;
    void* _90;
    void* _94;
    void* _98;

public:
    StageScene(ProductStageStartParam* stageStartParam);

    virtual void appear();
    virtual void control();
};
