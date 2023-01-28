#include "al/Execute/ExecuteTableHolder.h"
#include "al/LiveActor/LiveActorKit.h"

namespace al {
void registerExecutorUser(IUseExecutor* p, const char* name)
{
    al::getLiveActorKit()->getExecuteDirector()->registerUser(p, name);
}

void registerExecutorFunctor(const FunctorBase& base, const char* name)
{
    al::getLiveActorKit()->getExecuteDirector()->registerFunctor(base, name);
}

void registerExecutorFunctorDraw(const FunctorBase& base, const char* name)
{
    al::getLiveActorKit()->getExecuteDirector()->registerFunctorDraw(base, name);
}

} // namespace al

namespace alActorSystemFunction {

void addToExecutorMovement(al::LiveActor* actor)
{
    actor->getActorExecuteInfo()->getRequestKeeper()->request(actor, 0);
}

} // namespace alActorSystemFunction
