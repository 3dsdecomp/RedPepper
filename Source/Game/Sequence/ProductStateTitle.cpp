#include "Game/Sequence/ProductStateTitle.h"
#include "al/Nerve/Nerve.h"

namespace NrvProductStateTitle {

NERVE_DEF(ProductStateTitle, Load)

} // namespace NrvProductStateTitle

ProductStateTitle::ProductStateTitle(ProductSequence* host, ProductStageStartParam* startParam, const al::LayoutInitInfo& info)
    : HostStateBase(host, "���i�V�[�P���X�̃^�C�g���X�e�[�g")
    , mStartParam(startParam)
    , _1C(nullptr)
    , _20(nullptr)
    , _24(true)
    , _25(false)
{
    mButton = new WindowConfirmButton("�m�F�E�C���h�E", info);
    mWindow = new WindowConfirmSingle("�m�F�E�C���h�E[�{�^��1��]", info);
}

void ProductStateTitle::init()
{
    initNerve(&NrvProductStateTitle::Load);
}
