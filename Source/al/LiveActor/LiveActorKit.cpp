#include "al/LiveActor/LiveActorKit.h"
#include "Game/System/Application.h"

namespace al {

LiveActorKit* getLiveActorKit()
{
    return Application::instance()->mLiveActorKit;
}

} // namespace al
