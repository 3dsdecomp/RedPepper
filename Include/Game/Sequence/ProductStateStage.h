#pragma once

#include "Game/Scene/StageScene.h"
#include "Game/Sequence/ProductStageStartParam.h"
#include "al/Layout/LayoutInitInfo.h"
#include "al/Nerve/HostStateBase.h"

class ProductSequence;
class ProductStateStage : public al::HostStateBase<ProductSequence> {
    ProductStageStartParam* mStageStartParam;
    ProductStageStartParam* mLastStageStartParam;
    StageScene* mStageScene;
    void* _1C;
    void* _20;
    void* _24;
    void* _28;
    void* _2C;
    void* _30;
    void* _34;
    void* _38;

public:
    ProductStateStage(ProductSequence* parent, ProductStageStartParam* startParam, const al::LayoutInitInfo& info);
    /*virtual void init();
    virtual void appear();*/
};
