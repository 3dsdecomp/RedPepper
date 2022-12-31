#include "al/Execute/ExecuteDirector.h"
#include "al/Execute/ExecuteRequestKeeper.h"
#include "al/Execute/ExecuteTableHolderDraw.h"
#include "al/Execute/ExecuteTableHolderUpdate.h"
#include "types.h"

namespace al {

#pragma O3
ExecuteDirector::ExecuteDirector(int p)
    : _0(p)
    , mUpdateTable(nullptr)
    , mDrawTableAmount(0)
    , mDrawTables(nullptr)
    , mRequestKeeper(nullptr)
    , _14(0)
    , _18(0)
{
}

static const ExecuteOrder split(sUpdateExecuteOrder) = { "�N���b�s���O", "Execute", 1, "�V�X�e��" };

static const ExecuteOrder split(sDraw0ExecuteOrder) = { "��", "ActorModelDraw", 8, "�n�`" };
static const ExecuteOrder split(sDraw1ExecuteOrder) = { "�Q�c�G���h���[���e�L�X�g", "LayoutDraw", 64, "���C�A�E�g" };
static const ExecuteOrder split(sDraw2ExecuteOrder) = { "�Œ�n�`", "ActorModelDrawModelCache", 32, "�n�`" };
static const ExecuteOrder split(sDraw3ExecuteOrder) = { "�R���W�����n�`", "ActorModelDraw", 128, "�n�`" };
static const ExecuteOrder split(sDraw4ExecuteOrder) = { "�Q�c�A�C�R��", "LayoutDraw", 128, "���C�A�E�g" };
static const ExecuteOrder split(sDraw5ExecuteOrder) = { "�Q�c�x�[�X", "LayoutDraw", 128, "���C�A�E�g" };
static const ExecuteOrder split(sDraw6ExecuteOrder) = { "�Q�c�|�[�Y", "LayoutDraw", 8, "���C�A�E�g" };
static const ExecuteOrder split(sDraw7ExecuteOrder) = { "�Q�c�x�[�X�i����ʁj", "LayoutDrawBottom", 8, "���C�A�E�g" };
static const ExecuteOrder split(sDraw8ExecuteOrder) = { "�A�C�e���X�g�b�N���f��", "ActorModelDraw", 32, "�A�C�e��" };
static const ExecuteOrder split(sDraw9ExecuteOrder) = { "�Q�c�|�[�Y�i����ʁj", "LayoutDrawBottom", 8, "���C�A�E�g" };

NON_MATCHING
// small instruction swap in operator new[]
void ExecuteDirector::init()
{
    mUpdateTable = new ExecuteTableHolderUpdate;
    mUpdateTable->init(&sUpdateExecuteOrder, 58);
    mDrawTableAmount = 10;
    mDrawTables = new ExecuteTableHolderDraw*[10];

    for (int i = 0; i < mDrawTableAmount; i++) {
        ExecuteTableHolderDraw* newDrawTable = new ExecuteTableHolderDraw;
        mDrawTables[i] = newDrawTable;
        if (_14)
            newDrawTable->_48 = _14;
        if (_18)
            newDrawTable->_4C = _18;
    }

    mDrawTables[0]->init("�R�c�i��j", &sDraw0ExecuteOrder, 4);
    mDrawTables[1]->init("�Q�c�G���h���[���e�L�X�g�i���ʁj", &sDraw1ExecuteOrder, 1);
    mDrawTables[2]->init("�R�c�i�Œ�n�`�j", &sDraw2ExecuteOrder, 2);
    mDrawTables[3]->init("�R�c�i���ʁj", &sDraw3ExecuteOrder, 32);
    mDrawTables[4]->init("�Q�c�A�C�R���i���ʁj", &sDraw4ExecuteOrder, 1);
    mDrawTables[5]->init("�Q�c�x�[�X�i���ʁj", &sDraw5ExecuteOrder, 5);
    mDrawTables[6]->init("�Q�c�i���ʁj", &sDraw6ExecuteOrder, 10);
    mDrawTables[7]->init("�Q�c�x�[�X�i����ʁj", &sDraw7ExecuteOrder, 2);
    mDrawTables[8]->init("�R�c�i�A�C�e���X�g�b�N�j", &sDraw8ExecuteOrder, 1);
    mDrawTables[9]->init("�Q�c�i����ʁj", &sDraw9ExecuteOrder, 9);

    mRequestKeeper = new ExecuteRequestKeeper(_0);
}

void ExecuteDirector::createExecutorListTable()
{
    mUpdateTable->createExecutorListTable();
    for (int i = 0; i < mDrawTableAmount; i++)
        mDrawTables[i]->createExecutorListTable();
}

} // namespace al
