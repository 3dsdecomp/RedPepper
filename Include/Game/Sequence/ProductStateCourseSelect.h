#pragma once

#include "Game/Sequence/ProductStageStartParam.h"
#include "Game/Sequence/ProductStateStage.h"
#include "al/Layout/LayoutInitInfo.h"
#include "al/Nerve/HostStateBase.h"

class ProductStateCourseSelect : public al::HostStateBase<ProductSequence> {
    int _10;
    ProductStageStartParam* mStartParam;
    void* _18;
    void* _1C;
    void* _20;
    void* _24;
    void* _28;
    void* _2C;
    void* _30;
    void* _34;
    void* _38;
    void* _3C;

public:
    ProductStateCourseSelect(ProductSequence* host, ProductStageStartParam* startParam, const al::LayoutInitInfo& info);

    void set_10(int v) { _10 = v; }
};
