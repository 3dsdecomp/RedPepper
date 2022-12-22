#include "Game/System/GameSystem.h"
#include "Game/System/Application.h"
#include "Game/System/ApplicationFunction.h"
#include <nn/cfg/CTR/cfg_Api.h>
#include <sead/heap/seadHeapMgr.h>

#pragma O3
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

extern "C" void FUN_00101414(int);
extern "C" void FUN_0010073c();

#pragma O3
extern "C" void nnMain()
{
    FUN_00101414(1);
    nn::cfg::CTR::Initialize();
    FUN_0010073c();
    ApplicationFunction::initialize();
    Application::createInstance(sead::HeapMgr::getRootHeapNum() != 0 ? sead::HeapMgr::getRootHeap(0) : nullptr);
    Application::instance()->init();
    Application::instance()->run();
}
