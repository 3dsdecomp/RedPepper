#pragma once

#include "Game/Layout/WindowConfirmButton.h"
#include "Game/Layout/WindowConfirmSingle.h"
#include "Game/Sequence/ProductStageStartParam.h"
#include "Game/Sequence/ProductStateStage.h"
#include "al/Layout/LayoutInitInfo.h"
#include "al/Nerve/HostStateBase.h"

class ProductStateTitle : public al::HostStateBase<ProductSequence> {
    ProductStageStartParam* mStartParam;
    WindowConfirmButton* mButton;
    WindowConfirmSingle* mWindow;
    void* _1C;
    void* _20;
    bool _24;
    bool _25;

public:
    ProductStateTitle(ProductSequence* host, ProductStageStartParam* startParam, const al::LayoutInitInfo& info);

    virtual void init();

    void exeLoad();
};
