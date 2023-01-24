#include "Game/System/GameSystem.h"
#include "Game/System/Application.h"
#include "Game/System/ApplicationFunction.h"
#include "nn/fs/CTR/MPCore/detail/fs_UserFileSystem.h"
#include <nn/cfg/CTR/cfg_Api.h>
#include <nn/ndm/ndm_Api.h>
#include <sead/heap/seadHeapMgr.h>

GameSystem::GameSystem()
    : NerveExecutor("ゲームシステム")
    , mCurrentSequence(nullptr)
    , _C(nullptr)
    , _10(nullptr)
    , _14(nullptr)
    , _18(nullptr)
    , _1C(nullptr)
    , _20(nullptr)
    , _24(nullptr)
    , _28(nullptr)
    , _2C(nullptr)
    , _30(nullptr)
    , _34(nullptr)
{
}

extern "C" void nnMain()
{
    nn::ndm::SuspendScheduler(true);
    nn::cfg::CTR::Initialize();
    nn::fs::ForceDisableLatencyEmulation();
    ApplicationFunction::initialize();
    Application::createInstance(sead::HeapMgr::getRootHeapNum() != 0 ? sead::HeapMgr::getRootHeap(0) : nullptr);
    Application::instance()->init();
    Application::instance()->run();
}
