#include "Game/Sequence/ProductStateStage.h"
#include "Game/Sequence/ProductStageStartParam.h"

class KoopaLastStageStartParam : public ProductStageStartParam {
public:
    virtual const char* getStageDataName() { return "KoopaLastStage"; }
};

NON_MATCHING
ProductStateStage::ProductStateStage(ProductSequence* parent, ProductStageStartParam* startParam, const al::LayoutInitInfo& info)
    : HostStateBase(parent, "ステージステート")
    , mStageStartParam(startParam)
    , mLastStageStartParam(nullptr)
    , mStageScene(nullptr)
    , _1C(nullptr)
    , _20(nullptr)
    , _24(nullptr)
    , _28(nullptr)
    , _2C(nullptr)
    , _30(nullptr)
    , _34(nullptr)
    , _38(nullptr)
{
    mLastStageStartParam = new KoopaLastStageStartParam();
}

/*void ProductStateStage::init() { }
void ProductStateStage::appear() { }*/
