#include "Game/Sequence/ProductStateTitle.h"
#include "al/Nerve/Nerve.h"

namespace NrvProductStateTitle {

NERVE_DEF(ProductStateTitle, Load)

} // namespace NrvProductStateTitle

ProductStateTitle::ProductStateTitle(ProductSequence* host, ProductStageStartParam* startParam, const al::LayoutInitInfo& info)
    : HostStateBase(host, "製品シーケンスのタイトルステート")
    , mStartParam(startParam)
    , _1C(nullptr)
    , _20(nullptr)
    , _24(true)
    , _25(false)
{
    mButton = new WindowConfirmButton("確認ウインドウ", info);
    mWindow = new WindowConfirmSingle("確認ウインドウ[ボタン1個]", info);
}

void ProductStateTitle::init()
{
    initNerve(&NrvProductStateTitle::Load);
}
