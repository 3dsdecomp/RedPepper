#pragma once

#include "al/Functor/FunctorBase.h"
#include <sead/heap/seadHeap.h>

namespace al {

void createAndStartInitializeThread(sead::Heap* heap, int stackSize, const FunctorBase& func);

} // namespace al
