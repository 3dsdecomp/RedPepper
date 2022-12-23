#pragma once

#include "al/Execute/ExecuteDirector.h"
#include "al/LiveActor/LiveActor.h"

namespace al {

void registerExecutorUser(IUseExecutor* p, const char* name);

} // namespace al

namespace alActorSystemFunction {

void removeFromExecutorDraw(al::LiveActor* actor);

} // alActorSystemFunction
