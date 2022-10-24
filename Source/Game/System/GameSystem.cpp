#include "Game/System/Application.h"
#include "Game/System/ApplicationFunction.h"
#include <nn/cfg/CTR/cfg.h>
#include <sead/heap/seadHeapMgr.h>

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
    Application::instanceInline()->init();
    Application::instanceInline()->run();
}